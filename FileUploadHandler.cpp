#include "pch.h"
#include "FileUploadHandler.h"

using namespace Poco::JSON;
using namespace Poco::Dynamic;

FileUploadHandler::FileUploadHandler()
{

}

void FileUploadHandler::handleRequest(HTTPServerRequest& request, HTTPServerResponse& response)
{
	//qDebug() << "FileUploadHandler::handleRequest";
	NameValueCollection::ConstIterator it = request.begin();
	NameValueCollection::ConstIterator end = request.end();
	//qDebug() << "handlePart================";
	for (; it != end; ++it)
	{
	//	qDebug() << it->first.c_str() << ": " << it->second.c_str();
	}
	//qDebug() << "handlePart================";


	//"application/octet-stream; name=sample"
	//request.hasContentLength(),getContentLength64() getContentType()

	//Content-Type
	//Content-Range

	Object inner;

	if (request.has("Content-Disposition"))
	{
		std::string cd = request.get("Content-Disposition");
		std::string disp;
		NameValueCollection params;
		MessageHeader::splitParameters(cd, disp, params);
		//qDebug() << disp.c_str();
		if (params.has("filename"))
		{
			std::string fName = params.get("filename");
			std::ofstream ostr;
			ostr.open("d:/test.aaa", std::ios::binary | std::ios::out | std::ios::ate);

			std::istream& istr = request.stream();
			//std::string body;
			//istr>>body;
			StreamCopier::copyStream(istr, ostr);
			ostr.close();
		}
		else
		{
			std::string name = params["name"];
		}

		inner.set("msg", "ok");
		inner.set("code", 200);
		inner.set("status", 200);
	}
	else
	{
		inner.set("msg", "Content-Disposition error");
		inner.set("code", 201);
		inner.set("status", 200);
	}



	response.setStatusAndReason(Poco::Net::HTTPResponse::HTTP_OK);
	response.setContentType("text/plain");
	std::ostream& ostr = response.send();


	//inner.set("token", "eyJhbGciOiJIUzUxMiJ9");
	std::stringstream output;
	inner.stringify(output);
	ostr << output.str();
}