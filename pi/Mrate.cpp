#include <cstdio> 
#include <string>
#include <fstream>
#include <iostream>
#include <Windows.h>
#include "Mrate.h"

using namespace std;

// 默认参数集合
const int row = 40;// 训练样本/待测样本的默认行数
const int col = 20;// 训练样本/待测样本的默认列数
const int verify = 10;// 验证集的默认个案行数
const int testNumber = 801;
const int caseNumber = 1001;


// 默认变量集合
string AccurateValue[caseNumber], FuzzyValue[testNumber]; // 准确集/模糊集
long a = 10000, d, f[2801], g, e; // 用于梅钦类公式
int ii = 0, jj = 0, kk = 0; // 用于字符串分割

void Machin() {
	int  b = 0, c = 2800;
	while (b - c)
		f[b++] = a / 5;
	for (; d = 0, g = c * 2; c -= 14, splitting(e + d / a), e = d%a) {
		for (b = c; d += f[b] * a, f[b] = d%--g, d /= g--, --b; d *= b);
	}
}

void readTxt(string file)
{
	//创建一个文件输入流对象
	ifstream inFile;
	inFile.open(file, ios::in);
	string str;//显示一下
	if (inFile) {
		getline(inFile, str);//按行显示
		inFile.close();
	}
	else
		cout << file << "realPI.txt doesn't exist" << endl;

	for (int i = 0; i < 50; i++) {
		splitting(str.substr(i * 20, 20));
	}

}

void splitting(string A) {
	AccurateValue[ii++].append(A);
}
void splitting(int B) {
	string s;
	s = to_string(B);

	if (B / 10 < 1)
		s.insert(0, "000", 3); // 在开头插入000
	else if (B / 100 < 1)
		s.insert(0, "00", 2); // 在开头插入00
	else if (B / 1000 < 1)
		s.insert(0, "0", 1); // 在开头插入0

	FuzzyValue[kk].append(s);
	jj++;
	if (jj * 4 == col) {
		jj = 0;
		kk++;
	}
}

int comparestr() {
	int count = 0;
	for (int i = 0; i < kk; i++) {
		count += compares(AccurateValue[i], FuzzyValue[i]);
	}
	return count;
}

int compares(string A, string B) {
	if (A.compare(B))//完整的A和B的比较
		return 1;
	else
		return 0;
}

float rate(int wrong) {
	return (float)((1.0 - (1.0 * wrong / kk)) * 100);
}

void preprocessing(int Data[]) {
	for (int i = 0; i < kk; i++) {
		for (int j = 0; j < col; j++) {
			Data[i*col+j] = AccurateValue[i][j] % 48;
		}
	}
}