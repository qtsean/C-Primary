#include<iostream>
#include<stdlib.h>
using namespace std;
int main() {
	int a[50];			//�������鱣��
	for (int i = 0; i < 50; i++) {		//��ʼ��
		a[i] = i + 1;
	}
	int count = 0;
	for (int i = 0; i < 50; i++) {
		int is = 1;						//���λ��1��ʾ������
		for (int j = 2; j < a[i]; j++) {		//����������Ա������ģ����λ����Ϊ0����ʾ�Ǹ���
			if (a[i] % j == 0)
				is = 0;
		}
		if (is == 1) {
			a[count] = a[i];			//����ǷǸ������Ƶ�����ǰ�棬����count++
			count++;
		}
	}
	for (int i = 0; i < count; i++) {	//�������ǰ��λ����
		cout << a[i] << "\t";
	}
	cout << endl;
	system("pause");
	return 0;
}
