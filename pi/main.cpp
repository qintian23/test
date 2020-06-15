/*
	Բ���ʵ�ͳ��Ԥ�⣬����ʹ�ü��㹫ʽ���Բ���ʵ�ǰnλ��
	Ȼ��ͳ������0~9�ĳ���Ƶ�ʵȵ���Ϣ��÷���๫ʽ��
	����һ��αPI����ʹ���������PIֵ������ĳ���������ڵȼۣ�
	���Ҹ�αPI����Ӧ������ĳ�ֲַ�������ʹ��ͳ��ѧ֪ʶ������
	C++��string����Ӵ�����������(�ѽ��) 
											ZLC,2020/6/14
*/
#include <cstdio> 
#include <string>
#include <fstream>
#include <iostream>
#include <Windows.h>

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

// Ĭ�Ϻ�������
void Machin();
void readTxt(string file);
void compares(string A, string B);
void splitting(string A);
void splitting(int B);
void comparestr();

int main(void) {
	// ʹ��÷���๫ʽ����PI��ǰ800λ����ε�������ǰ1000λ��PIֵ��
	Machin();
	// ��ȡ��ʵPIֵ��ǰ1000λ
	readTxt("realPI.txt");
	// �ַ����Ƚ�
	/*
	string A = "31415";
	A.insert(0, "000", 3);
	cout << A << endl;
	*/
	//string B = "32416";
	// compares(A, B);
	// �ָ��ַ���
	// 1. ʹ�ü򵥵�string��ά����,�µĴ洢�ռ����ڴ���������ı���
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
	//����һ���ļ�����������
	ifstream inFile;
	inFile.open(file, ios::in);
	string str;//��ʾһ��
	if (inFile) { //������������˵���ļ��򿪳ɹ�
		cout << file << " open scessful" << endl;
		getline(inFile, str);//������ʾ
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

	/* �ַ���ת��Ϊ����
	data = std::stoi(str.substr(0,8));
	cout << endl << data << endl;
	*/
}

void compares(string A, string B) {
	int i = 0, count = 0;
	if (!A.compare(B))//������A��B�ıȽ�
		cout << "����һ����" << endl;
	else {
		cout << "���߲�ͬ: " << endl;
		cout << "\t" << A <<  "\n\t" << B << endl;
		if (A.length() == B.length()) {
			for (i = 0; i < A.length(); i++) {
				if (A[i] != B[i]) {
					cout << "��" << i + 1 << "����ͬ: ";
					cout << A[i] << "\t" << B[i] << endl;
					// break; // ɨ�����в�ͬʱ,����Ҫbreak
					if (++count > 10)
						cout << "������" << count << "��ͬ" << endl;
				}
			}
		}
		else
			cout << "���߳��Ȳ�һ����" << endl;
	}
}

void splitting(string A) {
	
	//if (A.length() == col)
	//	cout << "���ݵ��ַ��������Ѻ�!" << endl;
	AccurateValue[ii++].append(A);
	//string erase = "";
	//A.swap(erase);
}
void splitting(int B) {
	string s;
	s = to_string(B);
	//cout <<  "\t" << B ;
	if (B / 10 < 1) 
		s.insert(0, "000", 3); // �ڿ�ͷ����000
	else if(B / 100 < 1)
		s.insert(0, "00", 2); // �ڿ�ͷ����00
	else if(B / 1000 < 1)
		s.insert(0, "0", 1); // �ڿ�ͷ����0
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
