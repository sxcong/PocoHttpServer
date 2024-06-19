#include "pch.h"
#include "HttpUtils.h"

using namespace Poco::JSON;
using namespace Poco::Dynamic;

HttpUtils::HttpUtils()
{
}


HttpUtils::~HttpUtils()
{
}

HttpUtils& HttpUtils::Instance()
{
	static HttpUtils agent;
	return agent;
}

void HttpUtils::handleOKRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
{
	response.setStatusAndReason(Poco::Net::HTTPResponse::HTTP_OK);
	response.setContentType("text/plain");
	std::ostream& ostr = response.send();
	Object inner;
	inner.set("msg", "ok");
	inner.set("code", 200);
	inner.set("status", 200);
	inner.set("token", "eyJhbGciOiJIUzUxMiJ9");
	std::stringstream output;
	inner.stringify(output);
	ostr << output.str();
}

void HttpUtils::handleNotFoundRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
{
	/*response.setStatusAndReason(Poco::Net::HTTPResponse::HTTP_NOT_FOUND);
	response.setChunkedTransferEncoding(true);
	response.setContentType("text/html");
	response.send()
		<< "<html>"
		<< "<head><title>404 - Not Found</title></head>"
		<< "<body><h1>Not Found</h1><p>The requested resource was not found.</p></body>"
		<< "</html>";
	*/
	response.setContentType("text/html");
	response.setStatus(HTTPResponse::HTTPStatus::HTTP_NOT_FOUND);
	response.setReason("Not Found");
	std::ostream& ostr = response.send();
	ostr << "\r\n";

}

void HttpUtils::handleNotTokenRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
{
	response.setStatusAndReason(Poco::Net::HTTPResponse::HTTP_OK);
	response.setContentType("text/plain");
	std::ostream& ostr = response.send();
	Object inner;
	inner.set("msg", "no token");
	inner.set("code", 202);
	inner.set("status", 202);
	std::stringstream output;
	inner.stringify(output);
	ostr << output.str();
}


void HttpUtils::handleErrorRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response, int errorCode, std::string& errorMsg)
{
	response.setStatusAndReason(Poco::Net::HTTPResponse::HTTP_OK);
	response.setContentType("text/plain");
	std::ostream& ostr = response.send();
	Object inner;
	inner.set("msg", errorMsg.c_str());
	inner.set("code", errorCode);
	inner.set("status", 202);
	std::stringstream output;
	inner.stringify(output);
	ostr << output.str();
}


std::string HttpUtils::extToContentType(const std::string& ext)
{
	if (ext == "jpg" || ext == "jpeg")
		return "image/jpeg";
	else if (ext == "png")
		return "image/png";
	else if (ext == "gif")
		return "image/gif";
	else if (ext == "ico")
		return "image/x-icon";
	else if (ext == "htm")
		return "text/html";
	else if (ext == "html")
		return "text/html";
	else if (ext == "css")
		return "text/css";
	else if (ext == "js")
		return "application/javascript";
	else if (ext == "xml")
		return "text/xml";
	else if (ext == "svg")
		return "image/svg+xml";

	else
		return "application/binary";
}

std::string HttpUtils::getFileExt(std::string& strFile, int isLower)
{
	std::string strTemp = strFile;
	if (isLower == 1)
	{
		std::transform(strTemp.begin(), strTemp.end(), strTemp.begin(), ::tolower);
	}

	std::string::size_type pos = strTemp.rfind('.');
	std::string strExt = strTemp.substr(pos == std::string::npos ? strTemp.length() : pos + 1);
	return strExt;
}

void HttpUtils::setCommandPath(const std::string& path)
{
	_commandPath = path;
}
