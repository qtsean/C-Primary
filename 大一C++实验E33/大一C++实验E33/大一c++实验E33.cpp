#include<cstdlib>
#include<iostream>
using namespace std;

class Rectangle
{
private:
	pair<int ,int> leftUp;
	int length;
	int width;
public:
	Rectangle(int,int,int,int);
	int area();
	int equalInArea(Rectangle a, Rectangle b);
	void changeSize(int, int);
	void move(int, int);
	Rectangle overlap(Rectangle, Rectangle);
	int witherOverlap(Rectangle*, Rectangle*);
	void showleftUp();
	void showlength_width();
};
Rectangle::Rectangle(int x,int y,int l, int w)
{
	leftUp.first = x;
	leftUp.second = y;
	length = l;
	width = w;
}
int Rectangle::area()
{
	return length * width;
}
int Rectangle::equalInArea(Rectangle a, Rectangle b)
{
	int areaA;
	int areaB;
	areaA = a.area();
	areaB = b.area();
	if (areaA > areaB)
		return 1;
	if (areaA == areaB)
		return 0;
	if (areaA < areaB)
		return -1;
}
void Rectangle::changeSize(int x, int y)
{
	length = length + x;
	if (length <= 0)
	{
		cout << "�����겻��С��0" << endl;
		return;
	}
	width = width + y;
	if (width <= 0)
	{
		cout << "�����겻��С��0" << endl;
		return;
	}
}
void Rectangle::move(int x, int y)
{
	leftUp.first += x;
	leftUp.second += y;
}
void Rectangle::showlength_width()
{
	cout << "���� " << length << endl;
	cout << "�� "<<width << endl;
}
int Rectangle::witherOverlap(Rectangle *a, Rectangle *b)
{
	if (b->leftUp.first > a->leftUp.first&&b->leftUp.first < a->leftUp.first + a->length&&b->leftUp.second<a->leftUp.second&&b->leftUp.second>a->leftUp.second - a->width)
	{
		return 1;
	}
	if (a->leftUp.first > b->leftUp.first&&a->leftUp.first < b->leftUp.first + b->length&&a->leftUp.second<b->leftUp.second&&a->leftUp.second>b->leftUp.second - b->width)
	{
		return 2;
	}
	return 0;
}
Rectangle Rectangle::overlap(Rectangle a, Rectangle b)
{
	int e = witherOverlap(&a, &b);
	int cl;
	int cw;
	pair<int, int> node;
	if (e == 1)
	{
		node.first = b.leftUp.first;
		node.second = b.leftUp.second;
		if (b.leftUp.first + b.length > a.leftUp.first + a.length)
		{
			cl = a.leftUp.first + a.length - b.leftUp.first;
		}
		else
		{
			cl = b.length;
		}
		if (b.leftUp.second - b.width < a.leftUp.second - a.width)
		{
			cw = b.leftUp.second - (a.leftUp.second - a.width);
		}
		else
		{
			cw = b.width;
		}
	}
	else if (e == 2)
	{
		node.first = a.leftUp.first;
		node.second = a.leftUp.second;
		if (a.leftUp.first + a.length > b.leftUp.first + b.length)
		{
			cl = b.leftUp.first + b.length - a.leftUp.first;
		}
		else
		{
			cl = a.length;
		}
		if (a.leftUp.second - a.width < b.leftUp.second - b.width)
		{
			cw = a.leftUp.second - (b.leftUp.second - b.width);
		}
		else
		{
			cw = a.width;
		}
	}
	if (e == 0)
	{
		cout << "���ص�" << endl;
		node.first = 0;
		node.second = 0;
		cl = 0;
		cw = 0;
	}
	Rectangle c(node.first, node.second, cl, cw);
	return c;
}
void Rectangle::showleftUp()
{
	cout << "(" << leftUp.first << "," << leftUp.second << ")" << endl;
}

int main()
{
	cout << "����1Ϊ���϶�������Ϊ1��1����3����4�ľ���" << endl;
	Rectangle test1(1, 1, 3, 4);
	cout << "����2Ϊ���϶���Ϊ3��0����3��2�ľ���" << endl;
	Rectangle test2(3, 0, 3, 2);
	cout << "�������1�����" << endl;
	cout << test1.area() << endl;
	cout << "�ж����������Ƿ���ȣ�1Ϊǰ�ߴ��ں��ߣ�0Ϊ��ȣ�-1Ϊ���ߴ���ǰ��" << endl;
	cout << test1.equalInArea(test1, test2) << endl;
	cout << "�ı����1�Ĵ�С��ʹ���������1" << endl;
	test1.changeSize(1, 1);
	cout << "�ı������Ϊ��" << test1.area() << endl;
	cout << "�ƶ�һ�����Σ���һ������Ϊ�������λ�������ڶ����������������λ����" << endl;
	cout << "ʹ����1�����ƶ�1��λ,��ʾ�ƶ������϶��������" << endl;
	test1.move(0, 1);
	test1.showleftUp();
	cout << "�����������ص����ֵľ���" << endl;
	Rectangle c = test1.overlap(test1, test2);
	cout << "��ʾ������ε����ϽǶ������꣬�Լ�����" << endl;
	c.showleftUp();
	c.showlength_width();
	system("pause");
	return 0;
}