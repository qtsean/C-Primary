#include<iostream>
#include<stdlib.h>
#include<time.h>
#define M 500
using namespace std;
struct btnode {
	int element;						//�����Ԫ��
	btnode* left;						//������
	btnode* right;						//������
};
class bst {
private:
	
public:
	int size;
	void pre(btnode* current);			//ǰ�����
	bst(int* a,int n);						//���캯��
	btnode* root;						//���ڵ�
	void deleteMax();							//ɾ�����
	void insert(int element);
};
void bst::insert(int x) {
	btnode* current = root;
	while (1) {
		if (x < current->element&&current->left != NULL) {		//�������С�ڵ�ǰ�ڵ�����������ΪNULL
			current = current->left;								//��ǰ�ڵ��Ϊ�˽ڵ��������
		}
		if (x > current->element&&current->right != NULL) {		//������ִ��ڵ�ǰ�ڵ�����������ΪNULL
			current = current->right;								//��ǰ�ڵ��Ϊ�˽ڵ��������
		}
		if (x < current->element&&current->left == NULL) {		//�������С�ڵ�ǰ�ڵ���������ΪNULL
			current->left = new btnode;								//�����������Ҵ����������
			current->left->element = x;
			current->left->left = NULL;
			current->left->right = NULL;
			break;
		}
		if (x > current->element&&current->right == NULL) {		//������ִ��ڵ�ǰ�ڵ���������ΪNULL
			current->right = new btnode;							//�����������Ҵ����������
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
	root = new btnode;		//�������ڵ�
	cout << "a[" << 0 << "]= " << a[0] << endl;
	root->element = a[0];				//��һ�����ִ����ڸ��ڵ�
	root->left = NULL;					//ÿ����һ���ڵ㣬������������ʼ��ΪNULL
	root->right = NULL;
	btnode* current = root;				//����current�Ӹ��ڵ㿪ʼ
	int i = 1;
	while (a[i]!=-1) {				//-1Ϊ����Ľ�����־
		current = root;				//ÿ��ѭ�����Ӹ��ڵ㿪ʼ
		cout << "success " << i << endl;
		while (1) {
			if (a[i] <= current->element&&current->left != NULL) {		//�������С�ڵ�ǰ�ڵ�����������ΪNULL
				current = current->left;								//��ǰ�ڵ��Ϊ�˽ڵ��������
			}
			if (a[i] > current->element&&current->right != NULL) {		//������ִ��ڵ�ǰ�ڵ�����������ΪNULL
				current = current->right;								//��ǰ�ڵ��Ϊ�˽ڵ��������
			}
			if (a[i] <= current->element&&current->left == NULL) {		//�������С�ڵ�ǰ�ڵ���������ΪNULL
				current->left = new btnode;								//�����������Ҵ����������
				current->left->element = a[i];
				current->left->left = NULL;
				current->left->right = NULL;
				i++;
				cout << "a["<<i<<"]= " << a[i] << endl;
				break;
			}
			if (a[i] > current->element&&current->right == NULL) {		//������ִ��ڵ�ǰ�ڵ���������ΪNULL
				current->right = new btnode;							//�����������Ҵ����������
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
void bst::pre(btnode* current) {										//ǰ������������������
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