#include <windows.h>
#include <cstdio>   
#include <sstream>
#include <string.h>
#include <limits>
#include "zifu.h"
//#include <VersionHelpers.h>
#pragma warning(disable: 4996)    
using namespace std;

/* ASCII码的0-127 */
// 列举在cmd中的936编码无法输出的ASCII码字符，
// 这里给出这些ASCII码的英文名缩写
string ch[32] = { "NULL","SOH","STX","ETX",
"EOT","ENQ","ACK","BEL","BS","HT","LF","VT",
"FF","CR","SO","SI","DLE","DC1","DC2","DC3","DC4",
"NAK","SYN","ETB","CAN","EM","SUB","ESC",
"FS","GS","RS","US" };
void zprint(int n, int m) {
	int i, j = 0;
	for (i = n; i <= m; i++) {
		if (i < 32) {
			//字符串在visual在的输出需要sstream头文件
			cout << ch[i] << "\t";
			j++;
		}
		else {
			cout << (char)i << "\t";
			j++;
		}
		if (j == 5) {
			cout << endl;
			j = 0;
		}
	}
}

/* 常见数据类型长度及最大最小值 */
void zcprint(int z){// 似乎必须需要传参
	cout << "type: \t\t" << "*****************************************size*****************************************" << endl;
	cout << "bool: \t\t" << "所占字节数：" << sizeof(bool);
	cout << "\t最大值：" << (numeric_limits<bool>::max)();
	cout << "\t\t\t最小值：" << (numeric_limits<bool>::min)() << endl;

	cout << "char: \t\t" << "所占字节数：" << sizeof(char);
	cout << "\t最大值：" << (int)(numeric_limits<char>::max)();
	cout << "\t\t\t最小值：" << (int)(numeric_limits<char>::min)() << endl;

	cout << "signed char: \t" << "所占字节数：" << sizeof(signed char);
	cout << "\t最大值：" << (int)(numeric_limits<signed char>::max)();
	cout << "\t\t\t最小值：" << (int)(numeric_limits<signed char>::min)() << endl;

	cout << "unsigned char: \t" << "所占字节数：" << sizeof(unsigned char);
	cout << "\t最大值：" << (int)(numeric_limits<unsigned char>::max)();
	cout << "\t\t\t最小值：" << (int)(numeric_limits<unsigned char>::min)() << endl;

	cout << "wchar_t: \t" << "所占字节数：" << sizeof(wchar_t);
	cout << "\t最大值：" << (int)(numeric_limits<wchar_t>::max)();
	cout << "\t\t\t最小值：" << (int)(numeric_limits<wchar_t>::min)() << endl;

	cout << "short: \t\t" << "所占字节数：" << sizeof(short);
	cout << "\t最大值：" << (numeric_limits<short>::max)();
	cout << "\t\t\t最小值：" << (numeric_limits<short>::min)() << endl;
	cout << "int: \t\t" << "所占字节数：" << sizeof(int);
	cout << "\t最大值：" << (numeric_limits<int>::max)();
	cout << "\t\t最小值：" << (numeric_limits<int>::min)() << endl;
	cout << "unsigned: \t" << "所占字节数：" << sizeof(unsigned);
	cout << "\t最大值：" << (numeric_limits<unsigned>::max)();
	cout << "\t\t最小值：" << (numeric_limits<unsigned>::min)() << endl;
	cout << "long: \t\t" << "所占字节数：" << sizeof(long);
	cout << "\t最大值：" << (numeric_limits<long>::max)();
	cout << "\t\t最小值：" << (numeric_limits<long>::min)() << endl;
	cout << "long long: \t" << "所占字节数：" << sizeof(long long);
	cout << "\t最大值：" << (numeric_limits<long long>::max)();
	cout << "\t最小值：" << (numeric_limits<long long>::min)() << endl;
	cout << "unsigned long: \t" << "所占字节数：" << sizeof(unsigned long);
	cout << "\t最大值：" << (numeric_limits<unsigned long>::max)();
	cout << "\t\t最小值：" << (numeric_limits<unsigned long>::min)() << endl;
	cout << "double: \t" << "所占字节数：" << sizeof(double);
	cout << "\t最大值：" << (numeric_limits<double>::max)();
	cout << "\t\t最小值：" << (numeric_limits<double>::min)() << endl;
	cout << "long double: \t" << "所占字节数：" << sizeof(long double);
	cout << "\t最大值：" << (numeric_limits<long double>::max)();
	cout << "\t\t最小值：" << (numeric_limits<long double>::min)() << endl;
	cout << "float: \t\t" << "所占字节数：" << sizeof(float);
	cout << "\t最大值：" << (numeric_limits<float>::max)();
	cout << "\t\t最小值：" << (numeric_limits<float>::min)() << endl;
	cout << "size_t: \t" << "所占字节数：" << sizeof(size_t);
	cout << "\t最大值：" << (numeric_limits<size_t>::max)();
	cout << "\t最小值：" << (numeric_limits<size_t>::min)() << endl;
	cout << "string: \t" << "所占字节数：" << sizeof(string) << endl;
	// << "\t最大值：" << (numeric_limits<string>::max)() << "\t最小值：" << (numeric_limits<string>::min)() << endl;
	cout << "type: \t\t" << "*****************************************size*****************************************" << endl;
}

