#include<iostream>
#include<stdlib.h>
using namespace std;
struct chain {
	int element;
	chain * next = NULL;
};
class AC {
public:class LinkIterator
{
	/*
	private:
	chain * ltr;
	*/
public:
	chain * ltr;
	LinkIterator(chain * ltr)
	{
		this->ltr = ltr;
	}
	bool operator !=(LinkIterator& it)
	{
		return this->ltr != it.ltr;
	}
	bool operator <=(LinkIterator& it) {
		return this->ltr->element <= it.ltr->element;
	}
	bool operator >=(LinkIterator& it) {
		return this->ltr->element >= it.ltr->element;
	}
	void operator ++(int)
	{
		this->ltr = ltr->next;
		//return this->ltr;
	}
	LinkIterator operator --(int) {
		return this->ltr->next;
	}
	chain operator *()
	{
		return *ltr;
	}
};
private:
	chain * firstnode;
	chain * secondchain;
public:
	AC(int *a, int n);
	chain * gethead();
	void inserthead(int newelement);
	void showreverse();
	void show();
	void erase(int index);
	int search(int number);
	void getsecondchain(int *a, int n);
	void merge();
	chain* sort(chain * sorted);
	void lrshow(AC::LinkIterator it1);
};
void AC::lrshow(AC::LinkIterator it1) {
	if (it1.ltr->next != NULL) {
		lrshow(it1--);
	}
	cout << it1.ltr->element << "\t";
}
void RS(chain*node) {
	if (node->next != NULL)
		RS(node->next);
	cout << node->element << "\t";
}
void AC::showreverse() {
	cout << "反序输出链表如下" << endl << endl;
	chain * currentnode = firstnode;
	RS(currentnode);
	cout << endl << endl;
}
chain * AC::gethead() {
	return firstnode;
}
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
		AC::LinkIterator ts = temp;
		while (ts--.ltr != NULL) {
			if (ts.ltr->element > ts.ltr->next->element) {
				changed = 1;
				int swap = ts.ltr->element;
				ts.ltr->element = ts.ltr->next->element;
				ts.ltr->next->element = swap;
			}
			ts++;
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
	cout << "有序链表一如下" << endl << endl;
	LinkIterator o1 = currentnode1;
	while (o1.ltr != NULL) {
		cout << o1.ltr->element << "\t";
		o1++;
	}
	cout << endl << endl;
	cout << "有序链表二如下" << endl << endl;
	LinkIterator o2 = currentnode2;
	while (o2.ltr != NULL) {
		cout << o2.ltr->element << "\t";
		o2++;
	}
	cout << endl << endl;
	chain * temp = new chain;
	chain * temphead = temp;
	LinkIterator m1 = currentnode1;
	LinkIterator m2 = currentnode2;
	while (m1.ltr != NULL && m2.ltr != NULL) {
		if (m1 <= m2) {
			temp->element = m1.ltr->element;
			temp->next = new chain;
			temp = temp->next;
			m1++;
		}
		else {
			temp->element = m2.ltr->element;
			temp->next = new chain;
			temp = temp->next;
			m2++;
		}
	}
	if (m1.ltr == NULL) {
		while (m2.ltr != NULL) {
			temp->element = m2.ltr->element;

			if (m2.ltr->next != NULL) {
				temp->next = new chain;
				temp = temp->next;
			}
			m2++;
		}
	}
	else {
		while (m1.ltr != NULL) {
			temp->element = m1.ltr->element;

			if (m1.ltr->next != NULL) {
				temp->next = new chain;
				temp = temp->next;
			}
			m1++;

		}
	}
	cout << "合并后的链表如下" << endl << endl;
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
	for (int i = 0; currentnode != NULL; i++, currentnode = currentnode->next) {
		if (currentnode->element == number) {
			return i + 1;
		}
	}
	return 0;
}
void AC::erase(int index) {
	chain * currentnode = firstnode;
	chain * lastnode = NULL;
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
	cout << "正序输出链表如下" << endl << endl;
	chain* currentnode = firstnode;
	while (currentnode != NULL) {
		cout << currentnode->element << "\t";
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

void AC::inserthead(int newelement) {
	chain * temp = new chain;
	temp->element = newelement;
	temp->next = firstnode;
	firstnode = temp;
}
int main() {
	int n;
	cout << "输入第一个链表长度" << endl;
	cin >> n;
	cout << "输入" << n << "个数字" << endl;
	int * a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << "输入第二个链表" << endl << endl;
	cout << "输入第二个链表长度" << endl << endl;
	int n2;
	cin >> n2;
	cout << "输入" << n2 << "个数字" << endl;
	int * b = new int[n2];
	for (int i = 0; i < n2; i++) {
		cin >> b[i];
	}
	cout << endl;
	AC test(a, n);
	test.getsecondchain(b, n2);
	test.show();
	test.showreverse();
	AC::LinkIterator it1 = test.gethead();
	cout << "迭代器反序输出：" << endl << endl;
	test.lrshow(it1);
	cout << endl;
	cout << "自表首插入元素100" << endl << endl;
	test.inserthead(100);
	test.show();
	cout << "自表首插入元素500" << endl << endl;
	test.inserthead(500);
	test.show();
	cout << "删除第" << 3 + 1 << "个元素" << endl << endl;
	test.erase(3);
	test.show();
	cout << "删除第" << 0 + 1 << "个元素" << endl << endl;
	test.erase(0);
	test.show();
	cout << "查找是否有数999" << endl;
	cout << test.search(999) << endl << endl;
	cout << "查找是否有数300" << endl;
	cout << test.search(300) << endl << endl;
	cout << "有序链表合并" << endl << endl;
	test.merge();

	system("pause");
	return 0;
}