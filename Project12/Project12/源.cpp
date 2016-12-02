#include <stdio.h>
#include <stdlib.h>
int main()
{

	int a;
	scanf_s("%d", &a);
	int b = 1;
	int d = 0;
	int e = 1;
	while (a>0)
	{
		if (a % 2 - b % 2 == 0)
		{

			d = d + e;

		}
		e = e * 2;
		a = a / 10; b++;


	}
	printf("%d", d);

	system("pause");
	return 0;
}
