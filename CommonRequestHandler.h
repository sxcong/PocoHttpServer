#pragma once
class CommonRequestHandler
{
public:
	CommonRequestHandler();
	~CommonRequestHandler();
};

/*
 * class NotTokenRequestHandler
 * 
 * return: 0
 */
class NotFoudRequestHandler : public HTTPRequestHandler
{
public:
	void handleRequest(HTTPServerRequest& request, HTTPServerResponse& response);
};


/*
 * class NotTokenRequestHandler
 * 
 * return: 0
 */
class NotTokenRequestHandler : public HTTPRequestHandler
{
public:
	void handleRequest(HTTPServerRequest& request, HTTPServerResponse& response);
};

/*
 * class StaticRequestHandler
 * ¼ 
 * return: 0
 */
class StaticRequestHandler : public HTTPRequestHandler
{
public:
	void handleRequest(HTTPServerRequest& request, HTTPServerResponse& response);
};

