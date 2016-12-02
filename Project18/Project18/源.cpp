#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n, m;
	scanf_s("%d %d", &n, &m);
	int i = 2;
	int t = 2;
	int sumn = 0;
	int count = 0;
	int prime = 1;
	while (count < n)
	{for (i = 2; count < n; i++) 
		{
			if (i == 2)
			{ count++; sumn += 2; }
			else {
				    for (t = 2; t < i; t++) if (i%t == 0) { prime == 0; if (prime = 1)count++; sumn += i;
					}
				 }
		}if (prime = 1)count++; sumn += i;

	}



	


	int summ = 0;
	int count1 = 0;
	int i1 = 2;
	int t1 = 2;
	int prime1 = 1;
	while(count1 <= m) {
		for (i1 = 2; count1 < m; i1++) {
			if (i1 == 2) { count1++; summ += 2; }
			else {
				for (t1 = 2; t1 < i1; t1++) {
					if (i1%t1 == 0) {prime1=0; }
					if (prime1 = 1) { summ += i1; count1++; }

				}
			}
		}

		printf("%d", summ - sumn+n);
		system("pause");
		return 0;
	}
}
