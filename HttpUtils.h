#pragma once

#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"


class HttpUtils
{
public:
	static HttpUtils& Instance();
	HttpUtils();
	~HttpUtils();

	void handleOKRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);
	void handleNotFoundRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);
	void handleNotTokenRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);
	void handleErrorRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response, int errorCode, std::string& errorMsg);

	std::string extToContentType(const std::string& ext);
	std::string getFileExt(std::string& strFile, int isLower);

	void setCommandPath(const std::string& path);
	std::string getCommandPath() { return _commandPath; };

private:
	std::string _commandPath;

};

