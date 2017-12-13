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
	int que_size;		//目前队列中的元素数	
	int size;			//总节点数量
	btnode* root;
	btnode** que;		//队列中存指针
public:
	maxheap(const int *a,int _size);	
	void que_push(btnode*a);		//往队列中插入元素
	btnode* que_gettail();			//得到队首元素
	bool que_empty();				//判断队列是否空
	void que_pop();					//弹出
	void que_delete();				//重置队列
	void level(btnode*current);		//层次遍历，看输出结果用
	btnode* getnode();				//得到根节点
	void initialize();				//初始化最大堆
	void insert(int ins);			//往最大堆中插入元素
	void erase();					//弹出最大堆的根节点
	void sort();					//对最大堆排序
};
void maxheap::sort() {
	while (root->left!= NULL) {		//若左节点不为空，则弹出根节点，并重新排序
		cout << root->element << endl;
		erase();
	}
	cout << root->element << endl;
}
void maxheap::erase() {
	que_delete();					//先重置队列

	//对堆进行层次遍历，找出最后一个节点的元素
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
	root->element = current->element;	//把最后元素的值赋给根节点
	current->element = -1;				//把最后一个节点的值变为-1，作为标记
	que_delete();
	current = root;
	que_push(current);

	//再遍历一遍，找到子节点的值为-1的父节点，把该子树设置为NULL
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
	//重新初始化最大堆
	initialize();
}
void maxheap::insert(int ins) {
	delete que;
	size++;
	que = new btnode*[size];
	btnode* current = root;
	que_push(current);

	//找到最后一个节点，在该节点后创建一个新节点，存放插入的值
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
	//重新初始化最大堆
	initialize();
}
void maxheap::initialize() {
	while (1) {
		int change = 0;
		que_delete();
		btnode *current = root;
		que_push(current);
		while (que_empty()) {
			if (current->left!=NULL&&current->element < current->left->element || current->right!=NULL&&current->element < current->right->element) {	//如果子节点不为空且值大于父节点，则交换
				//通过层次遍历实现
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

	//第一次遍历，创建需要的节点个数
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

	//第二次遍历，赋值
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