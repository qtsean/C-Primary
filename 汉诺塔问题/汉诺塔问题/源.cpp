#include<iostream>
#include<cstdlib>
using namespace std;
int s = 0;
void move(char x, char y) {
	cout << x << "---->" << y << endl;
	s++;
}
void hanoi(int n, char a, char b, char c) {
	if (n == 1)
		move(a, c);
	else {
		hanoi(n - 1, a, c, b);
		move(a, c);
		hanoi(n - 1, b, a, c);
	}
}
int main() {
	int m;
	cout << "盘子数:" << endl;
	cin >> m;
	cout << "移动" << m << "个盘子" << "过程如下" << endl;
	hanoi(m, 'A', 'B', 'C');
	cout << "次数：" << s << endl;
	system("pause");
	return 0;
}