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


void String::copy(String x, String y)		//�����ݴ�y���Ƶ�x
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

void String::cat(String x, String y)		//��y������x��
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

int String::cmp(String x, String y)			//�Ƚ�x��y�ַ����е�����Ԫ�أ��������ͬ����0����ͬ����1
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
		cout << "�����ַ�������" << endl;
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
	cout << "����ԭʼ���ļ�·����" << endl;
	char a[1000];
	cin >> a;
	String test1(a);
	cout << "����Ϊ�� " << test1.getlength() << endl;
	cout <<"�ļ���Ϊ�� "<< test1.getname() << endl;
	cout << "�ļ�·��Ϊ�� " << test1.getcatlog() << endl;
	cout << "����Ҫ�滻���ļ�Ŀ¼:" << endl;
	char b[1000];
	cin >> b;
	String test2(b);
	String test3(test1.getname());
	test3.cat(test2, test3);
	cout << "�����滻����ļ����� " << test2.gettext() << endl;
	cout << "�����ļ�Ŀ¼�� " << endl;
	cin >> a;
	String test4(a);
	cout << "�����ļ����� " << endl;
	cin >> b;
	String test5(b);
	test4.merge(test4, test5);
	cout << test4.gettext() << endl;
	system("pause");
	return 0;
}