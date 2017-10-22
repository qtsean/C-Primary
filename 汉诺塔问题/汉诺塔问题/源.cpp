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
	cout << "������:" << endl;
	cin >> m;
	cout << "�ƶ�" << m << "������" << "��������" << endl;
	hanoi(m, 'A', 'B', 'C');
	cout << "������" << s << endl;
	system("pause");
	return 0;
}