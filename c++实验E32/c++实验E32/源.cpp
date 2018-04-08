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
private:
	number a;
	number b;
public:
	Rational(int, int, int, int);
	number add();
	number sub();
	number mul();
	number dvd();
	number reduce(number);
};
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
	number result;
	cout << "按分子/分母形式输入，有理数之间用操作符隔开，如1/2+1/3-1/6" << endl;
	char input[1000];
	cin >> input;
	int i = 0;
	stack<number> rtn;
	stack<char> ope;
	while (input[i] != '\0')
	{
		if (rtn.size < 2)
		{
			number current;
			current.n = 0;
			current.d = 0;
			while (input[i] != '/')
			{
				current.n = current.n * 10 + chartoint(input[i]);
				i++;
			}
			i++;
			while (input[i] != '+'&&input[i] != '-'&&input[i]!='\0')
			{
				current.d = current.d * 10 + chartoint(input[i]);
				i++;
			}
			rtn.push(current);
		}
		if(rtn.size==2)
		{
			number second = rtn.pop();
			number first = rtn.pop();
			Rational temp(first.n, first.d, second.n, second.d);
			switch (ope.pop())
			{
			case '+':
				rtn.push(temp.add());
				break;
			case '-':
				rtn.push(temp.sub());
				break;
			}
		}
		if (input[i] != '\0')
		{
			ope.push(input[i]);
			i++;
		}
		else
			break;
	}
	result = rtn.pop();
	cout << "结果为 ： " << result.n << "/" << result.d << endl;
	system("pause");
	return 0;

}