/* 返回系统版本和编译器类型 */
bool GetCompilerVer(void)
{
	//MSVC++ 14.0 _MSC_VER == 1900 (Visual Studio 2015)
	//MSVC++ 12.0 _MSC_VER == 1800 (Visual Studio 2013)
	//MSVC++ 11.0 _MSC_VER == 1700 (Visual Studio 2012)
	//MSVC++ 10.0 _MSC_VER == 1600 (Visual Studio 2010)
	//MSVC++ 9.0 _MSC_VER == 1500 (Visual Studio 2008)
	//MSVC++ 8.0 _MSC_VER == 1400 (Visual Studio 2005)
	//MSVC++ 7.1 _MSC_VER == 1310 (Visual Studio 2003)
	//MSVC++ 7.0 _MSC_VER == 1300
	//MSVC++ 6.0 _MSC_VER == 1200
	//MSVC++ 5.0 _MSC_VER == 1100
#ifdef __GNUC__
	printf("\nCompiled by gcc-%d.%d.%d\n", __GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__);
#elif _MSC_VER
	// printf("\nCompiled by %d\n", _MSC_VER);
	if (_MSC_VER == 1900)
		printf("\nCompiled by VC2015\n");
	else if (_MSC_VER == 1800)
		printf("\nCompiled by VC2013\n");
	else if (_MSC_VER == 1700)
		printf("\nCompiled by VC2012\n");
	else if (_MSC_VER == 1600)
		printf("\nCompiled by VC2010\n");
	else if (_MSC_VER == 1500)
		printf("\nCompiled by VC2008\n");
	else if (_MSC_VER == 1400)
		printf("\nCompiled by VC2005\n");
	else if (_MSC_VER == 1310)
		printf("\nCompiled by VC2003\n");
	else if (_MSC_VER == 1200)
		printf("\nCompiled by VC6.0");
	else
		printf("\nCompiled by Other VC compiler\n");

#endif // __GNUC__

#ifdef __GLIBC__
	printf("Glibc version :%d \n", __GLIBC__);//C Libraries
#elif __GLIBCXX__
	printf("Glibc version :%d \n", __GLIBCXX__);//C++ Libraries
#endif // __GLIBC__

	return true;
}

int GetSystemBits(void)
{
	SYSTEM_INFO si;
	GetSystemInfo(&si);
	if (si.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64 ||
		si.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_IA64)
	{
		return 64;
	}
	return 32;
}

