#include<cstdlib>
#include<iostream>
using namespace std;
void index(double a[], double b[], int *p1, int *p2) {
	double min;
	if (a[0] - b[0] > 0) {
		min = a[0] - b[0];
	}
	else
		min = b[0] - a[0];
	int c = 0;
	int d = 0;
	double x;
	for (int i = 0; i<4; i++) {
		for (int j = 0; j<4; j++) {
			if (a[i] - b[j] < 0)
				x = b[j] - a[i];
			else
				x = a[i] - b[j];
			if (min > x) {
				min = x;
				c = i;
				d = j;
			}
		}
	}
	*p1 = c;
	*p2 = d;
	
}
int main() {
	double a[4] = {1,9,11,12.45};
	double b[4] = {2,11.001,12.5,12};
	int i1 = 0;
	int i2 = 0;
	int *p1 = &i1;
	int *p2 = &i2;
	index(a,b,p1,p2);
	cout << "(" << i1 << "," << i2 << ")" << endl;
	//system("pause");
	cin.get();
	return 0;
}
