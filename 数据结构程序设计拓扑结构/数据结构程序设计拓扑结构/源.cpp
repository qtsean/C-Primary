#include<iostream>
#include<cstdlib>
using namespace std;
class topo
{
private:
	pair<int, int>* course;
	int *f;
	int *s;
	int csize;
	int fsize;
	int ssize;
	int notlast;
public:
	topo();
	void insert(pair<int, int>);
	void del(pair<int, int>);
	void delf(int);
	void sort();
	void compare(int*, int*);
	void reset();
	int* delr(int*,int);
	bool exist(int,int ,int *);
};
topo::topo()
{
	course = new pair<int, int>[100];
	f = new int[100];
	s = new int[100];
	csize = 0;
	fsize = 0;
	ssize = 0;
	notlast = 1;
}

void topo::del(pair<int, int>a)
{
	int i = 0;
	while (1)
	{
		if (a.first == course[i].first&&a.second == course[i].second)
		{
			break;
		}
		else
			i++;
	}
	for (int j = i; j < csize-1; j++)
	{
		course[j] = course[j + 1];
	}
	csize--;
}

void topo::delf(int a)
{
	int notdone = 1;
	while (1)
	{
		int index = -1;
		notdone = 0;
		for (int i = fsize - 1; i >= 0; i--)
		{
			if (a == f[i])
			{
				index = i;
				notdone = 1;
				break;
			}
		}
		if (notdone == 0)
		{
			break;
		}
		if (index == fsize - 1)
		{
			fsize--;
		}
		else
		{
			for (int i = index; i < fsize - 1; i++)
			{
				f[i] = f[i + 1];
			}
			fsize--;
		}
	}
}

int* topo::delr(int* a,int size)
{
	int* b = new int[100];
	int bsize = 0;
	for (int i = 0; i < 100; i++)
	{
		b[i] = -1;
	}
	for (int i = 0; i < size; i++)
	{
		if (!exist(a[i], size, b))
		{
			b[bsize] = a[i];
			bsize++;
		}
	}
	if (a == f)
	{
		fsize = bsize;
	}
	else
	{
		ssize = bsize;
	}
	return b;
}

bool topo::exist(int a,int l,int *c)
{
	int found = 0;
	for (int i = 0; i < l; i++)
	{
		if (a == c[i])
			found = 1;
	}
	return found;
}

void topo::insert(pair<int, int>a)
{
	course[csize] = a;
	csize++;
}

void topo::sort()
{
	int round = 1;
	while (1)
	{
		reset();
		for (int i = 0; i < csize; i++)
		{
			f[i] = course[i].first;
			fsize++;
			s[i] = course[i].second;
			ssize++;
		}
		compare(f, s);
	
		cout << "term: " << round << endl;
		f = delr(f, fsize);
		for (int i = 0; i < fsize; i++)
		{
			cout << f[i] << endl;
		}
		if (notlast == 0)
		{
			break;
		}
		for (int i = 0; i < fsize; i++)
		{
			for (int j = 0; j < csize; j++)
			{
				if (f[i] == course[j].first)
				{
					del(course[j]);
				}
			}
		}
		round++;
	}
	cout << "term: " << round +1<< endl;
	s = delr(s, ssize);
	for (int i = 0; i < ssize; i++)
	{
		cout << s[i] << endl;
	}
}

void topo:: compare(int *_f, int *_s)
{
	notlast = 0;
	for (int i = 0; i < fsize; )
	{
		int skip = 1;
		for (int j = 0; j < ssize; j++)
		{
			if (_f[i] == _s[j])
			{
				notlast = 1;
				delf(_f[i]);
				skip = 0;
				break;
			}
		}
		if (skip)
		{
			i++;
		}
	}
}

void topo::reset()
{
	delete f;
	delete s;
	f = new int[100];
	s = new int[100];
	fsize = 0;
	ssize = 0;
}

int main()
{
	cout << "ÊäÈëÊý¶Ô:" << endl;
	topo test1;
	pair<int, int>a;
	int b;
	cin >> b;
	while (b != -1)
	{
		a.first = b;
		cin >> b;
		a.second = b;
		test1.insert(a);
		cin >> b;
	}
	test1.sort();
	system("pause");
	return 0;
}