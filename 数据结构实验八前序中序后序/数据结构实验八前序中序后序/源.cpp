#include <string>   
#include <iostream>   
using namespace std;
typedef struct BtNode
{
	char data;											 
	struct BtNode * lchild;  
	struct BtNode * rchild;  
}BtNode, *BiTree;
void CreateBiTree(BiTree & t, string pre, string in)	//t�Ǹ��ڵ㣬preΪǰ��inΪ����
{
	if (pre.length() == 0)
	{
		t = NULL;
		return;
	}
	char current = pre[0];								//����ÿ�εݹ鶼ȡ��һ��������ֵ��ͬ
	int index = in.find(current);						//�������������е�λ��   
	string left_in = in.substr(0, index);				//���ӵ���������   
	string right_in = in.substr(index + 1);				//�Һ��ӵ���������   
	int left_length = left_in.length();					//���ӵĳ���   
	int right_length = right_in.length();				//�Һ��ӵĳ���   
	string left_pre = pre.substr(1, left_length);		//���ӵ�ǰ������   
	string right_pre = pre.substr(1 + left_length);		//�Һ��ӵ�ǰ������   

	t = (BiTree)malloc(sizeof(BtNode));
	if (t != NULL)
	{
		t->data = current;
		CreateBiTree(t->lchild, left_pre, left_in);		//�ݹ鴴������   
		CreateBiTree(t->rchild, right_pre, right_in);	//�ݹ鴴���Һ���   
	}
}
void post(BiTree & t)
{
	if (t != NULL)
	{
		post(t->lchild);
		post(t->rchild);
		cout << t->data;
	}
}
int main()
{
	BiTree t;
	string pre = "ABCDEFG";
	string in = "CBEDAFG";
	CreateBiTree(t, pre, in);
	post(t);
	system("PAUSE");
	return 0;
}