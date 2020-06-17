#include <cstdio> 
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
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
// 梅钦类公式
void Machin() {
	int  b = 0, c = 2800;
	while (b - c)
		f[b++] = a / 5;
	for (; d = 0, g = c * 2; c -= 14, splitting(e + d / a), e = d%a) {
		for (b = c; d += f[b] * a, f[b] = d%--g, d /= g--, --b; d *= b);
	}
}
// 读真实π值
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
// 分割
void splitting(string A) {
	AccurateValue[ii++].append(A);
}
// 分割
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
// 比较
int comparestr() {
	int count = 0;
	for (int i = 0; i < kk; i++) {
		count += compares(AccurateValue[i], FuzzyValue[i]);
	}
	return count;
}
// 比较
int compares(string A, string B) {
	if (A.compare(B))//完整的A和B的比较
		return 1;
	else
		return 0;
}
// 准确率
float rate(int wrong) {
	return (float)((1.0 - (1.0 * wrong / kk)) * 100);
}
// 数据预处理
void preprocessing(int Data[], int end) {
	for (int i = 0; i < end / col; i++) {
		for (int j = 0; j < col; j++) {
			Data[i * col + j] = AccurateValue[i][j] % 48;
		}
	}
}
// 频度
int * frequentness(int n, int data[]) {
	static int frequency[10];
	memset(frequency, 0, sizeof(frequency)); // 初始化,得到一个全零的频度统计元组
	for (int i = 0; i < n; i++) {
		frequency[data[i]] ++;
	}
	for (int j = 0; j < 10; j++) {
		cout << j << "\t" << frequency[j] << endl;
	}
	cout << endl;
	return frequency;
}
// 茎叶图
void CaulineLeafFigure(int * frequency,int len) {
	//int count = 0;
	int i = 0, mark, j = 0, k = 0;
	int Tendigits[11], unitsdigit[11]; // 茎叶
	int numeration[11]; // 记数(得到树高,和树宽)
	memset(numeration, 0, sizeof(numeration));
	sort(frequency, frequency + len);
	/*
	for (i = 0; i < len; i++) {
		cout << frequency[i] << endl;
	}
	*/
	
	for (i = 0; i < len; i++) { // 分离茎叶
		Tendigits[i] = frequency[i] / 10;
		unitsdigit[i] = frequency[i] % 10;
		// cout << Tendigits[i] << "\t" << unitsdigit[i] << endl;
	}

	mark = Tendigits[0];
	for (i = 0; i < len; i++) {
		if (mark != Tendigits[i]) {
			j++;
			numeration[j] += 1;
			mark = Tendigits[i];
		}
		else {
			numeration[j] += 1;
		}
	}

	cout << " 茎\t" << "叶" << endl;
	for (i = 0; i <= j; i++) {
		cout << ' ' << Tendigits[k] << " | ";
		//count = numeration[i];
		while (numeration[i]) {
			numeration[i]--;
			cout << unitsdigit[k] << ' ';
			k++;
		}
		//cout << count << endl;
		cout << endl;
	}
}
