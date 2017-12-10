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
	void pre(btnode* current);			//前序
	void in(btnode* current);			//中序	
	void post(btnode* current);			//后序
	void level(btnode* current);		//层次
	void createque();					//创建层次遍历用的表
	void push(btnode* current);
	void pop();
	int countnode(btnode* current);		//统计所有节点
	int height(btnode* current);		//只计较多一侧的节点数
	bool que_empty();					//判断队列是否空
	btnode* gettail();					//队尾元素
	btnode* getnode();
};
int bttree::height(btnode* current) {
	int hl = 0;
	int hr = 0;
	if (current == NULL)
		return 0;
	hl = height(current->left);
	hr = height(current->right);
	if (hl >= hr)						//返回较多一侧的节点数
		return hl + 1;
	else
		return hr + 1;
}
int bttree::countnode(btnode* current) {
	int cl = 0;
	int cr = 0;
	if (current == NULL)
		return 0;
	cl = countnode(current->left);
	cr = countnode(current->right);
	return cl + cr + 1;					//返回两侧的节点和
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
	while (que_empty()) {				//把队末元素的子节点入队，再把该节点出队
		cout << current->element << endl;
		if (current->left != NULL) {
			push(current->left);
		}
		if (current->right != NULL) {
			push(current->right);
		}
		pop();
		current = gettail();			//把指针指向队末元素
	}
}
void bttree::pop() {
	if (-1 == size) {
		cout << "队列已空" << endl;
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
		input = '0';			//若为0表示该节点已经是叶节点
	}
	if (input == '0') {
		current = NULL;
		if (0 == start) {
			root = current;
			start = 1;
		}
	}
	else if (input == '#') {	//输入井号表示已输入完全，剩余的0自动填充
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
	cout << "前序遍历" << endl;
	test.pre(test.getnode());
	cout << "中序遍历" << endl;
	test.in(test.getnode());
	cout << "后序遍历" << endl;
	test.post(test.getnode());
	cout << "层次遍历" << endl;
	test.createque();
	test.level(test.getnode());
	cout << "计算节点数量" << endl;
	cout << "节点数量为： " << test.countnode(test.getnode()) << endl;
	cout << "计算高度" << endl;
	cout << "高度为： " << test.height(test.getnode()) << endl;

	system("pause");
	return 0;
}