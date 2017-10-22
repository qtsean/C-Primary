#include<iostream>
#include<cstdlib>
using namespace std;
int main() {
	int *p;
	int a[3][4];
	int max = a[0][0];
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 4; j++)
			a[i][j] = 10 * (i + 1) + j + 1;
	for (p = &a[0][0]; p < &a[0][0] + 12; p++) {
		if (*p > max)
			max = *p;
	}
	cout << "max:" << max;
	system("pause");
	return 0;

}