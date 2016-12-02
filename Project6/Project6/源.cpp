#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a;
	scanf_s("%d", &a);

		int b = a / 100;
		int c = (a / 10) % 10;
		int d = a % 10;
		int e = d * 100 + c * 10 + b;
		printf("%d", e);
		system("pause");
		return 0;
	

}