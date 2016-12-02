#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n, m;
	scanf_s("%d %d",&n, &m);
	int i = 1;
	int t = 1;
	int sumn = 0;
	int count = 0;
	while (count < n) 
	{
		while(i<=n)
			{while(t<i)	if (i%t == 0)break;
			else { sumn += i; count++; }t++;


		}i++;

		}
	}
