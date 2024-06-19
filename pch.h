#ifndef PCH_H
#define PCH_H

// TODO: 添加要在此处预编译的标头

#include <sstream>
#include <iostream>
#include <iostream>
#include <fstream>
#include <strstream>
#include <string>
#include <map>
#include <vector>
#include <list>
#include <algorithm>


#include "Poco/Net/HTTPServer.h"
#include "Poco/Net/HTTPRequestHandler.h"
#include "Poco/Net/HTTPRequestHandlerFactory.h"
#include "Poco/Net/HTTPServerParams.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/Net/HTTPServerParams.h"
#include "Poco/Util/ServerApplication.h"
#include "Poco/Util/HelpFormatter.h"
#include "Poco/Util/Option.h"
#include "Poco/Util/OptionSet.h"

#include "Poco/DateTimeFormatter.h"
#include "Poco/DateTimeFormat.h"
#include "Poco/ThreadPool.h"
#include "Poco/StreamCopier.h"
#include "Poco/Net/PartHandler.h"
#include "Poco/Net/MessageHeader.h"
#include "Poco/Net/HTMLForm.h"
#include "Poco/CountingStream.h"
#include "Poco/NullStream.h"
#include "Poco/Net/HTTPResponse.h"
#include "Poco/URI.h"
#include "Poco/UTF8String.h"
#include "Poco/JSON/JSON.h"
#include "Poco/JSON/Object.h"
#include "Poco/JSON/Parser.h"
#include "Poco/JSON/Query.h"
#include "Poco/JSON/JSONException.h"
#include "Poco/JSON/Stringifier.h"
#include "Poco/JSON/ParseHandler.h"
#include "Poco/JSON/PrintHandler.h"
#include "Poco/JSON/Template.h"
#include "Poco/File.h"
#include "Poco/FileStream.h"
#include "Poco/StreamCopier.h"

using Poco::Net::ServerSocket;
using Poco::Net::HTTPRequestHandler;
using Poco::Net::HTTPRequestHandlerFactory;
using Poco::Net::HTTPServer;
using Poco::Net::HTTPRequest;
using Poco::Net::HTTPResponse;
using Poco::Net::HTTPServerRequest;
using Poco::Net::HTTPServerResponse;
using Poco::Net::HTTPServerParams;
using Poco::Net::HTTPMessage;
using Poco::Net::MessageHeader;
using Poco::Net::HTMLForm;
using Poco::Net::NameValueCollection;

using Poco::Util::ServerApplication;
using Poco::Util::HelpFormatter;
using Poco::Util::Option;
using Poco::Util::OptionSet;
using Poco::Util::Application;
using Poco::DateTimeFormatter;
using Poco::DateTimeFormat;
using Poco::Timestamp;
using Poco::ThreadPool;
using Poco::StreamCopier;
using Poco::CountingInputStream;
using Poco::NullOutputStream;
using Poco::Thread;
using Poco::URI;
using Poco::UTF8;
using Poco::DynamicStruct;
using Poco::DateTime;
using Poco::DateTimeFormatter;


using Poco::Path;
//using namespace Poco::JSON;
//using namespace Poco::Dynamic;
//测试：ab -c 10 -n 10000 http://127.0.0.1:8008/

#endif //PCH_H
