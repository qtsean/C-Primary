#include<iostream>
#include<cstdlib>
#include"array.h"
using namespace std;

int main()
{
	cout << "����Ϊ����ʱ���õ�����" << endl;
	int a[10] = { 1,2,3,4,3,9,8,8,7,4 };
	int b[5] = { 9,7,4,5,1 };
	int c[15];
	//int* c = new int[15];
	cout << "����a�ĳ�ֵ�� " << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	cout << "����b�ĳ�ֵ�� " << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << b[i] << " ";
	}
	cout << endl;
	cout << "�ϲ�a��b��������c����������ǰ����������ǰ" << endl;
	merge(a, 10, b, 5, c);
	for (int i = 0; i < 15; i++)
	{
		cout << c[i] << " ";
	}
	cout << endl;
	cout << "������a����������9������ʾ��һ�������ֵ�λ��" << endl;
	cout << search(a,10,9) << endl;
	cout << "������a��ɾ������3����ʾɾ����Ľ��" << endl;
	int count = del(a, 10, 3);
	if (count > 0) 
	{
		for (int i = 0; i < count; i++)
		{
			cout << a[i] << " ";
		}
	}
	else
	{
		cout << "�����ѿ�";
	}
	cout << endl;
	cout << "��b�е�����ȫ������Ϊ0" << endl;
	setV(b, 5, 0);
	for (int i = 0; i < 5; i++)
	{
		cout << b[i] << " ";
	}
	cout << endl;
	cout << "��ʣ�µ�a������������" << endl;
	sort(a, count);
	for (int i = 0; i < count; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}