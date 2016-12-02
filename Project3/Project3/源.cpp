#include <stdio.h>
#include <stdlib.h>
int main()
{
	int price = 0;

	printf("请输入金额（元）：");
	scanf_s("%d", &price);

	int change = 100 - price;

	printf("找您%d元。\n", change);
	system("pause");
	return 0;

}