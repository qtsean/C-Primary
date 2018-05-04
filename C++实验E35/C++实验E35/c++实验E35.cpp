#include<iostream>
#include<cstdlib>
using namespace std;

int getlength(char*);
char* cat(char*, char*);
char* copy(char*);
int cmp(char*, char*);
char* getname(char*);
char* getcatlog(char*);
char* merge(char*, char*);

class String
{
private:
	char* text;
public:
	char* operator+(String &x)
	{
		return ivkcat(x);
	}
	int operator==(String &x)
	{
		return ivkcmp(x);
	}
	String(char*);
	int ivkgetlength();
	char* ivkcat(String &);
	void ivkcopy(String &);
	char* gettext();
	int ivkcmp(String&);
	char* ivkgetname();
	char* ivkgetcatlog();
	char* ivkmerge(String&);
};

char* String::ivkmerge(String&x)
{
	return merge(this->text, x.gettext());
	
}

char* String::ivkgetcatlog()
{
	return getcatlog(this->text);
}

char* String::ivkgetname()
{
	return getname(this->text);
}

int String::ivkcmp(String &x)
{
	return cmp(this->text, x.gettext());
}

void String::ivkcopy(String& x)
{
	text = copy(x.gettext());
}

char* String::gettext()
{
	return text;
}

char* String::ivkcat(String &x)
{
	return cat(this->text, x.gettext());
}

int String::ivkgetlength()
{
	int length=getlength(this->text);
	return length;
}

String::String(char* a)
{
	int len = getlength(a);
	text = new char[2 * len];
	for (int i = 0; i < 2*len; i++)
	{
		text[i] = '\0';
	}
	for (int i = 0; a[i] != '\0'; i++)
	{
		text[i] = a[i];
	}
}

int getlength(char* text)
{
	int i = 0;
	while (text[i] != '\0')
	{
		i++;
	}
	return i;
}

char* cat(char* x, char * y)
{
	int len = getlength(x) + getlength(y);
	char *temp = new char[2 * len];
	int i = 0;
	while (x[i] != '\0')
	{
		temp[i] = x[i];
		i++;
	}
	int j = 0;
	while (y[j] != '\0')
	{
		temp[i] = y[j];
		i++;
		j++;
	}
	temp[i] = '\0';
	return temp;
}
char* copy(char* a)
{
	int len = getlength(a);
	char* temp = new char[2 * len];
	for (int i = 0; i < 2 * len; i++)
	{
		temp[i] = '\0';
	}
	for (int i = 0; i < len; i++)
	{
		temp[i] = a[i];
	}
	return temp;
}

int cmp(char*a,char*b)
{
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
		i++;
	}
	return 0;
}

char* getname(char*text)
{
	int j = 0;
	int i = getlength(text) - 1;
	char* temp = new char[i + 1];
	while (text[i] != '\\')
	{
		i--;
	}
	while (text[i] != 0)
	{
		temp[j] = text[i + 1];
		i++;
		j++;
	}
	return temp;
}

char* getcatlog(char*text)
{
	char *catlog = new char[getlength(text)];
	for (int i = 0; i < getlength(text); i++)
	{
		catlog[i] = '\0';
	}
	int i = getlength(text)-1;
	while (text[i] != '\\')
	{
		i--;
	}
	for (int j = 0; j <= i; j++)
	{
		catlog[j] = text[j];
	}
	i = getlength(text) - 1;
	i++;
	catlog[i] = '\0';
	return catlog;
}

char* merge(char*x, char*y)
{
	int i = getlength(x) - 1;
	if (x[i] == '\\')
	{
		return cat(x, y);
	}
	else
	{
		x[i + 1] = '\\';
		x[i + 2] = '\0';
		return cat(x, y);
	}
}

int main()
{
	char a[100];
	char b[100];
	cout << "输入原始的文件路径：" << endl;
	cin >> a;
	String test1(a);
	cout << "长度为： " << test1.ivkgetlength() << endl;
	cout << "文件名为： " << test1.ivkgetname() << endl;
//	delete test1.ivkgetname();
	cout << "文件路径为： " << test1.ivkgetcatlog() << endl;
	//delete test1.ivkgetcatlog();
	cout << "输入要替换的文件目录:" << endl;
	cin >> b;
	String test2(b);
	String test3(test1.ivkgetname());
	cout << "输出替换后的文件名： " << test2 + test3 << endl;			//重载了加号
	//delete(test2 + test3);
	//delete c;
	cout << "输入文件目录： " << endl;
	cin >> a;
	String test4(a);
	cout << "输入文件名： " << endl;
	cin >> b;
	String test5(b);
	cout << test4.ivkmerge(test5) << endl;
	//delete test4.ivkmerge(test5);
	cout << "比较两个字符串是否相同，1表示不同，0表示相同，输入两个字符串：" << endl;
	cin >> a;
	cin >> b;
	String test6(a);
	String test7(b);
	cout <<(test6==test7)<< endl;										//重载了等于
	//cout << test6.ivkcmp(test7) << endl;
	system("pause");
	return 0;
}