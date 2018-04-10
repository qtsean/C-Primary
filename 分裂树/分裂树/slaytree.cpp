#pragma once
#include"iostream"
#include"cstdlib"
//#include"stree.h"
#include"Queue"
#include"list"
#define posilchild(p) ((p)->left ? (p)->left->horizontal_position : (p)->horizontal_position)
#define posirchild(p) ((p)->right ? (p)->right->horizontal_position : (p)->horizontal_position)
#define INF 127  


using namespace std;

class DisplayInfo
{
public:
	int level;
	int pos;        //结点在屏幕中的绝对位置  
	bool enter;
	int spaceNum;
};

template<class T>
struct node
{
	T key;
	node* left;
	node* right;
	node* parent;
	int distance_to_root;
	int horizontal_position;
};
//template<class T>
//void printTree(node<T> root);
template<class T>
class slaytree/* :public stree<T>*/
{
private:
	node<T> * root;
	int size;
public:
	slaytree();
	void insert(T v);
	node<T>* newnode();
	node<T> *find(T v);
	void updatedistancetoroot(node<T>* x);
	void calculateposition();
	node<T>* succ(node<T>* x);
	void display();
	void erase(node<T>*);
	int getheight(node<T>* current);
	node<T>* getroot();
	void nprint();
	void rotate(node<T>* current);
};
template<class T>
void slaytree<T>::rotate(node<T>* current)
{
	while (current->parent != NULL)
	{

		if (current->parent->parent == NULL && current == current->parent->left)
		{
			node<T>* q = current;
			node<T>* p = current->parent;
			node<T>* a = current->left;
			node<T>* b = current->right;
			node<T>* c = current->parent->right;
			q->right = p;
			p->parent = q;
			p->left = b;
			if(b)
			b->parent = p;
			q->parent = NULL;
			return;
		}
		if (current->parent->parent == NULL && current == current->parent->right)
		{
			node<T>* q = current;
			node<T>* p = current->parent;
			node<T>* a = current->left;
			node<T>* b = current->right;
			node<T>* c = current->parent->left;
			q->parent = NULL;
			p->right = a;
			if(a)
			a->parent = p;
			q->left = p;
			p->parent = q;
			return;
		}
		node<T>* q = current;
		node<T>* p = current->parent;
		node<T>* gp = current->parent->parent;
		node<T>* gpp = gp->parent;
		if (q == p->left&&p == gp->left)
		{
			node<T>* a = q->left;
			node<T>* b = q->right;
			node<T>* c = p->right;
			node<T>* d = gp->right;
			q->right = p;
			p->parent = q;
			p->left = b;
			if(b)
			b->parent = p;
			p->right = gp;
			gp->parent = p;
			gp->left = c;
			if(c)
			c->parent = gp;
			q->parent = gpp;
			if (gpp != NULL && gp == gpp->right)
			{
				gpp->right = q;
			}
			if (gpp != NULL && gp == gpp->left)
			{
				gpp->left = q;
			}
			continue;
		}
		else if (q == p->right&&p == gp->left)
		{
			node<T>* a = p->left;
			node<T>* b = q->left;
			node<T>* c = q->right;
			node<T>* d = gp->right;
			q->left = p;
			p->parent = q;
			q->right = gp;
			gp->parent = q;
			p->right = b;
			if(b)
			b->parent = p;
			gp->left = c;
			if(c)
			c->parent = gp;
			q->parent = gpp;
			if (gpp != NULL && gp == gpp->right)
			{
				gpp->right = q;
			}
			if (gpp != NULL && gp == gpp->left)
			{
				gpp->left = q;
			}
			continue;
		}
		else if (q == p->right&&p == gp->right)
		{
			node<T>* a = q->right;
			node<T>* b = q->left;
			node<T>* c = p->left;
			node<T>* d = gp->left;
			q->left = p;
			p->parent = q;
			p->left = gp;
			gp->parent = p;
			p->right = b;
			if(b)
			b->parent = p;
			gp->right = c;
			if(c)
			c->parent = gp;
			q->parent = gpp;
			if (gpp != NULL && gp == gpp->right)
			{
				gpp->right = q;
			}
			if (gpp != NULL && gp == gpp->left)
			{
				gpp->left = q;
			}
			continue;
		}
		else if (q == p->left&&p == gp->right)
		{
			node<T>* a = p->right;
			node<T>* b = q->right;
			node<T>* c = q->left;
			node<T>* d = gp->left;
			q->left = gp;
			gp->parent = q;
			q->right = p;
			p->parent = q;
			gp->right = c;
			if(c)
			c->parent = gp;
			p->left = b;
			if(b)
			b->parent = p;
			q->parent = gpp;
			if (gpp != NULL && gp == gpp->right)
			{
				gpp->right = q;
			}
			if (gpp != NULL && gp == gpp->left)
			{
				gpp->left = q;
			}
			continue;
		}
	}
}
template<class T>
void slaytree<T>::nprint()
{
	int i;
	list<node<T>*>Q;
	list<DisplayInfo>QI;
	int screenWidth = 128;
	int dataWidth = 2;
	DisplayInfo info;    //将插入队列的结点的打印信息  
	DisplayInfo preInfo; //队尾的结点的打印信息  
	node<T> *curNode;       //队列当前取出的结点  
	DisplayInfo curInfo; //队列当前取出的结点的打印信息  
	if (!root)
	{
		cout << "Tree is empty !" << endl;
		return;
	}
	cout << "Nature Display Tree:" << endl;
	Q.push_back(root);
	info.level = 1;
	info.enter = true;
	info.spaceNum = screenWidth >> info.level;
	info.pos = info.spaceNum;
	QI.push_back(info);
	preInfo = info;
	while (Q.size())
	{
		curNode = Q.front();
		Q.pop_front();
		curInfo = QI.front();
		if (curInfo.enter)
			cout << endl << endl;
		for (i = 0; i<curInfo.spaceNum; i++)
			cout<<"-";
		cout << curNode->key;
		QI.pop_front();
		if (curNode->left)
		{
			Q.push_back(curNode->left);
			info.level = curInfo.level + 1;
			info.pos = curInfo.pos - (screenWidth >> info.level);
			if (info.level>preInfo.level)
			{
				info.enter = true;
				info.spaceNum = info.pos;
			}
			else
			{
				info.enter = false;
				info.spaceNum = info.pos - preInfo.pos;
			}
			info.spaceNum -= dataWidth;
			QI.push_back(info);
			preInfo = info;

		}
		if (curNode->right)
		{
			Q.push_back(curNode->right);
			info.level = curInfo.level + 1;
			info.pos = curInfo.pos + (screenWidth >> info.level);
			if (info.level>preInfo.level)
			{
				info.enter = true;
				info.spaceNum = info.pos;
			}
			else
			{
				info.enter = false;
				info.spaceNum = info.pos - preInfo.pos;
			}
			info.spaceNum -= dataWidth;
			QI.push_back(info);
			preInfo = info;
		}

	}
	cout << endl;
}
template<class T>
node<T>* slaytree<T>::getroot()
{
	return root;
}
template<class T>
int slaytree<T>::getheight(node<T>* current)
{
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
template<class T>
void slaytree<T>::display()
{
	calculateposition();
	queue<node<T>*> q;
	node<T>* x = root;
	q.push(x);
	int nowheight = 0;
	int lastheight = 0;
	int levelcount = 0;
	int i = 0;
	while (!q.empty())
	{
		x = q.front();
		q.pop();

		long long int tmpposi;
		if (x)
		{
			nowheight = x->distance_to_root;

			if (nowheight != lastheight)
			{
				lastheight = nowheight;
				cout << endl;
				levelcount = 0;
			}



			for (i = levelcount; i < posilchild(x); ++i)
			{
				printf(" ");
			}

			int firstprint = 1;
			for (; i < x->horizontal_position; ++i)
			{
				if (firstprint)
				{
					printf("_");
					firstprint = 0;
				}
				else
					printf("_");
			}

			tmpposi = cout.tellp();
			cout << x->key;
			long long int tellpppp = cout.tellp() - tmpposi;
			levelcount += (int)(tellpppp);

			levelcount += x->horizontal_position - levelcount;

			for (i = levelcount; i < posirchild(x); ++i)
			{
				if (i == posirchild(x) - 1)
					printf("_");
				else
					printf("_");
			}
			levelcount = i;


		}

		if (x && x->left) q.push(x->left);
		if (x && x->right) q.push(x->right);
	}


	cout << endl << endl;
}
template<class T>
void slaytree<T>::calculateposition()
{
	node<T>* x = root;
		updatedistancetoroot(x);
	
	int count = 0;
	node<T>* p = root;
	while (p->left != NULL)
		p = p->left;
	while (p != NULL)
	{
		p->horizontal_position = ++count;
		p->horizontal_position *= 6;    //水平位置放缩4倍 命令行显示时结点之间的空隙4个字符
		if (size == 1)
		{
			p = NULL;
		}
		else 
		{
			p = succ(p);
		}
	}
}
template<class T>
node<T>* slaytree<T>::succ(node<T>* x)
{
	node<T>* p = x;
	if (p->right != NULL)
	{
		p = p->right;
		while (p->left != NULL)
			p = p->left;
		return p;
	}
	else
	{
		p = x;
		if (p->parent != NULL && p->parent->left == p)
		{
			p = p->parent;
			return p;
		}
		
	}
	return NULL;
}
template<class T>
void slaytree<T>::updatedistancetoroot(node<T>* x)
{
	if (!x) return;
	int i = 0;
	node<T>* p = x;
	while (p != NULL)
	{
		p = p->parent;
		++i;
	}
	x->distance_to_root = i - 1;
	queue<node<T>*> q;

	q.push(x);
	while (!q.empty())
	{
		x = q.front();
		q.pop();
		if (x && x->parent)
			x->distance_to_root = x->parent->distance_to_root + 1;
		if (x->left) q.push(x->left);
		if (x->right) q.push(x->right);
	}
}

template<class T>
node<T>* slaytree<T>::find(T v)
{
	node<T>* thenode;
	node<T>* current = root;
	bool found = 0;
	while (1)
	{
		if (v == current->key)
		{
			found = 1;
			thenode = current;
			break;
		}
		if (v < current->key)
		{
			if (current->left != NULL)
			{
				current = current->left;
				continue;
			}
			else
			{
				cout << "NO SUCH VALUE" << endl;
				break;
			}
		}
		if (v > current->key)
		{
			if (current->right != NULL)
			{
				current = current->right;
				continue;
			}
			else
			{
				cout << "NO SUCH VALUE" << endl;
				break;
			}
		}
	}
	if (found == 1)
	{
		rotate(thenode);
	}
}

template<class T>
node<T>* slaytree<T>::newnode()
{
	node<T>* a = new node<T>;
	a->left = NULL;
	a->right = NULL;
	a->parent = NULL;
	a->distance_to_root = 0;
	a->horizontal_position = 0;
	return a;
}

template<class T>
slaytree<T>::slaytree()
{
	root = NULL;
	size = 0;
}

template<class T>
void slaytree<T>::insert(T v)
{
	node<T>* current;
	if (root == NULL)
	{
		root = newnode();
		root->key = v;
		size++;
		current = root;
	}
	else
	{
		current = root;
		while (true)
		{
			if (v < current->key)
			{
				if (current->left != NULL)
				{
					current = current->left;
				}
				else
				{
					current->left = newnode();
					current->left->key = v;
					current->left->parent = current;
					size++;
					current = current->left;
					break;
				}
			}
			if (v > current->key)
			{
				if (current->right != NULL)
				{
					current = current->right;
				}
				else
				{
					current->right = newnode();
					current->right->key = v;
					current->right->parent = current;
					size++;
					current = current->right;
					break;
				}
			}
			if (v == current->key)
			{
				cout << "不能有相同值" << endl;
				return;
			}
		}
	}
	rotate(current);
	root = current;
}


int main()
{
	slaytree<char> test;
	while (1)
	{
		char a;
		cin >> a;
		test.insert(a);
		test.nprint();
	}
	system("pause");
	return 0;
}
