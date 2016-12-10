#include <stdio.h>
#include <stdlib.h>
int main()
{
	int M[101];
	int i;
	int count = 0;
	int a;
	for (i = 0; i < 101; i++)
	{
		M[i] = 0;
	}
	int mi;
	int xishu;
	//for (a = 0; a < 10; a++) {
	//	scanf_s("%d %d", &mi, &xishu);
	//	M[mi] = M[mi] + xishu;
	//}
	//while (scanf_s("%d %d", &mi, &xishu)!=EOF)
	//{
	//	M[mi] = M[mi] + xishu;
	//}
	
		
	
	for (i = 100; i >= 0; i--)
	{
		if (M[i] != 0)
		{
			if (count != 0) { printf("+"); }
			if (i > 1) { printf("%dx%d", M[i], i); }
			if (i == 1) { printf("%dx", M[i]); }
			if (i == 0) { printf("%d", M[i]); }
			count++;
		}

	}
	system("pause");
	return 0;
}