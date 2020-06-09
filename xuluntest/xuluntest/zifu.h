#pragma once
#ifndef _ZIFU_H_
#define _ZIFU_H_
#include<iostream>

void zprint(int n = 0, int m = 127); // 打印ASCII码的0-127字符
void zcprint(int z = 1); // 打印常见数据类型的长度和最大最小值
int GetSystemBits(void); // 判断系统位数32 or 64
int GetOsInfo(void); // 系统信息
bool GetCompilerVer(void); // 编译器信息

#endif 


