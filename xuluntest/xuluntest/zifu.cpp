#include <windows.h>
#include <cstdio>   
#include <sstream>
#include <string.h>
#include <limits>
#include "zifu.h"
//#include <VersionHelpers.h>
#pragma warning(disable: 4996)    
using namespace std;

/* ASCII���0-127 */
// �о���cmd�е�936�����޷������ASCII���ַ���
// ���������ЩASCII���Ӣ������д
string ch[32] = { "NULL","SOH","STX","ETX",
"EOT","ENQ","ACK","BEL","BS","HT","LF","VT",
"FF","CR","SO","SI","DLE","DC1","DC2","DC3","DC4",
"NAK","SYN","ETB","CAN","EM","SUB","ESC",
"FS","GS","RS","US" };
void zprint(int n, int m) {
	int i, j = 0;
	for (i = n; i <= m; i++) {
		if (i < 32) {
			//�ַ�����visual�ڵ������Ҫsstreamͷ�ļ�
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

/* �����������ͳ��ȼ������Сֵ */
void zcprint(int z){// �ƺ�������Ҫ����
	cout << "type: \t\t" << "*****************************************size*****************************************" << endl;
	cout << "bool: \t\t" << "��ռ�ֽ�����" << sizeof(bool);
	cout << "\t���ֵ��" << (numeric_limits<bool>::max)();
	cout << "\t\t\t��Сֵ��" << (numeric_limits<bool>::min)() << endl;

	cout << "char: \t\t" << "��ռ�ֽ�����" << sizeof(char);
	cout << "\t���ֵ��" << (int)(numeric_limits<char>::max)();
	cout << "\t\t\t��Сֵ��" << (int)(numeric_limits<char>::min)() << endl;

	cout << "signed char: \t" << "��ռ�ֽ�����" << sizeof(signed char);
	cout << "\t���ֵ��" << (int)(numeric_limits<signed char>::max)();
	cout << "\t\t\t��Сֵ��" << (int)(numeric_limits<signed char>::min)() << endl;

	cout << "unsigned char: \t" << "��ռ�ֽ�����" << sizeof(unsigned char);
	cout << "\t���ֵ��" << (int)(numeric_limits<unsigned char>::max)();
	cout << "\t\t\t��Сֵ��" << (int)(numeric_limits<unsigned char>::min)() << endl;

	cout << "wchar_t: \t" << "��ռ�ֽ�����" << sizeof(wchar_t);
	cout << "\t���ֵ��" << (int)(numeric_limits<wchar_t>::max)();
	cout << "\t\t\t��Сֵ��" << (int)(numeric_limits<wchar_t>::min)() << endl;

	cout << "short: \t\t" << "��ռ�ֽ�����" << sizeof(short);
	cout << "\t���ֵ��" << (numeric_limits<short>::max)();
	cout << "\t\t\t��Сֵ��" << (numeric_limits<short>::min)() << endl;
	cout << "int: \t\t" << "��ռ�ֽ�����" << sizeof(int);
	cout << "\t���ֵ��" << (numeric_limits<int>::max)();
	cout << "\t\t��Сֵ��" << (numeric_limits<int>::min)() << endl;
	cout << "unsigned: \t" << "��ռ�ֽ�����" << sizeof(unsigned);
	cout << "\t���ֵ��" << (numeric_limits<unsigned>::max)();
	cout << "\t\t��Сֵ��" << (numeric_limits<unsigned>::min)() << endl;
	cout << "long: \t\t" << "��ռ�ֽ�����" << sizeof(long);
	cout << "\t���ֵ��" << (numeric_limits<long>::max)();
	cout << "\t\t��Сֵ��" << (numeric_limits<long>::min)() << endl;
	cout << "long long: \t" << "��ռ�ֽ�����" << sizeof(long long);
	cout << "\t���ֵ��" << (numeric_limits<long long>::max)();
	cout << "\t��Сֵ��" << (numeric_limits<long long>::min)() << endl;
	cout << "unsigned long: \t" << "��ռ�ֽ�����" << sizeof(unsigned long);
	cout << "\t���ֵ��" << (numeric_limits<unsigned long>::max)();
	cout << "\t\t��Сֵ��" << (numeric_limits<unsigned long>::min)() << endl;
	cout << "double: \t" << "��ռ�ֽ�����" << sizeof(double);
	cout << "\t���ֵ��" << (numeric_limits<double>::max)();
	cout << "\t\t��Сֵ��" << (numeric_limits<double>::min)() << endl;
	cout << "long double: \t" << "��ռ�ֽ�����" << sizeof(long double);
	cout << "\t���ֵ��" << (numeric_limits<long double>::max)();
	cout << "\t\t��Сֵ��" << (numeric_limits<long double>::min)() << endl;
	cout << "float: \t\t" << "��ռ�ֽ�����" << sizeof(float);
	cout << "\t���ֵ��" << (numeric_limits<float>::max)();
	cout << "\t\t��Сֵ��" << (numeric_limits<float>::min)() << endl;
	cout << "size_t: \t" << "��ռ�ֽ�����" << sizeof(size_t);
	cout << "\t���ֵ��" << (numeric_limits<size_t>::max)();
	cout << "\t��Сֵ��" << (numeric_limits<size_t>::min)() << endl;
	cout << "string: \t" << "��ռ�ֽ�����" << sizeof(string) << endl;
	// << "\t���ֵ��" << (numeric_limits<string>::max)() << "\t��Сֵ��" << (numeric_limits<string>::min)() << endl;
	cout << "type: \t\t" << "*****************************************size*****************************************" << endl;
}

/* ����ϵͳ�汾�ͱ��������� */
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
	// printf("�������ܹ� : %u\n", sysInfo.wProcessorArchitecture);
	// printf("ҳ���С : %u\n", sysInfo.dwPageSize);
	// printf("Ӧ�ó�����С��ַ : %u\n", sysInfo.lpMinimumApplicationAddress);
	// printf("Ӧ�ó�������ַ : %u\n", sysInfo.lpMaximumApplicationAddress);
	// printf("���������� : %u\n", sysInfo.dwActiveProcessorMask);
	// printf("���������� : %u\n", sysInfo.dwNumberOfProcessors);
	// printf("���������� : %u\n", sysInfo.dwProcessorType);
	// printf("�����ڴ�������� : %u\n", sysInfo.dwAllocationGranularity);
	// printf("���������� : %u\n", sysInfo.wProcessorLevel);
	// printf("�������汾 : %u\n", sysInfo.wProcessorRevision);
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
		switch (osVersion.dwMajorVersion) //�ж����汾��
		{
		case 4:
			switch (osVersion.dwMinorVersion) //�жϴΰ汾��
			{
			case 0:
				if (osVersion.dwPlatformId == VER_PLATFORM_WIN32_NT)
					osName = "Microsoft Windows NT 4.0"; //1996��7�·���
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
			switch (osVersion.dwMinorVersion) //�ٱȽ�dwMinorVersion��ֵ
			{
			case 0:
				osName = "Microsoft Windows 2000"; //1999��12�·���
				break;

			case 1:
				osName = "Microsoft Windows XP"; //2001��8�·���
				break;

			case 2:
				if (osVersion.wProductType == VER_NT_WORKSTATION
					&& sysInfo.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64)
				{
					osName = "Microsoft Windows XP Professional x64 Edition";
				}
				else if (GetSystemMetrics(SM_SERVERR2) == 0)
					osName = "Microsoft Windows Server 2003"; //2003��3�·���
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
					osName = "Microsoft Windows Server 2008"; //�������汾
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
			//���жϲ���ϵͳ�汾
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
	printf(" %dλ", GetSystemBits());

	printf(" Version %u.%u", osVersion.dwMajorVersion, osVersion.dwMinorVersion);
	printf(" Build %u\n", osVersion.dwBuildNumber);
	//printf("PlatformId : %u\n", osVersion.dwPlatformId);
	//printf("%x\n",osVersion.wSuiteMask);
	//system("pause");
	return 0;

}