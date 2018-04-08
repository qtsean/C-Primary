#pragma once

using namespace std;

template<class T>
class stree
{
public:
	virtual ~stree() {};
	virtual void insert(T) = 0;
	virtual T find(T) = 0;
	virtual erase(T) = 0;
};
