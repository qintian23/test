#pragma once
#ifndef _ZIFU_H_
#define _ZIFU_H_
#include<iostream>

void zprint(int n = 0, int m = 127); // ��ӡASCII���0-127�ַ�
void zcprint(int z = 1); // ��ӡ�����������͵ĳ��Ⱥ������Сֵ
int GetSystemBits(void); // �ж�ϵͳλ��32 or 64
int GetOsInfo(void); // ϵͳ��Ϣ
bool GetCompilerVer(void); // ��������Ϣ

#endif 


