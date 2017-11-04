#include<iostream>
using namespace std;
template<class T>
class TwoStack
{
public:
	TwoStack()
		:_a(NULL)
		, _top1(0)
		, _top2(0)
		, _capacity(0)
	{
		_CheckCapacity();
	}
	~TwoStack()
	{
		if (_a)
			delete[] _a;
	}
	void Push1(const T& d)
	{
		_CheckCapacity();
		_a[_top1++] = d;
	}
	void Push2(const T& d)
	{
		_CheckCapacity();
		_a[_top2--] = d;
	}
	void Pop1()
	{
		if (_top1 > 0)
			--_top1;
	}
	void Pop2()
	{
		if (_top2 < _capacity - 1)
			_top2++;
	}
	size_t Size1()
	{
		return _top1;
	}
	size_t Size2()
	{
		return _capacity - 1 - _top2;
	}
	bool Empty1()
	{
		return _top1 == 0;
	}
	bool Empty2()
	{
		return _top2 == _capacity - 1;
	}
	T& Top1()
	{
		if (_top1>0)
		{
			return _a[_top1 - 1];
		}
	}
	T& Top2()
	{
		if (_top2 < _capacity - 1)
			return _a[_top2 + 1];
	}

private:
	void _CheckCapacity()
	{
		if (_a == NULL)
		{
			_capacity += 3;
			_a = new T[_capacity];
			_top2 = _capacity - 1;
			return;
		}
		if (_top1 == _top2)
		{
			size_t OldCapacity = _capacity;
			_capacity = _capacity * 2;
			T* tmp = new T[_capacity];
			for (size_t i = 0; i < _top1; i++)
			{
				tmp[i] = _a[i];
			}
			for (size_t j = OldCapacity - 1, i = _capacity - 1; j>_top2; j--, i--)
			{
				tmp[i] = _a[j];
			}
			delete[] _a;
			_a = tmp;
			_top2 += _capacity / 2;
		}
	}

private:
	T* _a;
	size_t _top1;
	size_t _top2;
	size_t _capacity;
};
int main() {
	TwoStack<int> s;
	s.Push1(1);
	s.Push1(2);
	s.Push1(3);
	s.Push1(4);
	s.Push1(5);
	s.Push2(1);
	s.Push2(2);
	s.Push2(3);
	s.Push2(4);
	s.Push2(5);
	cout << "s1:" << s.Size1() << endl;;
	cout << "s2:" << s.Size2() << endl;
	while (!s.Empty1())
	{
		cout << s.Top1() << endl;
		s.Pop1();
	}
	while (!s.Empty2())
	{
		cout << s.Top2() << endl;
		s.Pop2();
	}
	system("pause");
	return 0;
}