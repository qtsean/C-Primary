#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

void set(int n, bool*got, int num, int*length,int a[])
{
	if (n == 0) {
		for (int i = 0; i < *length; i++) {
			if (got[i])
				cout << a[i];
		}
		cout << endl;
	}
	else {
		got[num] = false;
		set(n - 1, got, num+1, length, a);
		got[num] = true;
		set(n - 1, got, num+1, length, a);
	}
}
int main() {
	int a[10]{ 0,1,2,3,4,5,6,7,8,9 };
	int length = sizeof(a)/sizeof(int);
	bool *got = new bool[length] {false};
	int num = 0;
	set(length, got, num, &length,a);
	system("pause");
	return 0;
}