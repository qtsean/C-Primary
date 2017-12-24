#include<iostream>
#include<stdlib.h>
using namespace std;
int main() {
	int a[50];			//创建数组保存
	for (int i = 0; i < 50; i++) {		//初始化
		a[i] = i + 1;
	}
	int count = 0;
	for (int i = 0; i < 50; i++) {
		int is = 1;						//标记位，1表示是素数
		for (int j = 2; j < a[i]; j++) {		//如果遇到可以被整除的，标记位设置为0，表示非负数
			if (a[i] % j == 0)
				is = 0;
		}
		if (is == 1) {
			a[count] = a[i];			//如果是非负数，移到数组前面，并且count++
			count++;
		}
	}
	for (int i = 0; i < count; i++) {	//输出数组前几位素数
		cout << a[i] << "\t";
	}
	cout << endl;
	system("pause");
	return 0;
}
