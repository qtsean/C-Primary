#include<iostream>
#include<cstdlib>
using namespace std;

int length(char* r)
{
	int i = 0;
	while (r[i] != '\0')
	{
		i++;
	}
	return i;
}
char* getname(char* r)
{
	char* name = new char[1000];
	for (int i = 0; i < 1000; i++)
	{
		name[i] = '\0';
	}
	int i = 0;
	int index = 0;
	while (r[i] != '\0')
	{
		if (r[i] == '\\')
		{
			index = i;
		}
		i++;
	}
	index++;
	i = 0;
	while (r[index] != '\0')
	{
		name[i] = r[index];
		i++;
		index++;
	}
	return name;
}
char* getcat(char* r)
{
	char* cat;
	cat = new char[1000];
	for (int i = 0; i < 1000; i++)
	{
		cat[i] = '\0';
	}
	int i = 0;
	int index = 0;
	while (r[i] != '\0')
	{
		if (r[i] == '\\')
		{
			index = i;
		}
		i++;
	}
	for (int i = 0; i <= index; i++)
	{
		cat[i] = r[i];
	}
	return cat;
}
char* changecat(char* r,char* newcat)
{
	int i = 0;
	char* newroute = new char[1000];
	for (int i = 0; i < 1000; i++)
	{
		newroute[i] = '\0';
	}
	while (newcat[i] != '\0')
	{
		newroute[i] = newcat[i];
		i++;
	}
	char* name = getname(r);
	int j = 0;
	while (name[j] != '\0')
	{
		newroute[i] = name[j];
		i++;
		j++;
	}
	return newroute;
}

char* merge(char* file, char* name)
{
	char* route = new char[1000];
	for (int i = 0; i < 1000; i++)
	{
		route[i] = '\0';
	}
	int i = 0;
	int length = 0;
	while (file[i] != '\0')
	{
		i++;
	}
	length = i;
	if (file[i - 1] != '\\')
	{
		file[i] = '\\';
		file[i + 1] = '\0';
		length = i + 1;
	}
	for (int j = 0; j < length; j++) 
	{
		route[j] = file[j];
	}
	for (int j = 0; name[j]!='\0'; j++)
	{
		route[length] = name[j];
		length++;
	}
	return route;
}

int main()
{
	cout << "����һ��windows��ʽ���ļ�·��" << endl;
	char* r = new char[1000];
	char* name = new char[1000];
	char* catalog = new char[1000];
	char* newroute = new char[1000];
	//char r[1000] = "C:\ProgramFiles\data.txt";
	cin >> r;
	cout << "·������Ϊ�� " << length(r) << endl;
	name = getname(r);
	cout << "�ļ���Ϊ�� " << endl;
	cout << name << endl;
	cout << "�ļ�Ŀ¼Ϊ�� " << endl;
	catalog = getcat(r);
	cout << catalog << endl;
	cout << "������Ҫ�滻���ļ�Ŀ¼�� " << endl;
	char* newcat = new char[1000];
	cin >> newcat;
	newroute = changecat(r, newcat);
	cout << "�µ�ַΪ�� " << endl;
	cout << newroute << endl;
	cout << "�����ļ�Ŀ¼: " << endl;
	char* directory = new char[1000];
	cin >> directory;
	cout << "�����ļ���: " << endl;
	char* fname = new char[1000];
	cin >> fname;
	cout << "���ӣ� " << endl;
	newroute = merge(directory, fname);
	cout << newroute << endl;
	system("pause");
	return 0;
}