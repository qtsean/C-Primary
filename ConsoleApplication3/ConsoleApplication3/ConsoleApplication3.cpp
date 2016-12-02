// ConsoleApplication3.cpp : 定义控制台应用程序的入口点。
//

#include "stdio.h"


int main()
{
	int price = 0;
	printf("请输入金额：");
	scanf("%d", &price);
	int change = 100 - price;
	printf("找您的金额%d\n", change);

    return 0;
}

