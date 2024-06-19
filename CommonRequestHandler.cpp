#include "pch.h"
#include "CommonRequestHandler.h"
#include "HttpUtils.h"


CommonRequestHandler::CommonRequestHandler()
{
}


CommonRequestHandler::~CommonRequestHandler()
{
}


void NotFoudRequestHandler::handleRequest(HTTPServerRequest& request, HTTPServerResponse& response)
{
	HttpUtils::Instance().handleNotFoundRequest(request, response);
}


void NotTokenRequestHandler::handleRequest(HTTPServerRequest& request, HTTPServerResponse& response)
{
	HttpUtils::Instance().handleNotTokenRequest(request, response);
}


void StaticRequestHandler::handleRequest(HTTPServerRequest& request, HTTPServerResponse& response)
{
	//static std::string strHome = HttpUtils::Instance().getCommandPath() + "html";
	//std::cout << strHome;
	std::string strFile = request.getURI();

	static std::string strHome = "E:/svn_new/C++/Project/RTU/HttpServer/x64/Release/html";

	if (strFile == "/" || strFile == "/login" || strFile == "/index.html" || strFile == "/index.htm")
	{
		strFile = "/index.html";
	}

	//根据扩展名返回content type
	std::string ext = HttpUtils::Instance().getFileExt(strFile, 1);
	std::string outExt = HttpUtils::Instance().extToContentType(ext);
	response.setContentType(outExt);

	strFile = strHome + strFile;

	std::ifstream infile;
	infile.open(strFile, std::ios::binary | std::ios::in | std::ios::ate);
	long int length;
	length = infile.tellg();
	if (length > 0)
	{
		infile.seekg(0, std::ios::beg);
		char *buffer = new char[length];
		infile.read(buffer, length);
		response.sendBuffer(buffer, length);
		delete buffer;
		buffer = nullptr;
	}
	else
	{
		HttpUtils::Instance().handleNotFoundRequest(request, response);
	}
}
