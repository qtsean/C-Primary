#include <stdio.h>
#include <stdlib.h>

int main()
{
	double inch, foot;
	printf("Ӣ��Ӣ��");
	scanf_s("%lf %lf", &foot, &inch);
	printf("%f\n",((foot + inch / 12)*0.3048));
	system("pause");




return 0;
}