#include <iostream>
#include <cstdio>
#include <Windows.h>
#include "zifu.h"
using namespace std;
int main()
{
	zprint();
	cout << endl;
	zcprint();
	cout << endl;
	printf("%d", GetSystemBits());
	GetCompilerVer();
	GetOsInfo();
	system("pause");
	return 0;
}