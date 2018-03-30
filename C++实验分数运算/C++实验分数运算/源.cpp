#include<iostream>
#include<cstdlib>
using namespace std;

struct number
{
	int n;				//numerator
	int d;				//denominator
};

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
int main()
{
	number result;
	cout << "以分数形式输入两个有理数，按分子，分母，分子，分母的顺序，要求分母不为0" << endl;
	int an, ad, bn, bd;
	cin >> an;
	cin >> ad;
	cin >> bn;
	cin >> bd;
	cout << "你输入的两个有理数分别为 " << an << "/" << ad << " 和 " << bn << "/" << bd << endl;
	Rational test(an, ad, bn, bd);
	cout << "加法" << endl;
	result = test.add();
	showresult(result);
	cout << "减法" << endl;
	result = test.sub();
	showresult(result);
	cout << "乘法" << endl;
	result = test.mul();
	showresult(result);
	cout << "除法" << endl;
	result = test.dvd();
	showresult(result);
	system("pause");
	return 0;

}