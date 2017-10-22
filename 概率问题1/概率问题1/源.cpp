#include<iostream>
#include<cstdlib>
using namespace std;
int main() {
	int n = 0;
	cin >>n;
	double r=1;
	for (int i = 0; i < n; i++) {
		r = r*(365 - i) / 365;
	}
	cout << 1-r;
	system("pause");
	return 0;
}