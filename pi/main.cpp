/*
	圆周率的统计预测，首先把验证梅钦类公式的准确性封装为一个头文件.
	然后,做简单的统计分析,结合MATLAB.
											ZLC,2020/6/14
*/

#include <iostream>
#include <Windows.h>
#define N 800
#include "Mrate.h"

using namespace std;

int main(void) {
	int data[N]; // 数据元组
	int frequency[10]; // 频度统计元组
	// 使用梅钦类公式生成PI的前800位（如何调参生成前1000位的PI值）
	Machin();
	// 读取真实PI值的前1000位
	readTxt("realPI.txt");
	// 验证梅钦类公式的pi值的正确性
	cout<< "梅钦类公式的pi值的准确率: " << rate(comparestr()) << "%" << endl;

	/* 统计分析 */
	cout << "********************************************** 统计分析 **********************************************" << endl;
	// 1.数据预处理
	preprocessing(data);
	/*
	for (int i = 0; i < N; i++) {
		cout << data[i] ;
	}
	cout<< endl;
	*/
	// 2.数字频度统计
	memset(frequency,0,sizeof(frequency)); // 初始化,得到一个全零的频度统计元组
	for (int i = 0; i < N; i++) {
		frequency[data[i]] ++;
	}
	for (int j = 0; j < 10; j++) {
		cout << j << "\t" << frequency[j] << endl;
	}
	// 3.画出频度图像

	system("pause");

	return 0;
}

