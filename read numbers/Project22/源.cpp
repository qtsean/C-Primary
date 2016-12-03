#include <stdio.h>
#include <stdlib.h>
int main()
{
	/*int shuzi;*/
	int number;
	int count = 0;
	
	scanf_s("%d", &number);
	if (number < 0) 
	{ 
		number = -number;
		printf("fu ");
	
	}
	int t = number;
	while (number > 9) 
	{
		count++;
		number /= 10;
	}
	int mask=1;
	while(count>0)
	{
		mask *= 10;
		count--;
	}
	while (mask > 0)
	{
		int d = t / mask;
		switch (d)
		{
		case 0:printf("ling");
			break;
		case 1:printf("yi");
			break;
		case 2:printf("er");
			break;
		case 3:printf("san");
			break;
		case 4:printf("si");
			break;
		case 5:printf("wu");
			break;
		case 6:printf("liu");
			break;
		case 7:printf("qi");
			break;
		case 8:printf("ba");
			break;
		case 9:printf("jiu");
			break;
		}
		t = t%mask;
		mask /= 10;
		if (mask > 0)printf(" ");
	}
	/*int daoxu = 0;
	while(number>0)
	{
		daoxu = daoxu * 10 + number % 10;
		number = number / 10;
	}*/

	/*while(daoxu>0)
	{*/
		/* shuzi = daoxu % 10;*/
		
	/*}
		if(daoxu>9){printf(" "); }
		daoxu=daoxu / 10;
	}*/
	system("pause");
	return 0;
}