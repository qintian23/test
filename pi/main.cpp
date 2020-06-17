/*
	圆周率的统计预测，首先把验证梅钦类公式的准确性封装为一个头文件.
	然后,做简单的统计分析,结合MATLAB.
											ZLC,2020/6/14
*/

#include <iostream>
#include <Windows.h>
#include "Mrate.h"
#define N 800
#define M 1000

using namespace std;

int main(void) {
	int cdata[N]; // 训练数据元组
	//int rdata[M]; // 样本总体元组
	int * frequency; // 频度统计
	// 使用梅钦类公式生成PI的前800位（如何调参生成前1000位的PI值）
	Machin();
	// 读取真实PI值的前1000位
	readTxt("realPI.txt");
	// 验证梅钦类公式的pi值的正确性
	cout<< "梅钦类公式的pi值的准确率: " << rate(comparestr()) << "%" << endl;

	/* 统计分析 */
	cout << "********************************************** 初步分析 **********************************************" << endl;
	// 1.数据预处理
	preprocessing(cdata, N);
	// preprocessing(rdata, M);
	// 考虑三元组存储0~9的位置信息(链表??)

	// 2.数字频度统计 : 能否做出一个动态的呢?
	frequency = frequentness(N, cdata);
	/*
	for (int i = 0; i < 10; i++) {
		cout << frequency[i] << endl;
	}
	/* 使用时间序列预测是困难的,那么使用智能算法呢?
	for (int i = 0; i < N; i++) {
		cout << cdata[i] << endl;
	}
	*/
	// frequentness(M, rdata);
	// 3.画出频度图像 : 暂时省略大部分,制作茎叶图
	CaulineLeafFigure(frequency);

	cout << "********************************************** 统计分析 **********************************************" << endl;
	/* 第1章	变量与数据*/
	/*
		怎么使用C++模拟抽签??
		使用C++模拟简单抽样:(保证了每个元素都有相同的机会抽到)
			能否得到一个函数,然后得到随机数并代入该函数运算,最后得到的结果是
	    符合该规则抽签的概率分布的.
			那么该抽签结果的数据又呈什么类型的数据结构?
		总体: n;	样本: m;
		重复抽样: 放回式抽样;	不重复抽样: 不放回抽样.
		默认: 
			① n>m; ② 抽m次;

	*/
	cout << "简单抽样" << endl; 

	/*
			把已知的一部分信息(该信息总体为n)按照某种规则划分为k层,
		然后,从各层中抽取一定数量的元素,组成规模为m的样本.
	*/
	cout << "分层抽样" << endl;

	/*
			按照某种顺序排列的信息量为n总体,随机得到一个初始点,
		然后等距抽取m个元素.
	*/
	cout << "系统抽样" << endl;

	/*
			先将总体划分为若干群(n),然后随机抽取部分群(m).
	*/
	cout << "整群抽样" << endl;

	/* 第2章	使用图表展示数据*/
	cout << "生成频数分布表" << endl;
	cout << "茎叶图" << endl;
	cout << "箱线图" << endl;
	cout << "散点图" << endl;

	/* 第3章	使用统计量描述数据*/
	cout << "平均数" << endl;
	cout << "加权平均数" << endl;
	cout << "分位数" << endl;
	cout << "中位数" << endl;
	cout << "四分位数" << endl;
	cout << "百分位数" << endl;
	cout << "众数" << endl;
	cout << "极差" << endl;
	cout << "四分位差" << endl;
	cout << "标准差" << endl;
	cout << "方差" << endl;
	cout << "标准分数" << endl;
	cout << "离散系数" << endl;
	cout << "偏态" << endl;
	cout << "峰态" << endl;

	/* 第4章	概率分布*/
	cout << "度量事件发生的可能性" << endl;
	cout << "期望值" << endl;
	cout << "指数分布" << endl;
	cout << "二项分布" << endl;
	cout << "泊松分布" << endl;
	cout << "超几何分布" << endl;
	cout << "t分布" << endl;
	cout << "卡方分布" << endl;
	cout << "F分布" << endl;
	cout << "统计量的标准误差" << endl;

	/* 第5章	参数估计*/
	cout << "点估计" << endl;
	cout << "区间估计" << endl;
	cout << "置信区间" << endl;
	cout << "评价估计量的标准" << endl;

	/* 第6章	假设检验*/
	/* 第7章	类别变量的推断*/
	/* 第8章	方差分析与试验设计*/
	/* 第9章	一元线性回归*/
	/* 第10章	多元线性回归*/
	/* 第11章	时间序列预测*/
	/* 第12章	非参数检验*/

	system("pause");

	return 0;
}

