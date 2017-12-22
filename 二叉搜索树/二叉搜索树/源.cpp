#include<iostream>
#include<stdlib.h>
using namespace std;
struct btnode {
	int element;						//�����Ԫ��
	btnode* left;						//������
	btnode* right;						//������
};
class bst {
private:
	
public:
	void pre(btnode* current);			//ǰ�����
	bst(int* a);						//���캯��
	btnode* root;						//���ڵ�
};
bst::bst(int* a) {
	root = new btnode;					//�������ڵ�
	root->element = a[0];				//��һ�����ִ����ڸ��ڵ�
	root->left = NULL;					//ÿ����һ���ڵ㣬������������ʼ��ΪNULL
	root->right = NULL;
	btnode* current = root;				//����current�Ӹ��ڵ㿪ʼ
	int i = 1;
	while (a[i] != -1) {				//-1Ϊ����Ľ�����־
		current = root;					//ÿ��ѭ�����Ӹ��ڵ㿪ʼ
		while (1) {
			if (a[i] < current->element&&current->left != NULL) {		//�������С�ڵ�ǰ�ڵ�����������ΪNULL
				current = current->left;								//��ǰ�ڵ��Ϊ�˽ڵ��������
			}
			if (a[i] > current->element&&current->right != NULL) {		//������ִ��ڵ�ǰ�ڵ�����������ΪNULL
				current = current->right;								//��ǰ�ڵ��Ϊ�˽ڵ��������
			}
			if (a[i] < current->element&&current->left == NULL) {		//�������С�ڵ�ǰ�ڵ���������ΪNULL
				current->left = new btnode;								//�����������Ҵ����������
				current->left->element = a[i];
				current->left->left = NULL;
				current->left->right = NULL;
				i++;
				break;
			}
			if (a[i] > current->element&&current->right == NULL) {		//������ִ��ڵ�ǰ�ڵ���������ΪNULL
				current->right = new btnode;							//�����������Ҵ����������
				current->right->element = a[i];
				current->right->left = NULL;
				current->right->right = NULL;
				i++;
				break;
			}
		}
	}
}
void bst::pre(btnode* current) {										//ǰ������������������
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