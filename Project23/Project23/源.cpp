#include<iostream>
#include<stdlib.h>
using namespace std;
struct list {
	int raw;
	int col;
	int value;
};
class cMatrix {
private:int size;
		list *shuzu;
public:
	int  get(int);
	void insert(int, int);
	cMatrix(int **a, int n);
	void show();
};
void cMatrix::show() {
	for (int i = 0; i < 3 * size - 2; i++)
		cout << shuzu[i + 1].value << endl;
}
int cMatrix::get(int index) {
	return shuzu[index + 1].value;
}
void cMatrix::insert(int index, int x) {
	shuzu[index + 1].value = x;
}
cMatrix::cMatrix(int **a, int n) {
	size = n;
	shuzu = new list[3 * size - 2 + 1];
	for (int i = 0; i < size; i++) {
		shuzu[i + 1].value = a[0][i];
		shuzu[i + 1].raw = 1;
		shuzu[i + 1].col = i + 1;
	}
	for (int i = 0; i < size - 2; i++) {
		shuzu[size + i + 1].value = a[i + 1][0];
		shuzu[size + i + 1].raw = i + 1;
		shuzu[size + i + 1].col = 1;
	}
	for (int i = 0; i < size; i++) {
		shuzu[2 * size - 2 + i + 1].value = a[size - 1][i];
		shuzu[2 * size - 2 + i + 1].raw = size;
		shuzu[2 * size - 2 + 1 + i].col = i + 1;
	}
}
int main() {
	int n = 4;
	int **data = new int *[n];
	for (int i = 0; i < n; i++) {
		data[i] = new int[n];
	}
	for (int i = 0; i < n; i++)
		for(int j = 0; j < n; j++) {
			data[i][j] = i * 4 + j ;
	}
	cMatrix _4(data, 4);
	_4.show();
	cout << _4.get(4) << endl;
	_4.insert(7, 100);
	cout << _4.get(7) << endl;
	system("pause");
	return 0;
}