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
		cout << "��Ч��" << endl;
		return;
	}
	if (current.n == 0)
	{
		cout << "���Ϊ " << 0 << endl;
		return;
	}
	else
	{
		cout << "���Ϊ " << current.n << "/" << current.d << endl;
		return;
	}
}
int main()
{
	number result;
	cout << "�Է�����ʽ���������������������ӣ���ĸ�����ӣ���ĸ��˳��Ҫ���ĸ��Ϊ0" << endl;
	int an, ad, bn, bd;
	cin >> an;
	cin >> ad;
	cin >> bn;
	cin >> bd;
	cout << "������������������ֱ�Ϊ " << an << "/" << ad << " �� " << bn << "/" << bd << endl;
	Rational test(an, ad, bn, bd);
	cout << "�ӷ�" << endl;
	result = test.add();
	showresult(result);
	cout << "����" << endl;
	result = test.sub();
	showresult(result);
	cout << "�˷�" << endl;
	result = test.mul();
	showresult(result);
	cout << "����" << endl;
	result = test.dvd();
	showresult(result);
	system("pause");
	return 0;

}