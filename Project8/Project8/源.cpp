#include <iostream>
#include <cstdlib>

using namespace std;
int main()
{
	char str[101];
	char sub[101];
	int len;
	int k, l;
	int i, j = 0;
	cout << "�������ַ���" << endl;
	cin.getline(str, 100);
	len = 0;
	while (str[len] != '\0') {
		len++;
	}
	cout << "���������ַ�������ʼλ�úͳ���" << endl;
	cin >> k >> l;
	while (k != 0 && l != 0) {
		j = 0;
		for (i = k - 1; i < k + l - 1 && i < len; i++) {
			sub[j] = str[i];
			j++;
		}
	}
	sub[j] = '\0';
	cout << sub << endl;


	system("pause");
	return 0;
}