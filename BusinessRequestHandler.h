#pragma once
class BusinessRequestHandler
{
public:
	BusinessRequestHandler();
	~BusinessRequestHandler();
};

/*
 * class LoginRequestHandler
 * 
 * return: 0
 */
class LoginRequestHandler : public HTTPRequestHandler
{
public:
	void handleRequest(HTTPServerRequest& request, HTTPServerResponse& response);
};

/*
 * class LogoutRequestHandler
 * 
 * return: 0
 */
class LogoutRequestHandler : public HTTPRequestHandler
{
public:
	void handleRequest(HTTPServerRequest& request, HTTPServerResponse& response);
};

/*
 * class SetLanConfigRequestHandler
 * 
 * return: 0
 */
class SetLanConfigRequestHandler : public HTTPRequestHandler
{
public:
	void handleRequest(HTTPServerRequest& request, HTTPServerResponse& response);
};
/*
 * class GetLanConfigRequestHandler
 * 
 * return:³É¹¦·µ»Ø 0
 */
class GetLanConfigRequestHandler : public HTTPRequestHandler
{
public:
	void handleRequest(HTTPServerRequest& request, HTTPServerResponse& response);
};