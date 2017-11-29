#include<iostream>
#include<stdlib.h>
using namespace std;
struct btnode {
	char element;
	btnode* left;
	btnode* right;
};
class bttree {
private:
	btnode** queue;
	int size;
	int start;			//递归赋值的第一次循环
	int mark;			//记录是否输入自动填充标志
	btnode* root;
public:
	bttree();
	btnode* create();
	void pre(btnode* current);
	void in(btnode* current);
	void post(btnode* current);
	void createque();
	void push(btnode* current);
	void pop();
	btnode* getnode();
};
void bttree::pop() {
	if (-1 == size) {
		cout << "队列已空" << endl;
	}
	else {
		size--;
	}
}
void bttree::push(btnode* current) {
	size++;
	queue[size] = current;
}
void bttree::createque() {
	size = -1;
	queue = new btnode*[1000];
	for (int i = 0; i < 1000; i++) {
		queue[i] = NULL;
	}

}
void bttree::post(btnode* current) {
	if (current != NULL) {
		post(current->left);
		post(current->right);
		cout << current->element << endl;
	}
}
void bttree::in(btnode* current) {
	if (current != NULL) {
		in(current->left);
		cout << current->element << endl;
		in(current->right);
	}
}
btnode* bttree::getnode() {
	return root;
}
bttree::bttree() {
	root = new btnode;
	mark = 0;
	start = 0;
}
void bttree::pre(btnode* current) {
	if (current != NULL) {
		cout << current->element << endl;
		pre(current->left);
		pre(current->right);
	}
}
btnode* bttree::create() {
	btnode* current;
	char input;
	if (mark == 0) {
		cin >> input;
	}
	else {
		input = '0';
	}
	if (input == '0') {
		current = NULL;
		if (0 == start) {
			root = current;
			start = 1;
		}
	}
	else if (input == '#') {
		mark = 1;
		current = NULL;
		if (0 == start) {
			root = current;
			start = 1;
		}
	}
	else {
		current = new btnode;
		if (0 == start) {
			root = current;
			start = 1;
		}
		current->element = input;
		current->left = create();
		current->right = create();
	}
	return current;
}
int main() {
	bttree test;
	cout << "创建二叉树,输入#号自动填充剩余空节点" << endl;
	test.create();
	test.pre(test.getnode());
	test.in(test.getnode());
	test.post(test.getnode());
	test.createque();

	system("pause");
	return 0;
}