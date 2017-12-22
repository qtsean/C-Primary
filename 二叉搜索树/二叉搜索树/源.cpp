#include<iostream>
#include<stdlib.h>
using namespace std;
struct btnode {
	int element;						//储存的元素
	btnode* left;						//左子树
	btnode* right;						//右子树
};
class bst {
private:
	
public:
	void pre(btnode* current);			//前序输出
	bst(int* a);						//构造函数
	btnode* root;						//根节点
};
bst::bst(int* a) {
	root = new btnode;					//创建根节点
	root->element = a[0];				//第一个数字储存在根节点
	root->left = NULL;					//每创建一个节点，把左右子树初始化为NULL
	root->right = NULL;
	btnode* current = root;				//设置current从根节点开始
	int i = 1;
	while (a[i] != -1) {				//-1为数组的结束标志
		current = root;					//每次循环都从根节点开始
		while (1) {
			if (a[i] < current->element&&current->left != NULL) {		//如果数字小于当前节点且左子树不为NULL
				current = current->left;								//当前节点变为此节点的左子树
			}
			if (a[i] > current->element&&current->right != NULL) {		//如果数字大于当前节点且右子树不为NULL
				current = current->right;								//当前节点变为此节点的右子树
			}
			if (a[i] < current->element&&current->left == NULL) {		//如果数字小于当前节点且左子树为NULL
				current->left = new btnode;								//创建左子树且储存这个数字
				current->left->element = a[i];
				current->left->left = NULL;
				current->left->right = NULL;
				i++;
				break;
			}
			if (a[i] > current->element&&current->right == NULL) {		//如果数字大于当前节点且右子树为NULL
				current->right = new btnode;							//创建右子树且储存这个数字
				current->right->element = a[i];
				current->right->left = NULL;
				current->right->right = NULL;
				i++;
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
	int a[10] = { 3,7,1,6,9,4,5,8,2,-1 };
	bst test(a);
	test.pre(test.root);
	system("pause");
	return 0;
}