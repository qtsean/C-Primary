#include<iostream>
#include<stdlib.h>
int times = 0;																//����һ��ȫ�ֱ�������¼������������ж��Ƿ������ȫ�����Ӽ�
using namespace std;
void set(int n, bool*got, int num, int*length, int a[])
{
	if (n == 0) {															//��n=0ʱ��ʼ���
		cout << "{";														//�ô����Ű���ÿһ�����ϣ�������ʾ�ռ�
		for (int i = 0; i < *length; i++) {									//ѭ��n�䣬���ÿһ������ǵ���
			if (got[i]) {
				cout << a[i]<<", ";
			}
		}
		cout << "}";
		cout << endl;
		times++;
	}
	else {
		got[num] = false;													//��Ϊһ����ֻ�б���ǺͲ����������״̬������������Ϊ������ǣ���ʼ�ݹ�
		set(n - 1, got, num + 1, length, a);					
		got[num] = true;													//������Ϊ����ǣ���ʼ�ݹ�
		set(n - 1, got, num + 1, length, a);
	}
}
int main() {
	int a[10]{ 0,1,2,3,4,5,6,7,8,9 };										//�Զ���һ�����飬������
	int length = sizeof(a) / sizeof(int);									//ȡ�����鳤��
	bool *got = new bool[length] {false};									//��ʼ��bool����
	int num = 0;															//�ڴ˳�������num��������ÿ��num+1�ݹ��n-1�ݹ�Ч����ͬ
	set(length, got, num, &length, a);
	cout << times<<endl;													//��������ĵ��ô��������ж��Ƿ����2��n�η�
	system("pause");
	return 0;
}