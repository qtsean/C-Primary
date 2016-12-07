#include <stdio.h>
#include <stdlib.h>
int wanshu(int a);
int main()
{
	
	int b, c;
	int w=0;
	int count=0;
	scanf_s("%d %d", &b, &c);
	int a = b;
	for(; a >= b&&a <= c;a++)
	{
		if (wanshu(a))
		{
			if (count == 0) { printf("%d", a); }
			else { printf(" %d", a); }
			w = 1; count++;
		}

	}
	if(w==1){}
	else
	{
		printf("NIL\n");
	}
	system("pause");
	return 0;

}
int wanshu(int a)
{
	int t = 1;
	int p = a;
	int sum = 0;
	if (a == 1)
	{
		return 0;
	}
	else {
		while (t <a)
		{
			if (a%t == 0)
			{
				sum += t;
			}
			t++;
		}
			if (sum == p)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}

