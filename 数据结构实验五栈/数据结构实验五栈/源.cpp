#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;

class numstack {
public:
	double *num;								//栈，用来存数字
	int np;										//number pointer
	void push(char);							//重载，当参数为char时需要减去‘0’
	void push(double);							//当参数为double时，直接存入
	void pop();
	numstack();
};
numstack::numstack() {
	np = -1;									//索引从-1开始，当为-1表示空
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
		cout << "np已空" << endl;
}
class charstack {								//栈，用来存运算符和#标识符
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
		cout << "cp已空" << endl;
}
void charstack::push(char a) {
	cp++;
	cha[cp] = a;
}
int compare(int i, int j) {						//建立一个二维数组，用来比较两个运算符之间的优先级关系，默认同级运算符左侧优先级大于右侧，1表示大于，-1表示小于，0表示等于，即两个运算符同时出栈
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
int getindex(char a) {							//把运算符与数字对应，利于利用二维数组比较优先级
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
	int i = 0;									//输入字符串的索引
	op.push('#');								//先压入一个#，用来与用户输入的字符串末尾的#匹配
	while (ip[i] != '\0') {						//当用户输入的字符串未结束，则进入循环
		if (ip[i] >= '0'&&ip[i] <= '9') {		//如输入的是数字，则压栈
			nb.push(ip[i]);
			i++;
			continue;
		}
		if (ip[i]<'0' || ip[i]>'9') {			//如输入的不是数字
			if (op.cp == 0) {					//先判断栈内是否有运算符，如没有则直接压入
				op.push(ip[i]);
				i++;
				continue;
			}
			else{								//如有运算符，则比较输入运算符与前一个运算符的优先关系
				switch (compare(getindex(op.cha[op.cp]), getindex(ip[i]))) {
					case 1: {					//如果原运算符优先级高于输入运算符，则进行运算
						if (op.cha[op.cp] == '+') {		//先把栈内两个元素的值存入临时变量
							double n1 = nb.num[nb.np];	
							double n2 = nb.num[nb.np - 1];
							nb.pop();					//把两个元素出栈
							nb.pop();
							nb.push(n1 + n2);			//把运算后的数字压入栈
							op.pop();					//使用过的运算符出栈
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
						op.push(ip[i]);		//如输入的运算符高于原运算符，则把输入运算符压入
						i++;
						break;
					}
					case 0: {				//如优先级相等，表示需要把连续的两个（）或##都出栈
						op.pop();
						i++;
						break;
					}
				}
			}

		}
	}
	cout << nb.num[nb.np] << endl;			//输出运算结果
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
