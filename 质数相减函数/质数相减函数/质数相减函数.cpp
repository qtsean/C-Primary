// 质数相减函数.cpp : 定义控制台应用程序的入口点。
//

// 质数相减3.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdlib.h"
int fun(int a);
int main()
{
	int m = 0;
	int n = 0;
	scanf_s("%d %d", &m, &n);
	printf("%d", fun(n) - fun(m - 1));
	system("pause");
	return 0;
}
int fun(int a) {
	int count = 0;
	int sum = 0;
	int prime = 1;
	for (int i = 2; count < a; i++)
	{

		for (int t = 2; t < i; t++)
		{
			prime = 1;
			if (i%t == 0) {
				prime = 0;
				break;
			}

		}
		if (prime == 1) {
			count++;
			sum += i;
		}
	}
	return sum;
}

