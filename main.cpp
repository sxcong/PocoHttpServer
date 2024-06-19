// HttpServer.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include "MainApp.h"
#include <process.h>
#include "Poco/Process.h"
#include "Poco/Pipe.h"
#include "Poco/PipeStream.h"
#include "Poco/Path.h"
#include "Poco/Format.h"


using namespace std::string_literals;
using Poco::Process;
using Poco::ProcessHandle;
using Poco::Pipe;
using Poco::Path;
using Poco::PipeInputStream;
using Poco::PipeOutputStream;


int main(int argc, char** argv)
{
    std::cout << "Hello World!\n"; 

	MainApp app;
	return app.run(argc, argv);
}


