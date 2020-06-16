/*
	Բ���ʵ�ͳ��Ԥ�⣬���Ȱ���֤÷���๫ʽ��׼ȷ�Է�װΪһ��ͷ�ļ�.
	Ȼ��,���򵥵�ͳ�Ʒ���,���MATLAB.
											ZLC,2020/6/14
*/

#include <iostream>
#include <Windows.h>
#define N 800
#include "Mrate.h"

using namespace std;

int main(void) {
	int data[N]; // ����Ԫ��
	int frequency[10]; // Ƶ��ͳ��Ԫ��
	// ʹ��÷���๫ʽ����PI��ǰ800λ����ε�������ǰ1000λ��PIֵ��
	Machin();
	// ��ȡ��ʵPIֵ��ǰ1000λ
	readTxt("realPI.txt");
	// ��֤÷���๫ʽ��piֵ����ȷ��
	cout<< "÷���๫ʽ��piֵ��׼ȷ��: " << rate(comparestr()) << "%" << endl;

	/* ͳ�Ʒ��� */
	cout << "********************************************** ͳ�Ʒ��� **********************************************" << endl;
	// 1.����Ԥ����
	preprocessing(data);
	/*
	for (int i = 0; i < N; i++) {
		cout << data[i] ;
	}
	cout<< endl;
	*/
	// 2.����Ƶ��ͳ��
	memset(frequency,0,sizeof(frequency)); // ��ʼ��,�õ�һ��ȫ���Ƶ��ͳ��Ԫ��
	for (int i = 0; i < N; i++) {
		frequency[data[i]] ++;
	}
	for (int j = 0; j < 10; j++) {
		cout << j << "\t" << frequency[j] << endl;
	}
	// 3.����Ƶ��ͼ��

	system("pause");

	return 0;
}

