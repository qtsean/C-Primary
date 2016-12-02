#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a, b;

	printf("请输入两个整数：");
	scanf_s("%d %d", &a, &b);
	printf("%d + %d = %d\n",a, b, a + b);
	system("pause");
	return 0;

}