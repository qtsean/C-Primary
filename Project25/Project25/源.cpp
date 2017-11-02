#include<iostream>
#include<string>
#include<cstring>
#include<stdlib.h>
using namespace std;

void set(int n, bool* got, int num, int* length) {
	if (n == 0) {
		for (int i = 0; i < *length; i++) {
			if (got[i])
				cout << "1";
			else
				cout << "0";
		}
		cout << endl;
	}
	else {
		got[num] = true;
		set(n - 1, got, num + 1, length);
		got[num] = false;
		set(n - 1, got, num + 1, length);
	}
}
int main() {
	int n;
	cin >> n;
	int num = 0;
	int length = n;
	//char* ch = new char[n] {0};
	bool *got = new bool[n] {false};
	set(n, got, num, &length);
	system("pause");
	return 0;
}