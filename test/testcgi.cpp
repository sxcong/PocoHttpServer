// testcgi.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
/*
int main()
{
    std::cout << "Hello World!\n"; 
}*/

int main(int argc,  // Number of strings in array argv
	char *argv[],       // Array of command-line argument strings
	char **envp)       // Array of environment variable strings
{
	int count;

/*	printf("  argc =    %d\n", argc);

	// Display each command-line argument.
	printf("\nCommand-line arguments:\n");
	for (count = 0; count < argc; count++)
		printf("  argv[%d]   %s\n", count, argv[count]);

	// Display each environment variable.
	printf("\nEnvironment variables:\n");
	while (*envp != NULL)
		printf("  %s\n", *(envp++));

	char *cp = NULL, *ip = NULL;
	cp = getenv("REQUEST_METHOD");
	ip = getenv("CONTENT_LENGTH");

	if (cp)
		printf(" cp = %s\n", cp);

	if (ip)
		printf(" ip =  %s\n", ip);
	*/
	//printf("Content-type: text/html\n\n");
	printf("<html><title>get</title>\n");
	printf("<body>test</body>\n");
	printf("</html>\n");

	//printf("<script>\n");
	//printf("window.alert(\"用户名口令不能为空\"); \n");
	//printf("parent.parent.location.replace(\"/index.html\");\n");
	//printf("</script> \n");
	return 0;
}