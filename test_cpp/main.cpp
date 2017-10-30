#include <Windows.h>
#include <stdio.h>
#include <iostream>


int main()
{
	printf("### hello world.\n");

	std::cout << "### hello world.(C++)" << std::endl;

	OutputDebugStringA("### trace test.\n");
	OutputDebugString(L"### trace test2.\n");

	//TRACE("### trace test3.\n");
	//ATLTRACE("### trace test4.\n");

	//_RPTN(_CRT_WARNING, "### trace test2.\n");

	return 0;
}
