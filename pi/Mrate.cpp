#include <cstdio> 
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <Windows.h>
#include "Mrate.h"

using namespace std;

// Ĭ�ϲ�������
const int row = 40;// ѵ������/����������Ĭ������
const int col = 20;// ѵ������/����������Ĭ������
const int verify = 10;// ��֤����Ĭ�ϸ�������
const int testNumber = 801;
const int caseNumber = 1001;


// Ĭ�ϱ�������
string AccurateValue[caseNumber], FuzzyValue[testNumber]; // ׼ȷ��/ģ����
long a = 10000, d, f[2801], g, e; // ����÷���๫ʽ
int ii = 0, jj = 0, kk = 0; // �����ַ����ָ�
// ÷���๫ʽ
void Machin() {
	int  b = 0, c = 2800;
	while (b - c)
		f[b++] = a / 5;
	for (; d = 0, g = c * 2; c -= 14, splitting(e + d / a), e = d%a) {
		for (b = c; d += f[b] * a, f[b] = d%--g, d /= g--, --b; d *= b);
	}
}
// ����ʵ��ֵ
void readTxt(string file)
{
	//����һ���ļ�����������
	ifstream inFile;
	inFile.open(file, ios::in);
	string str;//��ʾһ��
	if (inFile) {
		getline(inFile, str);//������ʾ
		inFile.close();
	}
	else
		cout << file << "realPI.txt doesn't exist" << endl;

	for (int i = 0; i < 50; i++) {
		splitting(str.substr(i * 20, 20));
	}

}
// �ָ�
void splitting(string A) {
	AccurateValue[ii++].append(A);
}
// �ָ�
void splitting(int B) {
	string s;
	s = to_string(B);

	if (B / 10 < 1)
		s.insert(0, "000", 3); // �ڿ�ͷ����000
	else if (B / 100 < 1)
		s.insert(0, "00", 2); // �ڿ�ͷ����00
	else if (B / 1000 < 1)
		s.insert(0, "0", 1); // �ڿ�ͷ����0

	FuzzyValue[kk].append(s);
	jj++;
	if (jj * 4 == col) {
		jj = 0;
		kk++;
	}
}
// �Ƚ�
int comparestr() {
	int count = 0;
	for (int i = 0; i < kk; i++) {
		count += compares(AccurateValue[i], FuzzyValue[i]);
	}
	return count;
}
// �Ƚ�
int compares(string A, string B) {
	if (A.compare(B))//������A��B�ıȽ�
		return 1;
	else
		return 0;
}
// ׼ȷ��
float rate(int wrong) {
	return (float)((1.0 - (1.0 * wrong / kk)) * 100);
}
// ����Ԥ����
void preprocessing(int Data[], int end) {
	for (int i = 0; i < end / col; i++) {
		for (int j = 0; j < col; j++) {
			Data[i * col + j] = AccurateValue[i][j] % 48;
		}
	}
}
// Ƶ��
int * frequentness(int n, int data[]) {
	static int frequency[10];
	memset(frequency, 0, sizeof(frequency)); // ��ʼ��,�õ�һ��ȫ���Ƶ��ͳ��Ԫ��
	for (int i = 0; i < n; i++) {
		frequency[data[i]] ++;
	}
	for (int j = 0; j < 10; j++) {
		cout << j << "\t" << frequency[j] << endl;
	}
	cout << endl;
	return frequency;
}
// ��Ҷͼ
void CaulineLeafFigure(int * frequency,int len) {
	//int count = 0;
	int i = 0, mark, j = 0, k = 0;
	int Tendigits[11], unitsdigit[11]; // ��Ҷ
	int numeration[11]; // ����(�õ�����,������)
	memset(numeration, 0, sizeof(numeration));
	sort(frequency, frequency + len);
	/*
	for (i = 0; i < len; i++) {
		cout << frequency[i] << endl;
	}
	*/
	
	for (i = 0; i < len; i++) { // ���뾥Ҷ
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

	cout << " ��\t" << "Ҷ" << endl;
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
