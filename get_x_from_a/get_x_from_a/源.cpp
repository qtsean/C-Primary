#include<iostream>
#include<stdlib.h>
#include<string>
#include<cstring>
#include<sstream>
using namespace std;
stringstream sstr;
void  sub(string str, int n,int* num) {
	if (n == 0) {
		cout << str << endl;
		str = str.substr(0, str.length() - n);
	}
	else {
		for (int i = 0; i < 2; i++) {
			if (i == 0) {
				str += "0";
				sub(str, n - 1,num);
			}
			else {
				str += "1";
				sub(str, n - 1,num);
			}
		}
	}
}

int main() {
	int n;
	cin >> n;
	//char *str = new char[n + 1]{ 0 };
	string str;
	int num = n;
	sub(str, n,&num);
	system("pause");
	return 0;
}