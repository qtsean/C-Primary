#include <stdio.h>
#include <stdlib.h>
int zhishu(int);
int main()
{
	int a;
	scanf_s("%d", &a);
	printf("%d=",a);
	if (zhishu(a))
	{
		printf("%d", a);
	}
	else
	{
		int q = 2;
		while (q <= a)
		{
			if (a%q == 0)
			{
				printf("%d", q);
				if (a>q)
				{
					printf("x");
				}
				a /= q;

			}
			else
			{
				q++;
			}


		}
	}
	system("pause");
	return 0;
}
int zhishu(int a)
{
	int t = 2;
	int prime = 1;
	if (a == 2)
	{
		prime = 1;
	}
	else
	{
		for (t = 2; t < a; t++)
		{
			if (a%t == 0)
				prime = 0;

			
		}
	}
	return prime;
}