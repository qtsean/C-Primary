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
	int start;			//�ݹ鸳ֵ�ĵ�һ��ѭ��
	int mark;			//��¼�Ƿ������Զ�����־
	btnode* root;
public:
	bttree();
	btnode* create();
	void pre(btnode* current);
	void in(btnode* current);
	void post(btnode* current);
	void level(btnode* current);
	void createque();
	void push(btnode* current);
	void pop();
	int countnode(btnode* current);
	int height(btnode* current);
	bool que_empty();
	btnode* gettail();
	btnode* getnode();
};
int bttree::height(btnode* current) {
	int hl = 0;
	int hr = 0;
	if (current == NULL)
		return 0;
	hl = height(current->left);
	hr = height(current->right);
	return hl + hr + 1;
}
int bttree::countnode(btnode* current) {
	int cl = 0;
	int cr = 0;
	if (current == NULL)
		return 0;
	cl = countnode(current->left);
	cr = countnode(current->right);
	return cl + cr + 1;
}
btnode* bttree::gettail() {
	return queue[size];
}
bool bttree::que_empty() {
	if (-1 == size) {
		return 0;
	}
	else {
		return 1;
	}
}
void bttree::level(btnode* current) {
	push(current);
	while (que_empty()) {
		cout << current->element << endl;
		if (current->left != NULL) {
			push(current->left);
		}
		if (current->right != NULL) {
			push(current->right);
		}
		pop();
		current = gettail();
	}
}
void bttree::pop() {
	if (-1 == size) {
		cout << "�����ѿ�" << endl;
	}
	else {
		size--;
	}
}
void bttree::push(btnode* current) {
	if (size == -1) {
		size++;
		queue[0] = current;
	}
	else {
		for (int i = size; i >= 0; i--) {
			queue[i + 1] = queue[i];
		}
		queue[0] = current;
		size++;
	}
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
	cout << "����������,����#���Զ����ʣ��սڵ�" << endl;
	test.create();
	cout << "ǰ�����" << endl;
	test.pre(test.getnode());
	cout << "�������" << endl;
	test.in(test.getnode());
	cout << "�������" << endl;
	test.post(test.getnode());
	cout << "��α���" << endl;
	test.createque();
	test.level(test.getnode());
	cout << "����ڵ�����" << endl;
	cout << "�ڵ�����Ϊ�� " << test.countnode(test.getnode()) << endl;
	cout << "����߶�" << endl;
	cout << "�߶�Ϊ�� " << test.height(test.getnode()) << endl;

	system("pause");
	return 0;
}