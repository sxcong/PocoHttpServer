#include "pch.h"
#include "CGIRequestHandler.h"

#include "Poco/Process.h"
#include "Poco/Pipe.h"
#include "Poco/PipeStream.h"
#include "Poco/Path.h"
#include "Poco/Format.h"


using namespace std::string_literals;
using Poco::Process;
using Poco::ProcessHandle;
using Poco::Pipe;
using Poco::Path;
using Poco::PipeInputStream;
using Poco::PipeOutputStream;

using namespace Poco::JSON;
using namespace Poco::Dynamic;

#include "HttpUtils.h"


CGIRequestHandler::CGIRequestHandler()
{
}


CGIRequestHandler::~CGIRequestHandler()
{
}

void CGIRequestHandler::handleRequest(HTTPServerRequest& request, HTTPServerResponse& response)
{
	URI uri(request.getURI());
	static std::string szCgi = uri.getPath();
	static std::string strHome = "E:/svn_new/C++/Project/RTU/HttpServer/x64/Release";
	std::string cmd = strHome + szCgi;// "C:/Users/Tiger/source/repos/testcgi/Release/testcgi.exe";

	std::cout <<"cgi="<< cmd <<std::endl;
	Poco::File aFile(cmd);
	if (!aFile.exists() || !aFile.isFile())
	{
		HttpUtils::Instance().handleNotFoundRequest(request, response);
		return;
	}

	std::vector<std::string> args;
	args.push_back("-env");
	Process::Env env;
	//request参数传给cgi
	
	env["TESTENV"] = "test";

	Pipe outPipe;
	ProcessHandle ph = Process::launch(cmd, args, 0, &outPipe, 0, env);
	int rc = Process::wait(ph);
	if (rc != 0)
	{
		//throw Poco::RuntimeException("Failed to process file");
		HttpUtils::Instance().handleNotFoundRequest(request, response);
		return;
	}
	
	PipeInputStream istr(outPipe);
	std::string s;
	int c = istr.get();
	while (c != -1) { s += (char)c; c = istr.get(); }
	
	response.setStatusAndReason(Poco::Net::HTTPResponse::HTTP_OK);
	response.setContentType("text/html");
	std::ostream& ostr = response.send();
	/*Object inner;
	inner.set("msg", s);
	inner.set("code", 200);
	inner.set("status", 200);
	inner.set("token", "eyJhbGciOiJIUzUxMiJ9");
	std::stringstream output;
	inner.stringify(output);
	ostr << output.str();
	*/

	ostr << s;
}