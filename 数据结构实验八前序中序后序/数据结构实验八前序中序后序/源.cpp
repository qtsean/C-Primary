#include <string>   
#include <iostream>   
using namespace std;
typedef struct BtNode
{
	char data;											 
	struct BtNode * lchild;  
	struct BtNode * rchild;  
}BtNode, *BiTree;
void CreateBiTree(BiTree & t, string pre, string in)	//t是根节点，pre为前序，in为后序
{
	if (pre.length() == 0)
	{
		t = NULL;
		return;
	}
	char current = pre[0];								//根，每次递归都取第一个，但是值不同
	int index = in.find(current);						//根在中序序列中的位置   
	string left_in = in.substr(0, index);				//左孩子的中序序列   
	string right_in = in.substr(index + 1);				//右孩子的中序序列   
	int left_length = left_in.length();					//左孩子的长度   
	int right_length = right_in.length();				//右孩子的长度   
	string left_pre = pre.substr(1, left_length);		//左孩子的前序序列   
	string right_pre = pre.substr(1 + left_length);		//右孩子的前序序列   

	t = (BiTree)malloc(sizeof(BtNode));
	if (t != NULL)
	{
		t->data = current;
		CreateBiTree(t->lchild, left_pre, left_in);		//递归创建左孩子   
		CreateBiTree(t->rchild, right_pre, right_in);	//递归创建右孩子   
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