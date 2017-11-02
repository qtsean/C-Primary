#include<iostream>
#include<stdlib.h>
int times = 0;																//定义一个全局变量来记录输出次数，来判断是否输出了全部的子集
using namespace std;
void set(int n, bool*got, int num, int*length, int a[])
{
	if (n == 0) {															//当n=0时开始输出
		cout << "{";														//用大括号包括每一个集合，可以显示空集
		for (int i = 0; i < *length; i++) {									//循环n变，输出每一个被标记的数
			if (got[i]) {
				cout << a[i]<<", ";
			}
		}
		cout << "}";
		cout << endl;
		times++;
	}
	else {
		got[num] = false;													//因为一个数只有被标记和不被标记两种状态，所以先设置为不被标记，开始递归
		set(n - 1, got, num + 1, length, a);					
		got[num] = true;													//再设置为被标记，开始递归
		set(n - 1, got, num + 1, length, a);
	}
}
int main() {
	int a[10]{ 0,1,2,3,4,5,6,7,8,9 };										//自定义一个数组，测试用
	int length = sizeof(a) / sizeof(int);									//取得数组长度
	bool *got = new bool[length] {false};									//初始化bool数组
	int num = 0;															//在此程序中用num来计数，每次num+1递归和n-1递归效果相同
	set(length, got, num, &length, a);
	cout << times<<endl;													//输出函数的调用次数，来判断是否等于2的n次方
	system("pause");
	return 0;
}