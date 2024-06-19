#pragma once
class FileUploadHandler : public HTTPRequestHandler
{
public:
	FileUploadHandler();
	void handleRequest(HTTPServerRequest& request, HTTPServerResponse& response);
};
