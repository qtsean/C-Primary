#pragma once
#include"iostream"
#include"cstdlib"
#include"stree.h"
using namespace std;

template<class T>
struct node
{
	T key;
	node* left;
	node* right;
};
template<class T>
class slaytree :public stree<T>
{
private:
	node * root;
public:
	slaytree();
	node* insert(T v);
	node* newnode();
	node* find(T v);
	node* merge(node*, node*);
};
template<class T>
node<T>* slaytree<T>::merge(node<T>* a, node<T>* b)
{

}

template<class T>
node<T>* slaytree<T>::find(T v)
{

}

template<class T>
node<T>* slaytree<T>::newnode()
{
	node<T>* a = new node;
	a->left = NULL;
	a->right = NULL;
	return a;
}

template<class T>
slaytree<T>::slaytree()
{
	root = NULL;
}

template<class T>
node<T>* slaytree<T>::insert(T v)
{
	if (root == NULL)
	{
		root = newnode();
		root->key = v;
	}
	else
	{
		node<T>* current = root;
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
					break;
				}
			}
			if (v == current->key)
			{
				cout << "不能有相同值" << endl;
				break;
			}
		}
	}
}