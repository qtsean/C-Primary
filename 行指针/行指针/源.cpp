#include<iostream>
#include<cstdlib>
using namespace std;
char *month_name(int n) {
	static char *month[] = {
		"Illegal",
		"Jan",
		"Feb",
		"MAR",
		"April",
		"May",
		"Jane",
		"July",
		"August",
		"September",
		"October",
		"November",
		"December"
	};
	return (n >= 1 && n <= 12) ? month[n] : month[0];
}
int main() {
	int n;
	cin >> n;
	cout << n << "-" << month_name(n) << endl;
	system("pause");
	return 0;
}