int GetOsInfo(void)
{
	SYSTEM_INFO sysInfo;
	OSVERSIONINFOEX osVersion;

	GetSystemInfo(&sysInfo);

	// printf("OemId : %u\n", sysInfo.dwOemId);
	// printf("处理器架构 : %u\n", sysInfo.wProcessorArchitecture);
	// printf("页面大小 : %u\n", sysInfo.dwPageSize);
	// printf("应用程序最小地址 : %u\n", sysInfo.lpMinimumApplicationAddress);
	// printf("应用程序最大地址 : %u\n", sysInfo.lpMaximumApplicationAddress);
	// printf("处理器掩码 : %u\n", sysInfo.dwActiveProcessorMask);
	// printf("处理器数量 : %u\n", sysInfo.dwNumberOfProcessors);
	// printf("处理器类型 : %u\n", sysInfo.dwProcessorType);
	// printf("虚拟内存分配粒度 : %u\n", sysInfo.dwAllocationGranularity);
	// printf("处理器级别 : %u\n", sysInfo.wProcessorLevel);
	// printf("处理器版本 : %u\n", sysInfo.wProcessorRevision);
	// typedef struct _OSVERSIONINFOEX
	// {
	// DWORD dwOSVersionInfoSize;
	// DWORD dwMajorVersion;
	// DWORD dwMinorVersion;
	// DWORD dwBuildNumber;
	// DWORD dwPlatformId;
	// TCHAR szCSDVersion[128];
	// WORD wServicePackMajor;
	// WORD wServicePackMinor;
	// WORD wSuiteMask;
	// BYTE wProductType;
	// BYTE wReserved;
	// } OSVERSIONINFOEX, *POSVERSIONINFOEX, *LPOSVERSIONINFOEX;
	char* osName = NULL;
	char* vmark = NULL;

	osVersion.dwOSVersionInfoSize = sizeof(osVersion);

	if (GetVersionEx((OSVERSIONINFO*)&osVersion))
	{
		//osName
		switch (osVersion.dwMajorVersion) //判断主版本号
		{
		case 4:
			switch (osVersion.dwMinorVersion) //判断次版本号
			{
			case 0:
				if (osVersion.dwPlatformId == VER_PLATFORM_WIN32_NT)
					osName = "Microsoft Windows NT 4.0"; //1996年7月发布
				else if (osVersion.dwPlatformId == VER_PLATFORM_WIN32_WINDOWS)
					osName = "Microsoft Windows 95";
				break;
			case 10:
				osName = "Microsoft Windows 98";
				break;
			case 90:
				osName = "Microsoft Windows Me";
				break;
			}
			break;

		case 5:
			switch (osVersion.dwMinorVersion) //再比较dwMinorVersion的值
			{
			case 0:
				osName = "Microsoft Windows 2000"; //1999年12月发布
				break;

			case 1:
				osName = "Microsoft Windows XP"; //2001年8月发布
				break;

			case 2:
				if (osVersion.wProductType == VER_NT_WORKSTATION
					&& sysInfo.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64)
				{
					osName = "Microsoft Windows XP Professional x64 Edition";
				}
				else if (GetSystemMetrics(SM_SERVERR2) == 0)
					osName = "Microsoft Windows Server 2003"; //2003年3月发布
				else if (GetSystemMetrics(SM_SERVERR2) != 0)
					osName = "Microsoft Windows Server 2003 R2";
				break;
			}
			break;

		case 6:
			switch (osVersion.dwMinorVersion)
			{
			case 0:
				if (osVersion.wProductType == VER_NT_WORKSTATION)
					osName = "Microsoft Windows Vista";
				else
					osName = "Microsoft Windows Server 2008"; //服务器版本
				break;
			case 1:
				if (osVersion.wProductType == VER_NT_WORKSTATION)
					osName = "Microsoft Windows 7";
				else
					osName = "Microsoft Windows Server 2008 R2";
				break;
			case 2:
				if (osVersion.wProductType == VER_NT_WORKSTATION)
					osName = "Windows 8";
				else if (osVersion.wProductType != VER_NT_WORKSTATION)
					osName = "Windows Server 2012";
				break;
			case 3:
				if (osVersion.wProductType == VER_NT_WORKSTATION)
					osName = "Windows 8.1";
				else if (osVersion.wProductType != VER_NT_WORKSTATION)
					osName = "Windows Server 2012 R2";
				break;
			}
			break;
		case 10:
			switch (osVersion.dwMinorVersion)
			{
			case 0:
				if (osVersion.wProductType == VER_NT_WORKSTATION)
					osName = "Windows 10";
				else if (osVersion.wProductType != VER_NT_WORKSTATION)
					osName = "Windows Server 2016";
				break;

			}
			break;
		}

		//osMark
		switch (osVersion.dwMajorVersion)
		{
			//先判断操作系统版本
		case 5:
			switch (osVersion.dwMinorVersion)
			{
			case 0: //Windows 2000
				if (osVersion.wSuiteMask == VER_SUITE_ENTERPRISE)
					vmark = "Advanced Server";
				break;
			case 1: //Windows XP
				if (osVersion.wSuiteMask == VER_SUITE_EMBEDDEDNT)
					vmark = "Embedded";
				else if (osVersion.wSuiteMask == VER_SUITE_PERSONAL)
					vmark = "Home Edition";
				else
					vmark = "Professional";
				break;
			case 2:
				if (GetSystemMetrics(SM_SERVERR2) == 0
					&& osVersion.wSuiteMask == VER_SUITE_BLADE) //Windows Server 2003
					vmark = "Web Edition";
				else if (GetSystemMetrics(SM_SERVERR2) == 0
					&& osVersion.wSuiteMask == VER_SUITE_COMPUTE_SERVER)
					vmark = "Compute Cluster Edition";
				else if (GetSystemMetrics(SM_SERVERR2) == 0
					&& osVersion.wSuiteMask == VER_SUITE_STORAGE_SERVER)
					vmark = "Storage Server";
				else if (GetSystemMetrics(SM_SERVERR2) == 0
					&& osVersion.wSuiteMask == VER_SUITE_DATACENTER)
					vmark = "Datacenter Edition";
				else if (GetSystemMetrics(SM_SERVERR2) == 0
					&& osVersion.wSuiteMask == VER_SUITE_ENTERPRISE)
					vmark = "Enterprise Edition";
				else if (GetSystemMetrics(SM_SERVERR2) != 0
					&& osVersion.wSuiteMask == VER_SUITE_STORAGE_SERVER)
					vmark = "Storage Server";
				break;
			}
			break;

		case 6:
			switch (osVersion.dwMinorVersion)
			{
			case 0:
				if (osVersion.wProductType != VER_NT_WORKSTATION
					&& osVersion.wSuiteMask == VER_SUITE_DATACENTER)
					vmark = "Datacenter Server";
				else if (osVersion.wProductType != VER_NT_WORKSTATION
					&& osVersion.wSuiteMask == VER_SUITE_ENTERPRISE)
					vmark = "Enterprise";
				else if (osVersion.wProductType == VER_NT_WORKSTATION
					&& osVersion.wSuiteMask == VER_SUITE_PERSONAL) //Windows Vista
					vmark = "Home";
				break;
			case 1:
				if (osVersion.wProductType == VER_NT_WORKSTATION
					&& osVersion.wSuiteMask == VER_SUITE_SINGLEUSERTS)
					vmark = "Ultimate";

				break;
			}
			break;
		}

	}//if(GetVersionEx((OSVERSIONINFO *)&os))

	printf("%s ", osName);
	printf("%s", vmark);

	printf(" SP%u.%u", osVersion.wServicePackMajor, osVersion.wServicePackMinor);
	printf(" %d位", GetSystemBits());

	printf(" Version %u.%u", osVersion.dwMajorVersion, osVersion.dwMinorVersion);
	printf(" Build %u\n", osVersion.dwBuildNumber);
	//printf("PlatformId : %u\n", osVersion.dwPlatformId);
	//printf("%x\n",osVersion.wSuiteMask);
	//system("pause");
	return 0;

}