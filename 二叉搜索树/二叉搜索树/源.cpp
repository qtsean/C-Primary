#include<iostream>
#include<stdlib.h>
#include<time.h>
#define M 500
using namespace std;
struct btnode {
	int element;						//储存的元素
	btnode* left;						//左子树
	btnode* right;						//右子树
};
class bst {
private:
	
public:
	int size;
	void pre(btnode* current);			//前序输出
	bst(int* a,int n);						//构造函数
	btnode* root;						//根节点
	void deleteMax();							//删除最大
	void insert(int element);
};
void bst::insert(int x) {
	btnode* current = root;
	while (1) {
		if (x < current->element&&current->left != NULL) {		//如果数字小于当前节点且左子树不为NULL
			current = current->left;								//当前节点变为此节点的左子树
		}
		if (x > current->element&&current->right != NULL) {		//如果数字大于当前节点且右子树不为NULL
			current = current->right;								//当前节点变为此节点的右子树
		}
		if (x < current->element&&current->left == NULL) {		//如果数字小于当前节点且左子树为NULL
			current->left = new btnode;								//创建左子树且储存这个数字
			current->left->element = x;
			current->left->left = NULL;
			current->left->right = NULL;
			break;
		}
		if (x > current->element&&current->right == NULL) {		//如果数字大于当前节点且右子树为NULL
			current->right = new btnode;							//创建右子树且储存这个数字
			current->right->element = x;
			current->right->left = NULL;
			current->right->right = NULL;
			break;
		}
	}
	//size++;
}
void bst::deleteMax() {
	btnode * current = root;
	btnode * last = current;
	if (current->right == NULL) {
		root = current->left;
		delete current;
	//	size--;
		return;
	}
	if(current->right != NULL) {
		while (1) {
			if (current->right != NULL) {
				last = current;
				current = current->right;
			}
			if (current->right == NULL) {
				if (current->left == NULL) {
					last->right = NULL;
					delete current;
					break;
				}
				if (current->left != NULL) {
					last->right = current->left;
					delete current;
					break;
				}
			}
		}
	}
	//size--;
}
bst::bst(int* a,int n) {
	size = n;
	root = new btnode;		//创建根节点
	cout << "a[" << 0 << "]= " << a[0] << endl;
	root->element = a[0];				//第一个数字储存在根节点
	root->left = NULL;					//每创建一个节点，把左右子树初始化为NULL
	root->right = NULL;
	btnode* current = root;				//设置current从根节点开始
	int i = 1;
	while (a[i]!=-1) {				//-1为数组的结束标志
		current = root;				//每次循环都从根节点开始
		cout << "success " << i << endl;
		while (1) {
			if (a[i] <= current->element&&current->left != NULL) {		//如果数字小于当前节点且左子树不为NULL
				current = current->left;								//当前节点变为此节点的左子树
			}
			if (a[i] > current->element&&current->right != NULL) {		//如果数字大于当前节点且右子树不为NULL
				current = current->right;								//当前节点变为此节点的右子树
			}
			if (a[i] <= current->element&&current->left == NULL) {		//如果数字小于当前节点且左子树为NULL
				current->left = new btnode;								//创建左子树且储存这个数字
				current->left->element = a[i];
				current->left->left = NULL;
				current->left->right = NULL;
				i++;
				cout << "a["<<i<<"]= " << a[i] << endl;
				break;
			}
			if (a[i] > current->element&&current->right == NULL) {		//如果数字大于当前节点且右子树为NULL
				current->right = new btnode;							//创建右子树且储存这个数字
				current->right->element = a[i];
				current->right->left = NULL;
				current->right->right = NULL;
				i++;
				cout << "a[" << i << "]= " << a[i] << endl;
				break;
			}
		}
	}
}
void bst::pre(btnode* current) {										//前序输出这个搜索二叉树
	if (current != NULL) {
		cout << current->element << endl;
		pre(current->left);
		pre(current->right);
	}
}
int main() {
	srand((unsigned)time(NULL));
	clock_t start;
	clock_t end;
	int n;
	cin >> n;
	int *a = new int[n+1];
	for (int i = 0; i < n; i++) {
		a[i] = rand();
	}
	int *b = new int[M];
	for(int i = 0; i < M; i++) {
		b[i] = rand();
		//cout << rand();
		//cout << "b[" << i << "]= " << b[i] << endl;
	}
	a[n] = -1;
	start = clock();
	bst test(a,n);
	for (int i = 0; i < M; i++) {
		if (i % 2 == 0) 
		{
			test.insert(b[i]);
			//cout << "current:" << endl;
			//test.pre(test.root);
			//cout << "size: " << test.size << endl;
		}
		else
		{
			test.deleteMax();
			//cout << "current:" << endl;
			//test.pre(test.root);
			//cout << "size: " << test.size << endl;
		}
		cout << i << endl;
	}
	cout << "check" << endl;
	end = clock();
	cout << "time: " << end - start << endl;
	/*test.pre(test.root);
	cout << endl;
	test.deleteMax();
	test.pre(test.root);
	cout << endl;
	test.insert(100);
	test.pre(test.root);*/
	system("pause");
	return 0;
}