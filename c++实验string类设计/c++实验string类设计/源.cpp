#include<iostream>
#include<cstdlib>
using namespace std;

class String
{
private:
	char* text;
	int length;
public:
	String(char*);
	void cat(String a, String b);
	void copy(String a, String b);
	int cmp(String a, String b);
	char* gettext();
	int getlength();
	char* find(String a, int n);
	char* getname();
	char* getcatlog();
	void merge(String a, String b);
};

String::String(char* a)
{
	text = new char[1000];
	for (int i = 0; i < 1000; i++)
	{
		text[i] = '\0';
	}
	for (int i = 0; a[i] != '\0'; i++)
	{
		text[i] = a[i];
	}
	getlength();
}

char* String::gettext()
{
	return text;
}


void String::copy(String x, String y)		//把内容从y复制到x
{
	char*a = x.gettext();
	char*b = y.gettext();
	int i = 0;
	while (b[i] != '\0')
	{
		a[i] = b[i];
		i++;
	}
	a[i] = '\0';
	getlength();
}

void String::cat(String x, String y)		//把y连接在x后
{
	int i = 0;
	char*a = x.gettext();
	char*b = y.gettext();
	while (a[i] != '\0')
	{
		i++;
	}
	int j = 0;
	while (b[j] != '\0')
	{
		a[i] = b[j];
		i++;
		j++;
	}
	a[i] = '\0';
	getlength();
}

int String::cmp(String x, String y)			//比较x和y字符串中的所有元素，如果都相同返回0，不同返回1
{
	char*a = x.gettext();
	char*b = y.gettext();
	int i = 0;
	while (a[i] != '\0' || b[i] != '\0')
	{
		if (a[i] == '\0'&&b[i] != '\0')
		{
			return 1;
		}
		if (a[i] != '\0'&&b[i] == '\0')
		{
			return 1;
		}
		if (a[i] != b[i])
		{
			return 1;
		}
	}
	return 0;
}

int String::getlength()
{
	int i = 0;
	while (text[i] != '\0')
	{
		i++;
	}
	length = i;
	return i;
}

char* String::find(String x, int n)
{
	char*a = x.gettext();
	if (n > length)
	{
		cout << "大于字符串长度" << endl;
		return NULL;
	}
	return &a[n];
}

char*String::getcatlog()
{
	char *catlog = new char[1000];
	for (int i = 0; i < 1000; i++)
	{
		catlog[i] = '\0';
	}
	char* a = getname();
	int i = 0;
	while (&text[i] != a)
	{
		catlog[i] = text[i];
		i++;
	}
	catlog[i] = '\0';
	return catlog;
}

char* String::getname()
{
	int i = length - 1;
	while (text[i] != '\\')
	{
		i--;
	}
	return &text[i + 1];
}

void String::merge(String x, String y)
{
	int i = x.getlength() - 1;
	if (x.gettext()[i] == '\\') {
		 cat(x, y);
	}
	else
	{
		x.gettext()[i + 1] = '\\';
		x.gettext()[i + 2] = '\0';
		cat(x, y);
	}
}

int main()
{
	cout << "输入原始的文件路径：" << endl;
	char a[1000];
	cin >> a;
	String test1(a);
	cout << "长度为： " << test1.getlength() << endl;
	cout <<"文件名为： "<< test1.getname() << endl;
	cout << "文件路径为： " << test1.getcatlog() << endl;
	cout << "输入要替换的文件目录:" << endl;
	char b[1000];
	cin >> b;
	String test2(b);
	String test3(test1.getname());
	test3.cat(test2, test3);
	cout << "输入替换后的文件名： " << test2.gettext() << endl;
	cout << "输入文件目录： " << endl;
	cin >> a;
	String test4(a);
	cout << "输入文件名： " << endl;
	cin >> b;
	String test5(b);
	test4.merge(test4, test5);
	cout << test4.gettext() << endl;
	system("pause");
	return 0;
}