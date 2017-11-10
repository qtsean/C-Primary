#include<iostream>
#include<stdlib.h>
using namespace std;
struct chain {
	int element;
	chain * next=NULL;
};
class AC {
private:
	chain * firstnode;
	chain * secondchain;
public:
	AC(int *a, int n);
	void inserthead(int newelement);
	void showreverse();
	void show();
	void erase(int index);
	int search(int number);
	void getsecondchain(int *a, int n);
	void merge();
	chain* sort(chain * sorted);
};
chain * AC::sort(chain * sorted) {
	chain * temp = new chain;
	//temp->element = sorted->element;
	chain* scurrentnode = sorted;
	chain* tcurrentnode = temp;
	while (scurrentnode != NULL) {
		if (scurrentnode->next != NULL) {
			tcurrentnode->next = new chain;
		}
//		tcurrentnode->next = scurrentnode->next;
		tcurrentnode->element = scurrentnode->element;
		if (scurrentnode->next != NULL) {
			tcurrentnode = tcurrentnode->next;
		}
		scurrentnode = scurrentnode->next;
	}
	for (int i = 0; i < 100; i++) {
		bool changed = 0;
		chain * current = temp;
		while (current->next != NULL) {
			if (current->element > current->next->element) {
				changed = 1;
				int swap = current->element;
				current->element = current->next->element;
				current->next->element = swap;
			}
			current = current->next;
		}
		if (changed == 0)
			break;
	}
	/*
	chain * current = temp;
	while (current != NULL) {
		cout << current->element << "\t";
		current = current->next;
	}
	*/
	return temp;
}
void AC::merge() {
	chain * currentnode1 = sort(firstnode);
	chain * currentnode2 = sort(secondchain);
	cout << "��������һ����" << endl << endl;
	chain * output = currentnode1;
	while (output != NULL) {
		cout << output->element << "\t";
		output = output->next;
	}
	cout << endl << endl;
	cout << "�������������" << endl << endl;
	chain * output1 = currentnode2;
	while (output1 != NULL) {
		cout << output1->element << "\t";
		output1 = output1->next;
	}
	cout << endl << endl;
	chain * temp = new chain;
	chain * temphead = temp;
	while (currentnode1 != NULL && currentnode2 != NULL) {
		if (currentnode1->element <= currentnode2->element) {
			temp->element = currentnode1->element;
			temp->next = new chain;
			temp = temp->next;
			currentnode1 = currentnode1->next;
		}
		else {
			temp->element = currentnode2->element;
			temp->next = new chain;
			temp = temp->next;
			currentnode2 = currentnode2->next;
		}
	}
	if (currentnode1 == NULL) {
		while (currentnode2 != NULL) {
			temp->element = currentnode2->element;
			
			if (currentnode2->next != NULL) {
				temp->next = new chain;
				temp = temp->next;
			}
			currentnode2 = currentnode2->next;	
		}
	}
	else {
		while (currentnode1 != NULL) {
			temp->element = currentnode1->element;
			
			if (currentnode1->next != NULL) {
				temp->next = new chain;
				temp = temp->next;
			}
			currentnode1 = currentnode1->next;
			
		}
	}
	cout << "�ϲ������������" << endl << endl;
	while (temphead != NULL) {
		cout << temphead->element << "\t";
		temphead = temphead->next;
	}
	cout << endl << endl;
	
}
void AC::getsecondchain(int *a, int n) {
	secondchain = new chain;
	secondchain->element = a[0];
	secondchain->next = new chain;
	chain* currentnode = secondchain->next;
	for (int i = 1; i < n; i++) {
		currentnode->element = a[i];
		if (i < n - 1) {
			currentnode->next = new chain;
			currentnode = currentnode->next;
		}
		else {
			currentnode->next = NULL;
		}
	}
	/*
	chain* current = secondchain;
	while (current != NULL) {
		cout << current->element << "\t";
		current = current->next;
	}
	*/
	cout << endl;
}
int AC::search(int number) {
	chain * currentnode = firstnode;
	for (int i = 0; currentnode != NULL;i++,currentnode=currentnode->next) {
		if (currentnode->element == number) {
			return i+1;
		}
	}
		return 0;
}
void AC::erase(int index) {
	chain * currentnode = firstnode;
	chain * lastnode=NULL;
	bool found = 1;
	if (index == 0) {
		chain * temp = firstnode;
		firstnode = firstnode->next;
		delete temp;
	}
	else {
		for (int i = 0; i < index; i++) {
			if (currentnode->next == NULL) {
				found = 0;
				break;
			}
			lastnode = currentnode;
			currentnode = currentnode->next;
		}
		if (found == 1) {
			chain * temp = currentnode;
			lastnode->next = currentnode->next;
			delete temp;
		}
	}
	
}
void AC::show() {
	cout << "���������������" << endl << endl;
	chain* currentnode = firstnode;
	while (currentnode != NULL) {
		cout << currentnode->element<<"\t";
		currentnode = currentnode->next;
	}
	cout << endl << endl;
}
AC::AC(int *a, int n) {
	firstnode = new chain;
	firstnode->element = a[0];
	firstnode->next = new chain;
	chain* currentnode = firstnode->next;
	for (int i = 1; i < n; i++) {
		currentnode->element = a[i];
		if (i < n - 1) {
			currentnode->next = new chain;
			currentnode = currentnode->next;
		}
		else {
			currentnode->next = NULL;
		}
	}
}
void RS(chain*node){
	if (node->next != NULL)
		RS(node->next);
	cout << node->element << "\t";
}
void AC::showreverse() {
	cout << "���������������" << endl << endl;
	chain * currentnode = firstnode;
		RS(currentnode);
		cout << endl << endl;
}
void AC::inserthead(int newelement) {
	chain * temp = new chain;
	temp->element = newelement;
	temp->next = firstnode;
	firstnode = temp;
}
int main() {
	int n;
	cout << "�����һ��������" << endl;
	cin >> n;
	cout << "����" << n << "������" << endl;
	int * a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << "����ڶ�������" << endl << endl;
	cout << "����ڶ���������" << endl << endl;
	int n2;
	cin >> n2;
	cout << "����" << n2 << "������" << endl;
	int * b = new int[n2];
	for (int i = 0; i < n2; i++) {
		cin >> b[i];
	}
	cout << endl;
	AC test(a, n);
	test.getsecondchain(b, n2);
	test.show();
	test.showreverse();
	cout << "�Ա��ײ���Ԫ��100" << endl << endl;
	test.inserthead(100);
	test.show();
	cout << "�Ա��ײ���Ԫ��500" << endl << endl;
	test.inserthead(500);
	test.show();
	cout << "ɾ����"<<3+1<<"��Ԫ��" << endl << endl;
	test.erase(3);
	test.show();
	cout << "ɾ����"<<0+1<<"��Ԫ��" << endl << endl;
	test.erase(0);
	test.show();
	cout << "�����Ƿ�����999" << endl;
	cout << test.search(999) << endl << endl;
	cout << "�����Ƿ�����300" << endl;
	cout << test.search(300) << endl << endl;
	cout << "��������ϲ�" << endl << endl;
	test.merge();
	system("pause");
	return 0;
}