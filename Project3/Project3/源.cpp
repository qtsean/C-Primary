#include <stdio.h>
#include <stdlib.h>
int main()
{
	int price = 0;

	printf("�������Ԫ����");
	scanf_s("%d", &price);

	int change = 100 - price;

	printf("����%dԪ��\n", change);
	system("pause");
	return 0;

}