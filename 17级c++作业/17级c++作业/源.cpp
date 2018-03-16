#include<iostream>
#include<cstdlib>
#include"array.h"
using namespace std;

int main()
{
	cout << "以下为测试时所用的数据" << endl;
	int a[10] = { 1,2,3,4,3,9,8,8,7,4 };
	int b[5] = { 9,7,4,5,1 };
	int c[15];
	//int* c = new int[15];
	cout << "数组a的初值： " << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	cout << "数组b的初值： " << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << b[i] << " ";
	}
	cout << endl;
	cout << "合并a和b存入数组c，参数中在前的数组排在前" << endl;
	merge(a, 10, b, 5, c);
	for (int i = 0; i < 15; i++)
	{
		cout << c[i] << " ";
	}
	cout << endl;
	cout << "在数组a中搜索数字9，仅显示第一个该数字的位置" << endl;
	cout << search(a,10,9) << endl;
	cout << "在数组a中删除数字3，显示删除后的结果" << endl;
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
		cout << "数组已空";
	}
	cout << endl;
	cout << "将b中的数字全部设置为0" << endl;
	setV(b, 5, 0);
	for (int i = 0; i < 5; i++)
	{
		cout << b[i] << " ";
	}
	cout << endl;
	cout << "把剩下的a进行升序排序" << endl;
	sort(a, count);
	for (int i = 0; i < count; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}