/*
	圆周率的统计预测，首先使用计算公式获得圆周率的前n位；
	然后统计描述0~9的出现频率等等信息。梅钦类公式。
	构造一个伪PI数，使得这个数与PI值保持在某置信区间内等价，
	并且该伪PI数，应该满足某种分布，容易使用统计学知识阐述。
	C++的string类的子串函数有问题(已解决) 
											ZLC,2020/6/14
*/
#include <cstdio> 
#include <string>
#include <fstream>
#include <iostream>
#include <Windows.h>

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

// 默认函数集合
void Machin();
void readTxt(string file);
void compares(string A, string B);
void splitting(string A);
void splitting(int B);
void comparestr();

int main(void) {
	// 使用梅钦类公式生成PI的前800位（如何调参生成前1000位的PI值）
	Machin();
	// 读取真实PI值的前1000位
	readTxt("realPI.txt");
	// 字符串比较
	/*
	string A = "31415";
	A.insert(0, "000", 3);
	cout << A << endl;
	*/
	//string B = "32416";
	// compares(A, B);
	// 分割字符串
	// 1. 使用简单的string二维容器,新的存储空间用于储存待分析的变量
	// cout << endl << FuzzyValue[0] << endl;
	// cout << endl;
	// cout << endl << ii << endl;
	comparestr();
	//int x = 321;
	//cout << sizeof(x) << endl;

	system("pause");

	return 0;
}

void Machin() {
	int pi, i = 0, b = 0, c = 2800;
	while (b - c)
		f[b++] = a / 5;
	for (; d = 0, g = c * 2; c -= 14, printf("%04d", pi = e + d / a), splitting(pi), e = d%a) {
		for (b = c; d += f[b] * a, f[b] = d%--g, d /= g--, --b; d *= b);
	}
	// cout << endl;
	// cout << (pi[0] == 3141) << "\t" << i << endl;
	// cout << endl << pi << endl;
}

void readTxt(string file)
{
	// int data;
	//创建一个文件输入流对象
	ifstream inFile;
	inFile.open(file, ios::in);
	string str;//显示一下
	if (inFile) { //条件成立，则说明文件打开成功
		cout << file << " open scessful" << endl;
		getline(inFile, str);//按行显示
		cout << str << endl;
		inFile.close();
	}
	else
		cout << file << "realPI.txt doesn't exist" << endl;
	
	for (int i = 0; i < 50; i++) {
			splitting(str.substr(i * 20, 20));
			//cout << i * 20 << "\t" << (i + 1) * 20 - 1 << endl;
			//cout << endl << "A\t" << str.substr(i * 20, 20) << endl;
	}

	/* 字符串转化为整型
	data = std::stoi(str.substr(0,8));
	cout << endl << data << endl;
	*/
}

void compares(string A, string B) {
	int i = 0, count = 0;
	if (!A.compare(B))//完整的A和B的比较
		cout << "二者一样！" << endl;
	else {
		cout << "二者不同: " << endl;
		cout << "\t" << A <<  "\n\t" << B << endl;
		if (A.length() == B.length()) {
			for (i = 0; i < A.length(); i++) {
				if (A[i] != B[i]) {
					cout << "第" << i + 1 << "个不同: ";
					cout << A[i] << "\t" << B[i] << endl;
					// break; // 扫描所有不同时,不需要break
					if (++count > 10)
						cout << "这里有" << count << "不同" << endl;
				}
			}
		}
		else
			cout << "二者长度不一样！" << endl;
	}
}

void splitting(string A) {
	
	//if (A.length() == col)
	//	cout << "传递的字符串长度友好!" << endl;
	AccurateValue[ii++].append(A);
	//string erase = "";
	//A.swap(erase);
}
void splitting(int B) {
	string s;
	s = to_string(B);
	//cout <<  "\t" << B ;
	if (B / 10 < 1) 
		s.insert(0, "000", 3); // 在开头插入000
	else if(B / 100 < 1)
		s.insert(0, "00", 2); // 在开头插入00
	else if(B / 1000 < 1)
		s.insert(0, "0", 1); // 在开头插入0
	//cout << "\t" << s << endl;
	//cout << endl << B << endl;
	FuzzyValue[kk].append(s);
	jj++;
	if (jj * 4 == col) {
		jj = 0;
		kk++;
	}
}

void comparestr() {

	for (int i = 0; i < kk; i++) {
		cout << i + 1 << "\t";
		compares(AccurateValue[i], FuzzyValue[i]);
	}

	/*
	cout << endl << AccurateValue[2].length() <<endl;
	cout << endl << FuzzyValue[2].length() << endl;
	cout << endl << AccurateValue[1] << endl;
	cout << endl << FuzzyValue[1] << endl;
	*/
}
