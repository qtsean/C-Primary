#pragma once
using namespace std;

template<class T>
class stree
{
public:
	virtual ~stree() {};
	virtual void insert(T) = 0;
	virtual node<T>* find(T) = 0;
	virtual void erase(T) = 0;
};
