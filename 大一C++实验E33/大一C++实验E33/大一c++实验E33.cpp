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
		cout << "横坐标不能小于0" << endl;
		return;
	}
	width = width + y;
	if (width <= 0)
	{
		cout << "纵坐标不能小于0" << endl;
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
	cout << "长： " << length << endl;
	cout << "宽： "<<width << endl;
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
		cout << "无重叠" << endl;
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
	cout << "矩形1为左上顶点坐标为1，1，长3，宽4的矩形" << endl;
	Rectangle test1(1, 1, 3, 4);
	cout << "矩形2为左上顶点为3，0，长3宽2的矩形" << endl;
	Rectangle test2(3, 0, 3, 2);
	cout << "计算矩形1的面积" << endl;
	cout << test1.area() << endl;
	cout << "判断两个矩形是否相等，1为前者大于后者，0为相等，-1为后者大于前者" << endl;
	cout << test1.equalInArea(test1, test2) << endl;
	cout << "改变矩形1的大小，使长宽各增加1" << endl;
	test1.changeSize(1, 1);
	cout << "改变后的面积为：" << test1.area() << endl;
	cout << "移动一个矩形，第一个参数为横坐标的位移量，第二个参数是纵坐标的位移量" << endl;
	cout << "使矩形1向上移动1单位,显示移动后左上顶点的坐标" << endl;
	test1.move(0, 1);
	test1.showleftUp();
	cout << "求两个矩阵重叠部分的矩形" << endl;
	Rectangle c = test1.overlap(test1, test2);
	cout << "显示这个矩形的左上角顶点坐标，以及长宽" << endl;
	c.showleftUp();
	c.showlength_width();
	system("pause");
	return 0;
}