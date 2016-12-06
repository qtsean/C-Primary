#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a, b;
	int count = 1;
	scanf_s("%d/%d", &a, &b);
	printf("0.");
	int yushu;
	yushu = a;
	while(yushu!=0&&count<=200)
	{
		printf("%d", yushu * 10 / b);
		yushu = 10 * yushu%b;

		
		count++;
	}
	system("pause");
	return 0;
}