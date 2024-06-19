# PocoHttpServer

A Small C++HTTP Server Based on Poco Project,Can run on Windows, Linux, or ARM Linux
Reference::poco-poco-1.13.3-release\poco-poco-1.13.3-release\Net\testsuite\src\HTTPServerTest.cpp

A small HTTP server based on the Poco project: https://github.com/pocoproject/poco.git.
The current project is a VC++version, compiled using VS2017. Simultaneously using VS to compile remotely under Debian 12. Then, cross compile was used in Debian and ran successfully in the Linux environment of the zynq development board. Subsequent supplements to the Linux project and ARM Linux project.
The main purpose of this project is to implement a small HTTP server, similar to Boa, for parameter configuration of embedded devices. It can also be used in regular programming environments on Windows or Linux. In practical applications, multiple projects such as Boa, libhttps, and nginx have been selected successively. Boa has weak functionality for upper computer, while other projects are too complex. Ultimately, it was found that using POCO was the best choice.
This project is based on the HTTPServerTest.cpp example of POCO, which adds file upload and CGI call functions, and can be tested using PostMan.



一个小型http服务器，基于poco项目:https://github.com/pocoproject/poco.git.
当前项目是VC++版本，使用VS2017编译。同时使用VS远程在debian 12下编译通过。然后在debian下使用交叉编译，在zynq开发板的linux环境下运行成功。linux项目和arm linux项目后续补充。
本项目主要是想实现一个小型的http server，类似boa，用于嵌入式设备进行参数配置。同样也可以用于windows或linux普通程序环境。在实际应用中，先后选择boa、libhttpd、nginx等多个项目，boa用于上位机功能偏弱，其他的项目过于复杂。最终发现使用poco是最佳选择。
本项目基于POCO的HTTPServerTest.cpp例子，增加了文件上传和CGI调用功能，可以使用PostMan进行测试。
