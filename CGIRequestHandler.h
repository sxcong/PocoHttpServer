#pragma once
class CGIRequestHandler : public HTTPRequestHandler
{
public:
	CGIRequestHandler();
	~CGIRequestHandler();
	void handleRequest(HTTPServerRequest& request, HTTPServerResponse& response);
};

