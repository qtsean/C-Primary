#include<iostream>
#include<cstdlib>
#include<fstream>
#include<iomanip>
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
	String();
	void create(char*);
	int ivkgetlength();
	char* ivkcat(String &);
	void ivkcopy(String &);
	char* gettext();
	int ivkcmp(String&);
	char* ivkgetname();
	char* ivkgetcatlog();
	char* ivkmerge(String&);
};
struct node
{
	String a;
	int num;
};

void String::create(char* a)
{
	int len = getlength(a);
	text = new char[2 * len];
	for (int i = 0; i < 2 * len; i++)
	{
		text[i] = '\0';
	}
	for (int i = 0; a[i] != '\0'; i++)
	{
		text[i] = a[i];
	}
}

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
	int length = getlength(this->text);
	return length;
}

String::String(char* a)
{
	int len = getlength(a);
	text = new char[2 * len];
	for (int i = 0; i < 2 * len; i++)
	{
		text[i] = '\0';
	}
	for (int i = 0; a[i] != '\0'; i++)
	{
		text[i] = a[i];
	}
}

String::String()
{

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

int cmp(char*a, char*b)
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
	int i = getlength(text) - 1;
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

void sta(pair<String ,int>*x, char*y,int &number)
{
	for (int i = 0; i < number; i++)
	{
		if (!cmp(x[i].first.gettext(), y))
		{
			x[i].second++;
			return;
		}
	}
	x[number].first.create(y);
	number++;
}

void sort(pair<String, int>*nd,int count)
{
	int times = 0;
	while (times < count)
	{
		bool change = false;
		for (int i = 0; i < count - 1; i++)
		{
			if (nd[i].second < nd[i + 1].second)
			{
				swap(nd[i], nd[i + 1]);
				change = true;
			}
		}
		if (change == false)
			break;
		times++;
	}
}

int main()
{
	pair<String,int> nd[1000];
	for (int i = 0; i < 1000; i++)
	{
		nd[i].second = 1;
	}
	int count = 0;
	ifstream fin("E36.txt");
	char temp;
	char *tem = new char[50];
	for (int i = 0; i < 50; i++)
	{
		tem[i] = '\0';
	}
	int start = 0;
	int i = 0;
	while (1)
	{
		int bk = 0;
		if (!fin.get(temp))
		{
			bk = 1;
			temp = ' ';
		}
		if ((temp <= 90 && temp >= 65))
		{
			temp += 32;
		}
		if (temp >= 97 && temp <= 122)
		{
			start = 1;
			tem[i] = temp;
			i++;
		}
		else
		{
			if (start == 1&&i>=2) 
			{
				sta(nd, tem, count);
				delete tem;
				tem = new char[50];
				for (int i = 0; i < 50; i++)
				{
					tem[i] = '\0';
				}
			}
			start = 0;
			i = 0;
		}
		if (bk == 1)
			break;
	}
	sort(nd, count);
	for (int i = 0; i < 100; i++)
	{
		cout<<left<<setw(20)<< nd[i].first.gettext()  <<left<<setw(4)<< nd[i].second << " times" << endl;
	}
	system("pause");
	return 0;
}