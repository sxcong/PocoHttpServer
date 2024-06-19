#include "pch.h"
#include <iostream>

#include "MainApp.h"
#include "CommonRequestHandler.h"
#include "BusinessRequestHandler.h"
#include "FileUploadHandler.h"
#include "CGIRequestHandler.h"
#include "HttpUtils.h"

class MainRequestHandlerFactory : public HTTPRequestHandlerFactory
{
public:
	MainRequestHandlerFactory()
	{

	}
	virtual ~MainRequestHandlerFactory()
	{

	}

	HTTPRequestHandler* createRequestHandler(const HTTPServerRequest& request)
	{

		NameValueCollection::ConstIterator it = request.begin();
		NameValueCollection::ConstIterator end = request.end();
		for (; it != end; ++it)
		{
		   // qDebug() << it->first.c_str() << ": " << it->second.c_str();
		}

		/*   URI uri(request.getURI());

			 qDebug()<<"uri.getPath()"<<uri.getPath().c_str();
			 qDebug()<<"uri.getRawQuery()"<<uri.getRawQuery().c_str();
			 qDebug()<<"uri.getHost()"<<uri.getHost().c_str();
			 qDebug()<<"uri.getUserInfo()"<<uri.getUserInfo().c_str();
			 qDebug()<<"uri.getScheme()"<<uri.getScheme().c_str();
			 qDebug()<<"uri.getRawFragment()"<<uri.getRawFragment().c_str();
			 qDebug()<<"uri.getSpecifiedPort()"<<uri.getSpecifiedPort();
	 */
		std::cout << "request.getURI()" << request.getURI().c_str() << request.getMethod().c_str()<<std::endl;

		static std::string szStatic = "/assets/";
		static std::string szCgi = "/cgi/";
		static std::string szIndex = "/index.html";
		static std::string szIco = "/favicon.ico";

		URI uri(request.getURI());
		std::string reqString = uri.getPath();

		//static resource
		if (uri.getPath() == "/")
		{
			return new StaticRequestHandler();
		}
		if (uri.getPath() == szIndex)
		{
			return new StaticRequestHandler();
		}
		if (uri.getPath() == szIco)
		{
			return new StaticRequestHandler();
		}
		if (reqString.size() > 8)
		{
			if (reqString.substr(0, 8) == szStatic)
			{
				return new StaticRequestHandler();
			}
		}

		if (reqString.size() > 5)
		{
			if (reqString.substr(0, 5) == szCgi)
			{
				return new CGIRequestHandler();
			}
		}


		//for test rest api

		if (uri.getPath() == "/api/user/login")
		{
			return new LoginRequestHandler();
		}

		if (uri.getPath() == "/login")
		{
			return new StaticRequestHandler();
		}
		else if (uri.getPath() == "/upload-api2/upload")
		{
			return new FileUploadHandler();
		}
		else if (uri.getPath() == "/api/setLanConfig")
		{
			return new SetLanConfigRequestHandler();
		}
		else if (uri.getPath() == "/api/getLanConfig")
		{
			return new GetLanConfigRequestHandler();
		}

		// test token
		std::string field = request.get("token", "");

		if (field.empty())
		{
			//return new NotTokenRequestHandler();
			return new StaticRequestHandler();
		}
		return new NotFoudRequestHandler();
	}
};


MainApp::MainApp() : _helpRequested(false)
{
}


MainApp::~MainApp()
{
}




void MainApp::initialize(Application& self)
{
	loadConfiguration(); // load default configuration files, if present
	ServerApplication::initialize(self);
}

void MainApp::uninitialize()
{
	ServerApplication::uninitialize();
}

void MainApp::defineOptions(OptionSet& options)
{
	ServerApplication::defineOptions(options);

	options.addOption(
		Option("help", "h", "display help information on command line arguments")
		.required(false)
		.repeatable(false));
}

void MainApp::handleOption(const std::string& name, const std::string& value)
{
	ServerApplication::handleOption(name, value);

	if (name == "help")
		_helpRequested = true;
}

void MainApp::displayHelp()
{
	HelpFormatter helpFormatter(options());
	helpFormatter.setCommand(commandName());
	helpFormatter.setUsage("OPTIONS");
	helpFormatter.setHeader("A web server that serves the current date and time.");
	helpFormatter.format(std::cout);
}


int MainApp::main(const std::vector<std::string>& args)
{
	//HttpUtils::Instance().setCommandPath(this->commandPath());
	Path appPath(this->commandPath());
	
	HttpUtils::Instance().setCommandPath(appPath.parent().toString());
	if (_helpRequested)
	{
		displayHelp();
	}
	else
	{
		// get parameters from configuration file
		unsigned short port = (unsigned short)config().getInt("HTTPTimeServer.port", 8089);
		std::string format(config().getString("HTTPTimeServer.format", DateTimeFormat::SORTABLE_FORMAT));
		int maxQueued = config().getInt("HTTPTimeServer.maxQueued", 100);
		int maxThreads = config().getInt("HTTPTimeServer.maxThreads", 16);

		ThreadPool::defaultPool().addCapacity(maxThreads);

		HTTPServerParams* pParams = new HTTPServerParams;
		pParams->setMaxQueued(maxQueued);
		pParams->setMaxThreads(maxThreads);

		// set-up a server socket
		//ServerSocket svs(port);
		// set-up a HTTPServer instance
		HTTPServer srv(new MainRequestHandlerFactory(), port, pParams);
		// start the HTTPServer
		srv.start();
		// wait for CTRL-C or kill
		waitForTerminationRequest();
		// Stop the HTTPServer
		srv.stop();
	}
	return Application::EXIT_OK;
}

