#include<iostream>
#include<stdlib.h>
using namespace std;
struct btnode {
	int element;
	btnode* left;
	btnode* right;
};
class bst {
private:
	
public:
	void pre(btnode* current);
	bst(int* a);
	btnode* root;
};
bst::bst(int* a) {
	root = new btnode;
	root->element = a[0];
	root->left = NULL;
	root->right = NULL;
	btnode* current = root;
	int i = 1;
	while (a[i] != -1) {
		current = root;
		while (1) {
			if (a[i] < current->element&&current->left != NULL) {
				current = current->left;
			}
			if (a[i] > current->element&&current->right != NULL) {
				current = current->right;
			}
			if (a[i] < current->element&&current->left == NULL) {
				current->left = new btnode;
				current->left->element = a[i];
				current->left->left = NULL;
				current->left->right = NULL;
				i++;
				break;
			}
			if (a[i] > current->element&&current->right == NULL) {
				current->right = new btnode;
				current->right->element = a[i];
				current->right->left = NULL;
				current->right->right = NULL;
				i++;
				break;
			}
		}
	}
}
void bst::pre(btnode* current) {
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