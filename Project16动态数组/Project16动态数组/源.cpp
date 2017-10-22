#include<iostream>
#include<cstdlib>
using namespace std;
void invert(double a[10], int n) {
	double t;
	double *i;
	double *j;
	i = a;
	j = a + n - 1;
	while (i < j) {
		t = *i;
		*i = *j;
		*j = t;
		i++;
		j--;

	}

}
int main() {
	double a[10];
	for (int i = 0; i < 10; i++)
		a[i] = i;
	invert(a, 10);
	for (int i = 0; i < 10; i++)
		cout << a[i] << "  ";
	system("pause");
	return 0;
}