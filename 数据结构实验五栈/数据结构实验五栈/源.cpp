#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;

class numstack {
public:
	double *num;								//ջ������������
	int np;										//number pointer
	void push(char);							//���أ�������Ϊcharʱ��Ҫ��ȥ��0��
	void push(double);							//������Ϊdoubleʱ��ֱ�Ӵ���
	void pop();
	numstack();
};
numstack::numstack() {
	np = -1;									//������-1��ʼ����Ϊ-1��ʾ��
	num = new double[100];
}
void numstack::push(double a) {
	np++;
	num[np] = a;
}
void numstack::push(char a) {
	np++;
	num[np] = double(a)-double('0');
}
void numstack::pop() {
	if (np != -1)
		np--;
	else
		cout << "np�ѿ�" << endl;
}
class charstack {								//ջ���������������#��ʶ��
public:
	char cha[100];
	int cp;										//char pointer
	void push(char a);
	void pop();
	charstack();
};
charstack::charstack() {
	cp = -1;
}
void charstack::pop() {
	if (cp != -1)
		cp--;
	else
		cout << "cp�ѿ�" << endl;
}
void charstack::push(char a) {
	cp++;
	cha[cp] = a;
}
int compare(int i, int j) {						//����һ����ά���飬�����Ƚ����������֮������ȼ���ϵ��Ĭ��ͬ�������������ȼ������Ҳ࣬1��ʾ���ڣ�-1��ʾС�ڣ�0��ʾ���ڣ������������ͬʱ��ջ
	int a[7][7] =
	{
		{1,1,-1,-1,-1,1,1},
		{1,1,-1,-1,-1,1,1},
		{1,1,1,1,-1,1,1},
		{1,1,1,1,-1,1,1},
		{-1,-1,-1,-1,-1,0,9},
		{1,1,1,1,9,1,1},
		{-1,-1,-1,-1,-1,9,0}
	};
	return a[i][j];
}
int getindex(char a) {							//������������ֶ�Ӧ���������ö�ά����Ƚ����ȼ�
	int index = 0;
	switch (a)
	{
	case '+':
		index = 0;
		break;
	case '-':
		index = 1;
		break;
	case '*':
		index = 2;
		break;
	case '/':
		index = 3;
		break;
	case '(':
		index = 4;
		break;
	case ')':
		index = 5;
		break;
	case '#':
		index = 6;
	default:break;
	}
	return index;
}

int main() {
	numstack nb;								//number
	charstack op;								//operator
	char ip[100];								//input
	cin >> ip;
//	char ip[100] = "(1+5)/2#";
	int i = 0;									//�����ַ���������
	op.push('#');								//��ѹ��һ��#���������û�������ַ���ĩβ��#ƥ��
	while (ip[i] != '\0') {						//���û�������ַ���δ�����������ѭ��
		if (ip[i] >= '0'&&ip[i] <= '9') {		//������������֣���ѹջ
			nb.push(ip[i]);
			i++;
			continue;
		}
		if (ip[i]<'0' || ip[i]>'9') {			//������Ĳ�������
			if (op.cp == 0) {					//���ж�ջ���Ƿ������������û����ֱ��ѹ��
				op.push(ip[i]);
				i++;
				continue;
			}
			else{								//�������������Ƚ������������ǰһ������������ȹ�ϵ
				switch (compare(getindex(op.cha[op.cp]), getindex(ip[i]))) {
					case 1: {					//���ԭ��������ȼ�������������������������
						if (op.cha[op.cp] == '+') {		//�Ȱ�ջ������Ԫ�ص�ֵ������ʱ����
							double n1 = nb.num[nb.np];	
							double n2 = nb.num[nb.np - 1];
							nb.pop();					//������Ԫ�س�ջ
							nb.pop();
							nb.push(n1 + n2);			//������������ѹ��ջ
							op.pop();					//ʹ�ù����������ջ
						}
						else if (op.cha[op.cp] == '-') {
							double n1 = nb.num[nb.np];
							double n2 = nb.num[nb.np - 1];
							nb.pop();
							nb.pop();
							nb.push(n2 - n1);
							op.pop();
						}
						else if (op.cha[op.cp] == '*') {
							double n1 = nb.num[nb.np];
							double n2 = nb.num[nb.np - 1];
							nb.pop();
							nb.pop();
							nb.push(n1 * n2);
							op.pop();
						}
						else if (op.cha[op.cp] == '/') {
							double n1 = nb.num[nb.np];
							double n2 = nb.num[nb.np - 1];
							nb.pop();
							nb.pop();
							nb.push((n2 / n1)*1.0);
							op.pop();
						}
						break;
					}
					case -1: {
						op.push(ip[i]);		//����������������ԭ�������������������ѹ��
						i++;
						break;
					}
					case 0: {				//�����ȼ���ȣ���ʾ��Ҫ������������������##����ջ
						op.pop();
						i++;
						break;
					}
				}
			}

		}
	}
	cout << nb.num[nb.np] << endl;			//���������
	/*
	char test[100];
	for (int i = 0; i < 10; i++) {
		test[i] = ip[i];
	}
	for (int i = 0; i < 10; i++) {
		cout << test[i]<<"\t";
	}
	*/
	system("pause");
	return 0;
}
