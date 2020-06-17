#pragma once
#ifndef _MRATE_H_
#define _MRATE_H_

// 默认函数集合
void Machin();
void readTxt(std::string file);
void splitting(std::string A);
void splitting(int B);
int compares(std::string A, std::string B);
int comparestr();
float rate(int wrong);
void preprocessing(int Data[], int end);
int * frequentness(int n, int data[]);
void CaulineLeafFigure(int * frequency, int len = 10);

#endif // !_MRATE_H_

