#include<iostream>
#include<cstdlib>
using namespace std;
long recursion(int n) {
	if (n == 1 || n == 2)
		return 1;
	else return recursion(n - 1) + recursion(n - 2);
}
int main() {
	int n;
	cout << "求第几项" << endl;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cout << recursion(i) << '\t';
	system("pause");
	return 0;
}