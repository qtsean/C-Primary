#include<iostream>
#include<cstdlib>
#define NOWAY 10000
using namespace std;

class dp
{
private:
	int **start;
	int **end;
	int size;
public:
	dp(int **,int);
	void shortest();
	void showend();
	void findBestLocation1();
	int findLongestInCol(int );
	void fineBestLocation2();
	int findSumInCol(int);
};
dp::dp(int **a,int _size)
{
	start = a;
	size = _size;
	end = new int*[size];
	for (int i = 0; i < size; i++)
	{
		end[i] = new int[size];
	}
}
void dp::shortest()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			end[i][j] = start[i][j];
		}
	}
	for (int i = 0; i < size; i++)
		end[i][i] = 0;
	for(int k=0;k<size;k++)
		for(int i=0;i<size;i++)
			for (int j = 0; j < size; j++)
			{
				int t1 = end[i][k];
				int t2 = end[k][j];
				int t3 = end[i][j];
				if (t1 != NOWAY && t2 != NOWAY && (t3 == NOWAY || t1 + t2 < t3))
				{
					end[i][j] = t1 + t2;
				}
			}
}

void dp::showend()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << end[i][j] << "\t";
		}
		cout << endl;
	}
}

void dp::findBestLocation1()
{
	int *t = new int[size];
	for (int i = 0; i < size; i++)
	{
		t[i] = findLongestInCol(i);
	}
	int k = 0;
	int min = NOWAY;
	for (int i = 0; i < size ; i++)
	{
		if (min > t[i])
		{
			min = t[i];
			k = i;
		}
	}
	cout << "其他城市到这个城市最大距离最小的是： " << k + 1 << endl;
}

int dp::findLongestInCol(int a)
{
	int k = 0;
	for (int i = 0; i < size; i++)
	{
		if (k < end[i][a])
		{
			k = end[i][a];
		}
	}
	return k;
}

int dp::findSumInCol(int a)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += end[i][a];
	}
	return sum;
}

void dp::fineBestLocation2()
{
	int *t = new int[size];
	for (int i = 0; i < size; i++)
	{
		t[i] = findSumInCol(i);
	}
	int k = 0;
	int min = NOWAY;
	for (int i = 0; i < size; i++)
	{
		if (min > t[i])
		{
			min = t[i];
			k = i;
		}
	}
	cout << "其他城市到这个城市总距离最小的是: " << k + 1 << endl;
}

int main()
{
	cout << "输入社区数量:" << endl;
	int size;
	cin >> size;
	int **a = new int*[size];
	for (int i = 0; i < size; i++)
	{
		a[i] = new int[size];
	}
	cout << "输入社区之间的直接距离，没有直接距离的输入-1" << endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			int b;
			cin >> b;
			if (b == -1)
				b = 10000;
			a[i][j] = b;
		}
	}
	dp test1(a,size);
	test1.shortest();
	test1.showend();
	test1.findBestLocation1();
	test1.fineBestLocation2();
	system("pause");
	return 0;
}