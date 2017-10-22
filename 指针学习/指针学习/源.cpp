#include<iostream>
#include<cstdlib>
using namespace std;
double faver(int s[], int n, int *max, int *min) {
	double aver = 0;
	*max = s[0];
	*min = s[0];
	for (int i = 0; i < n; i++) {
		aver += s[i];
		if (s[i] > *max)
			*max = s[i];
		if (s[i] < *min)
			*min = s[i];
	}
	return aver / n;
}
int main() {
	int a[5] = { 1,2,3,4,5 };
	int min;
	int max;
	double aver;
	aver=faver(a, 5, &max, &min);
	cout << "aver=:" <<aver<< "max=" << max << "min=" << min << endl;
	system("pause");
	return 0;
}