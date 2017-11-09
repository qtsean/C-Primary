#include<stdlib.h>
#include<iostream>
using namespace std;
template<class T>
class Sort {
private:
	T *a;
	int n;
public:
	Sort(T *list, int listsize) {
		a = list;
		n = listsize;
	}

	void selection() {
		for (int i = 0; i<n; i++) {
			int indexofmax = 0;
			for (int j = 1; j<n - i; j++) {
				if (a[indexofmax]<a[j]) {
					indexofmax = j;
				}
			}
			for (int m = 0; m<n; m++)
				cout << a[m] << ' ';
			cout << endl;
			if (a[indexofmax] == a[n - i - 1])
				break;
			swap(a[indexofmax], a[n - i - 1]);
		}
	}

	void bubble() {
		for (int i = 0; i<n; i++) {
			bool swapped = false;
			for (int m = 0; m<n - i; m++) {
				if (a[m]>a[m + 1]) {
					swap(a[m], a[m + 1]);
					swapped = true;
					for (int j = 0; j<n; j++)
						cout << a[j] << ' ';
					cout << endl;
				}
			}
			if (swapped == false)
				break;
		}
	}

	void insert() {
		for (int m = 1; m<n; m++) {
			T t = a[m];
			int i;
			for (i = m - 1; i >= 0 && t<a[i]; i--)
				a[i + 1] = a[i];
			a[i + 1] = t;
			for (int j = 0; j<n; j++)
				cout << a[j] << ' ';
			cout << endl;
		}
	}

	void radix()
	{
		int m;
		for (int i = 1; i <= 100; i = i * 10)
		{
			int tmp[20][10] = { 0 };
			for (int j = 0; j<n; j++)
			{
				m = (a[j] / i) % 10;
				tmp[j][m] = a[j];
			}
			int k = 0;
			for (int p = 0; p<10; p++)
				for (int q = 0; q<n; q++)
				{
					if (tmp[q][p] != 0)
						a[k++] = tmp[q][p];
				}
			for (int i = 0; i<n; i++)
				cout << a[i] << " ";
			cout << endl;
		}
	}
};
int main() {
	int list[] = { 100,245,412,187,141,151,945,831 };
	Sort<int> example(list, 8);
	example.selection();
	system("pause");
	return 0;
	
}
