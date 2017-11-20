#include<iostream>
#include<stdlib.h>
#include<ctime>
using namespace std;
int dsize = 960;
int divisor = 961;
struct node {
	pair<int, int>element;
	int used = 0;
	node* next = NULL;
};
class lh {
private:
	node** dic;
public:
	lh(pair<int, int>*a);
	int search(int);
	int find(int);
};
int lh::find(int index) {
	int j = index%divisor;
	node *current = dic[j];
	while (current != NULL) {
		if (current->element.first == index) {				//��Ϊ����search�жϹ������Կ϶�����
			return current->element.second;
		}
		current = current->next;
	}
}
int lh::search(int index) {
	int j = index%divisor;									//�����ַΪ�գ��򲻴���
	if (dic[j] == NULL) {
		return -1;
	}
	else if (dic[j]->element.first == index) {				//��ַ��Ϊ����������ͬ���򷵻�λ��
		return j;
	}
	else {
		node* current = dic[j]->next;						//��ַ��Ϊ�գ�������ֵ��ͬ������������ƣ�ֱ��������β���ҵ���Ҫ������
		while (current != NULL) {
			if (current->element.first == index) {
				return j;
			}
			current = current->next;
		}
		return -1;											//�����������û���򲻴���
	}
}
lh::lh(pair<int, int>*a) {
	dic = new node*[divisor];
	for (int i = 0; i < divisor; i++) {
		dic[i] = NULL;
	}
	for (int i = 0; i < dsize; i++) {
		if (dic[a[i].first%divisor]== NULL) {				//��Ϊ�գ����½��ڵ㲢����
			dic[a[i].first%divisor] = new node;
			dic[a[i].first%divisor]->element = a[i];
			dic[a[i].first%divisor]->used = 1;
		}
		else {
			if (dic[a[i].first%divisor]->next == NULL) {			//����Ϊ�գ�������½���������
				dic[a[i].first%divisor]->next = new node;
				dic[a[i].first%divisor]->next->element = a[i];
			}
			else if (dic[a[i].first%divisor]->next != NULL) {
				node* currentnode = dic[a[i].first%divisor]->next;
				while (currentnode->next != NULL) {
					currentnode = currentnode->next;
				}
				currentnode->next = new node;
				currentnode->next->element = a[i];
			}
		}
	}
	cout << "������ֵ�:" << endl;
	for (int i = 0; i < divisor; i++) {
		node *current = dic[i];
		while (current != NULL) {
			cout <<"λ�ã�"<<i<<"\t"<< "������" << current->element.first << "\t" << "ֵ��" << current->element.second << endl;
			current = current->next;
		}
	}
}
int main() {
	srand((unsigned)time(NULL));
	pair<int, int>*a = new pair<int, int>[dsize];
	cout << "������ֵ䣺" << endl;
	for (int i = 0; i < dsize; i++) {
		a[i].first = rand();
		a[i].second = a[i].first+1;
		cout << "������" << a[i].first << "\t" << "ֵ��" << a[i].second << endl;
	}
	lh test1(a);
	cout << "������ҪѰ�ҵ�����ֵ" << endl;
	int index;
	cin >> index;
	int d = test1.search(index);
	if (d == -1) {
		cout << "������������" << endl;
	}
	else {
		cout << "��������Ӧ��ֵΪ��" << test1.find(index) << endl;
	}
	system("pause");
	return 0;
}