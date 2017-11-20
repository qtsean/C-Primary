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
		if (current->element.first == index) {				//因为已用search判断过，所以肯定存在
			return current->element.second;
		}
		current = current->next;
	}
}
int lh::search(int index) {
	int j = index%divisor;									//如果地址为空，则不存在
	if (dic[j] == NULL) {
		return -1;
	}
	else if (dic[j]->element.first == index) {				//地址不为空且索引相同，则返回位置
		return j;
	}
	else {
		node* current = dic[j]->next;						//地址不为空，且索引值不同，则依次向后移，直到到链表尾或找到需要的索引
		while (current != NULL) {
			if (current->element.first == index) {
				return j;
			}
			current = current->next;
		}
		return -1;											//遍历链表后还是没有则不存在
	}
}
lh::lh(pair<int, int>*a) {
	dic = new node*[divisor];
	for (int i = 0; i < divisor; i++) {
		dic[i] = NULL;
	}
	for (int i = 0; i < dsize; i++) {
		if (dic[a[i].first%divisor]== NULL) {				//若为空，则新建节点并插入
			dic[a[i].first%divisor] = new node;
			dic[a[i].first%divisor]->element = a[i];
			dic[a[i].first%divisor]->used = 1;
		}
		else {
			if (dic[a[i].first%divisor]->next == NULL) {			//若不为空，则向后新建链表并插入
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
	cout << "输出的字典:" << endl;
	for (int i = 0; i < divisor; i++) {
		node *current = dic[i];
		while (current != NULL) {
			cout <<"位置："<<i<<"\t"<< "索引：" << current->element.first << "\t" << "值：" << current->element.second << endl;
			current = current->next;
		}
	}
}
int main() {
	srand((unsigned)time(NULL));
	pair<int, int>*a = new pair<int, int>[dsize];
	cout << "输入的字典：" << endl;
	for (int i = 0; i < dsize; i++) {
		a[i].first = rand();
		a[i].second = a[i].first+1;
		cout << "索引：" << a[i].first << "\t" << "值：" << a[i].second << endl;
	}
	lh test1(a);
	cout << "输入需要寻找的索引值" << endl;
	int index;
	cin >> index;
	int d = test1.search(index);
	if (d == -1) {
		cout << "该索引不存在" << endl;
	}
	else {
		cout << "该索引对应的值为：" << test1.find(index) << endl;
	}
	system("pause");
	return 0;
}