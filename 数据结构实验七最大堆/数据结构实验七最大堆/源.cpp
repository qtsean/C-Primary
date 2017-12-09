#include<iostream>
#include<stdlib.h>
using namespace std;
struct btnode {
	int element;
	btnode* left;
	btnode* right;
};
class maxheap {
private:
	int que_size;
	int size;
	btnode* root;
	btnode** que;
public:
	maxheap(const int *a,int _size);
	void que_push(btnode*a);
	btnode* que_gettail();
	bool que_empty();
	void que_pop();
	void que_delete();
	void level(btnode*current);
	btnode* getnode();
	void initialize();
	void insert(int ins);
	void erase();
	void sort();
};
void maxheap::sort() {
	while (root->left!= NULL) {
		cout << root->element << endl;
		erase();
	}
	cout << root->element << endl;
}
void maxheap::erase() {
	que_delete();
	btnode* current = root;
	que_push(current);
	while (que_empty()) {
		if (current->left != NULL) {
			que_push(current->left);
		}
		if (current->right != NULL) {
			que_push(current->right);
		}
		que_pop();
		current = que_gettail();
		if (que_size == 0 && current->left == NULL&&current->right == NULL)
			break;
	}
	root->element = current->element;
	current->element = -1;
	que_delete();
	current = root;
	que_push(current);
	while (que_empty()) {
		if (current->left != NULL) {
			if (current->left->element == -1) {
				current->left = NULL;
				size--;
				break;
			}
			que_push(current->left);
		}
		if (current->right != NULL) {
			if (current->right->element == -1) {
				current->right = NULL;
				size--;
				break;
			}
			que_push(current->right);
		}
		que_pop();
		current = que_gettail();
	}
	initialize();
}
void maxheap::insert(int ins) {
	delete que;
	size++;
	que = new btnode*[size];
	btnode* current = root;
	que_push(current);
	while (1) {
		if (current->left != NULL) {
			que_push(current->left);
		}
		if (current->right != NULL) {
			que_push(current->right);
		}
		if (current->left == NULL || current->right == NULL) {
			if (current->left == NULL) {
				current->left = new btnode;
				current->left->left = NULL;
				current->left->right = NULL;
				current->left->element = ins;
				break;
			}
			else {
				current->right = new btnode;
				current->right->left = NULL;
				current->right->right = NULL;
				current->right->element = ins;
				break;
			}
		}
		que_pop();
		current = que_gettail();
	}
	initialize();
}
void maxheap::initialize() {
	while (1) {
		int change = 0;
		que_delete();
		btnode *current = root;
		que_push(current);
		while (que_empty()) {
			if (current->left!=NULL&&current->element < current->left->element || current->right!=NULL&&current->element < current->right->element) {
				
				if (current->right != NULL) {
					if (current->left != NULL&&current->left->element > current->right->element) {
						int temp = current->left->element;
						current->left->element = current->element;
						current->element = temp;
						change = 1;
						break;
					}
					if (current->left != NULL&&current->left->element < current->right->element) {
						int temp = current->right->element;
						current->right->element = current->element;
						current->element = temp;
						change = 1;
						break;
					}
				}

				else {
						int temp = current->left->element;
						current->left->element = current->element;
						current->element = temp;
						change = 1;
						break;
				}
				/*
				else {
					int temp = current->right->element;
					current->right->element = current->element;
					current->element = temp;
					change = 1;
					break;
				}*/
			}
			if (current->left != NULL) {
				que_push(current->left);
			}
			if (current->right != NULL) {
				que_push(current->right);
			}
			que_pop();
			current = que_gettail();
		}
		if (0 == change)
			break;
	}
}
btnode* maxheap::getnode() {
	return root;
}
void maxheap::level(btnode* current) {
	que_push(current);
	while (que_empty()) {
		cout << current->element << endl;
		if (current->left != NULL) {
			que_push(current->left);
		}
		if (current->right != NULL) {
			que_push(current->right);
		}
		que_pop();
		current = que_gettail();
	}
}
void maxheap::que_delete() {
	que_size = -1;
}
void maxheap::que_pop() {
	if (-1 == que_size) {
		cout << "队列空" << endl;
	}
	else {
		que_size--;
	}
}
bool maxheap::que_empty() {
	if (-1 == que_size) {
		return 0;
	}
	else {
		return 1;
	}
}
btnode* maxheap::que_gettail() {
	return que[que_size];
}
void maxheap::que_push(btnode*a) {
	if (que_size == -1) {
		que[0] = a;
		que_size++;
	}
	else{
		for (int i = que_size; i >= 0; i--) {
			que[i + 1] = que[i];
		}
		que[0] = a;
		que_size++;
	}
}
maxheap::maxheap(const int *a,int _size) {
	que_size = -1;
	size = _size;
	que = new btnode*[size];
	root = new btnode;
	btnode *current = root;
	int i = 0;
	que_push(current);
	while (1) {
		if (i < size-1) {
			current->left = new btnode;
			current->left->left = NULL;
			current->left->right = NULL;
			que_push(current->left);
			i++;
		}
		else
			break;
		if (i < size) {
			current->right = new btnode;
			current->right->left = NULL;
			current->right->right = NULL;
			que_push(current->right);
			i++;
		}
		else
			break;
		que_pop();
		current = que_gettail();
	}
	que_delete();
	i = 0;
	current = root;
	que_push(current);
	while (que_empty()) {
		current->element = a[i];
		i++;
		if (current->left != NULL) {
			que_push(current->left);
		}
		if (current->right != NULL) {
			que_push(current->right);
		}
		que_pop();
		current = que_gettail();
	}
}
int main() {
	int a[10] = { 3,2,1,6,5,4,9,8,7,-1 };
	maxheap test(a, 9);
	cout << "初始化前： " << endl;
	test.level(test.getnode());
	test.initialize();
	cout << "初始化后： " << endl;
	test.level(test.getnode());
	test.insert(11);
	cout << "插入11后：" << endl;
	test.level(test.getnode());
	cout << "删除堆顶后： " << endl;
	test.erase();
	test.level(test.getnode());
	cout << "对剩下的堆进行排序： " << endl;
	test.sort();
	//test.level(test.getnode());
	system("pause");
	return 0;
}