#include<iostream>
#include<stdlib.h>
using namespace std;
void fp(int* number, int *arr, bool* unused , int n, int length){
	if (0 == n) {											//���n�Ѿ�Ϊ0�������Ѿ���¼ÿһ����������ʼ�������
		for (int i = 0; i < length; i++) {
			cout << number[i]<<"\t";
		}
		cout << endl;
	}
	else {														//���n����0����������еݹ�
		for (int i = 0; i < length; i++) {						//ѭ��n��
			if (unused[i] == true) {							//���ж��Ǹ�������û�б��ù�������ù���������û�ù��������������
				number[length - n] = arr[i];					//ÿһ��ݹ����õ���λ����ͬ�ģ��������е��������Ǹ���λ
				unused[i] = false;								//�������Ϊ���ã��ں����ĵݹ�����������ٳ���
				fp(number, arr, unused, n - 1, length);			//�ݹ���䣬ÿ��n-1
				unused[i] = true;								//�ٰ������λ����Ϊδ�ã��Ա���һ��ݹ��е�ѭ�������Խ���
			}
		}
	}
}
int main() {
	int n;														//�˴�Ϊ��ʵ�飬��n������һ����0��ʼ������arr
	cin >> n;
	int * arr = new int[n];
	for (int i = 0; i < n; i++) {
		arr[i] = i;
	}
	int * number = new int[n] ;									//������¼ÿһ��ѭ�������õ�����
	bool * unused = new bool[n];								//�������ĳ�������Ƿ����ù�
	for (int i = 0; i < n; i++) {								//��ȫ����ʼ��Ϊδ��
		unused[i] = true;
	}
	int length = n;												//��Ϊ���鳤��n�ڵݹ��л�ı䣬�����length��¼n��ֵ
	fp(number, arr, unused, n, length);							//�ݹ鿪ʼ
	system("pause");
}