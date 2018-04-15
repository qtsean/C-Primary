#include<iostream>
#include<cstdlib>
using namespace std;

struct number
{
	int n;				//numerator
	int d;				//denominator
};

template<class T>
class stack
{
private:
	T element[1000];

public:
	int size;
	stack();
	void push(T);
	T pop();
};

template<class T>
stack<T>::stack()
{
	size = 0;
}

template<class T>
void stack<T>::push(T a)
{
	element[size] = a;
	size++;
}

template<class T>
T stack<T>::pop()
{
	size--;
	return element[size];
}
class Rational
{
public:
	number operator+(const number b);
	number operator-(const number b);
	number operator/(const number b);
	number operator*(const number b);
	number a;
	number b;
	Rational(int, int, int, int);
	number add();
	number sub();
	number mul();
	number dvd();
	number add1(number, number);
	number sub1(number, number);
	number mul1(number, number);
	number dvd1(number, number);
	number reduce(number);
};
number Rational::operator*(const number c)
{
	return mul1(this->a, c);
}
number Rational::operator/(const number c)
{
	return dvd1(this->a, c);
}
number Rational::operator+(const number c)
{
	return add1(this->a, c);
}
number Rational::operator-(const number c)
{
	return sub1(this->a, c);
}
number Rational::add1(number x,number y)
{
	Rational temp(x.n, x.d, y.n, y.d);
	return temp.add();
}
number Rational::sub1(number x, number y)
{
	Rational temp(x.n, x.d, y.n, y.d);
	return temp.sub();
}
number Rational::dvd1(number x, number y)
{
	Rational temp(x.n, x.d, y.n, y.d);
	return temp.dvd();
}
number Rational::mul1(number x, number y)
{
	Rational temp(x.n, x.d, y.n, y.d);
	return temp.mul();
}
Rational::Rational(int an, int ad, int bn, int bd)
{
	a.n = an;
	a.d = ad;
	b.n = bn;
	b.d = bd;
}
number Rational::add()
{
	number current;
	current.d = a.d*b.d;
	current.n = a.n*b.d + a.d*b.n;
	current = reduce(current);
	return current;
}
number Rational::sub()
{
	number current;
	current.d = a.d*b.d;
	current.n = a.n*b.d - a.d*b.n;
	current = reduce(current);
	return current;
}
number Rational::mul()
{
	number current;
	current.d = a.d*b.d;
	current.n = a.n*b.n;
	current = reduce(current);
	return current;
}
number Rational::dvd()
{
	number current;
	current.d = a.d*b.n;
	current.n = a.n*b.d;
	current = reduce(current);
	return current;
}
number Rational::reduce(number current)
{
	if (current.n > 0)
	{
		for (int i = current.n; i > 1; i--)
		{
			if (current.n%i == 0 && current.d%i == 0)
			{
				current.n = current.n / i;
				current.d = current.d / i;
			}
		}
	}
	else
	{
		current.n = -current.n;
		for (int i = current.n; i > 1; i--)
		{
			if (current.n%i == 0 && current.d%i == 0)
			{
				current.n = current.n / i;
				current.d = current.d / i;
			}
		}
		current.n = -current.n;
	}
	return current;
}
void showresult(number current)
{
	if (current.n != 0 && current.d == 0)
	{
		cout << "无效答案" << endl;
		return;
	}
	if (current.n == 0)
	{
		cout << "结果为 " << 0 << endl;
		return;
	}
	else
	{
		cout << "结果为 " << current.n << "/" << current.d << endl;
		return;
	}
}

int chartoint(char a)
{
	int c = a - 48;
	return c;
}

int main()
{
	Rational test1(3, 8, 4, 15);
	showresult(test1 + test1.b);
	showresult(test1 - test1.b);
	showresult(test1 * test1.b);
	showresult(test1 / test1.b);
	system("pause");
	return 0;

}