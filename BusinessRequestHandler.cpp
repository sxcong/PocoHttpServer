#include "pch.h"
#include "HttpUtils.h"
#include "BusinessRequestHandler.h"
using namespace Poco::JSON;
using namespace Poco::Dynamic;

BusinessRequestHandler::BusinessRequestHandler()
{
}


BusinessRequestHandler::~BusinessRequestHandler()
{
}


void LoginRequestHandler::handleRequest(HTTPServerRequest& request, HTTPServerResponse& response)
{
	if (request.getMethod() == HTTPRequest::HTTP_POST)
	{
		std::istream& istr = request.stream();
		std::string body;
		istr >> body;
		Parser parser;
		Var result;
		try
		{
			result = parser.parse(body);
			Object::Ptr object = result.extract<Object::Ptr>();
			Var test = object->get("username");
			std::string name = test;

			Var test2 = object->get("password");
			std::string password = test2;

			if (name == "admin" && password == "password")//for test
			{
				HttpUtils::Instance().handleOKRequest(request, response);
			}
			else
			{
				std::string errorMsg = "username or password error";
				HttpUtils::Instance().handleErrorRequest(request, response, 202, errorMsg);
			}
		}
		catch (JSONException& jsone)
		{
			std::cout << jsone.message() << std::endl;
			std::string errorMsg = "JSONException json format error";
			HttpUtils::Instance().handleErrorRequest(request, response, 504, errorMsg);
			return;
		}
		catch (...)
		{
			std::string errorMsg = "json format error";
			HttpUtils::Instance().handleErrorRequest(request, response, 502, errorMsg);
			return;
		}
	}
	else
	{
		std::string errorMsg = "It only supports the POST method.!";
		HttpUtils::Instance().handleErrorRequest(request, response, 202, errorMsg);
	}
}

void LogoutRequestHandler::handleRequest(HTTPServerRequest& request, HTTPServerResponse& response)
{

}

void SetLanConfigRequestHandler::handleRequest(HTTPServerRequest& request, HTTPServerResponse& response)
{
	if (request.getMethod() == HTTPRequest::HTTP_POST)
	{
		std::istream& istr = request.stream();
		std::string body;
		istr >> body;

		Parser parser;
		Var result;
		try
		{
			result = parser.parse(body);
			Object::Ptr object = result.extract<Object::Ptr>();
			Var test = object->get("ip");
			std::string ip = test;

			Var test2 = object->get("mask");
			std::string mask = test2;

			Var test3 = object->get("gateway");
			std::string gateway = test2;

			std::string file("dummy_file.json");

			Poco::FileOutputStream fos(file);
			if (fos.good())
			{
				fos << body;
				fos.close();
			}
			HttpUtils::Instance().handleOKRequest(request, response);
			return;
		}
		catch (JSONException& jsone)
		{
			std::cout << jsone.message() << std::endl;
			std::string errorMsg = "JSONException json format error";
			HttpUtils::Instance().handleErrorRequest(request, response, 504, errorMsg);
			return;
		}
		catch (...)
		{
			std::string errorMsg = "json format error";
			HttpUtils::Instance().handleErrorRequest(request, response, 502, errorMsg);
			return;
		}
	}
	else
	{
		std::string errorMsg = "It only supports the POST method.!";
		HttpUtils::Instance().handleErrorRequest(request, response, 202, errorMsg);
	}
}


void GetLanConfigRequestHandler::handleRequest(HTTPServerRequest& request, HTTPServerResponse& response)
{
	if (request.getMethod() == HTTPRequest::HTTP_GET)
	{
		Object obj;
		obj.set("msg", "ok");
		obj.set("code", 200);
		obj.set("status", 200);

		std::string file("dummy_file.json");
		Poco::FileInputStream fis(file);
		if (fis.good())
		{
			std::string read;
			fis >> read;

			Parser parser;
			Var result;
			try
			{
				result = parser.parse(read);
			}
			catch (JSONException& jsone)
			{
				std::cout << jsone.message() << std::endl;
			}

			obj.set("data", result);
			std::stringstream output;
			obj.stringify(output);
			std::ostream& ostr = response.send();
			ostr << output.str();
		}
		else
		{
			obj.set("data", "");
			std::stringstream output;
			obj.stringify(output);
			std::ostream& ostr = response.send();
			ostr << output.str();
		}
	}
	else
	{
		std::string errorMsg = "It only supports the GET method.!";
		HttpUtils::Instance().handleErrorRequest(request, response, 202, errorMsg);
	}
}