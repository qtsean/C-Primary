#include<iostream>
#include<stdlib.h>
using namespace std;
template<class T>
class TM {
private:T *element;
		int n;
public:	TM(T **a,int num);
		T get(int x,int y);
		void set(int x,int y, T a);
		void show();
};
template<class T>
void TM<T>::show() {
	for (int i = 0; i < 2 * n - 1; i++) {
		cout << element[i]<<endl;
	}
	cout << endl;
}
template<class T>
TM<T>::TM(T **a,int num) {
	n = num;
	element = new T[2 * n - 1];
	for (int i = 0; i < n; i++) {
		element[i] = a[0][i];
	}
	for (int i = 1; i < n; i++) {
		element[n - 1 + i] = a[i][0];
	}
}
template<class T>
T TM<T>::get(int x,int y) {
	int i = x - 1;
	int j = y - 1;
	while (i > 0 && j > 0) {
		i--;
		j--;
	}
	if (0==i&&j!=0) {
		return element[j];
	}
	else if(0==j&&i!=0) {
		return element[n - 1 + i];
	}
	else {
		return element[0];
	}
}
template<class T>
void TM<T>::set(int x, int y, T a) {
	int i = x - 1;
	int j = y - 1;
	while (i > 0 && j > 0) {
		i--;
		j--;
	}
	if (0 == i&&j != 0) {
		element[j]=a;
	}
	else if (0 == j&&i != 0) {
		element[n - 1 + i]=a;
	}
	else {
		element[0]=a;
	}
}
int main() {
	int n = 5;
	int **p = new int *[n];
	for (int i = 0; i < n; i++) {
		p[i] = new int[n];
	}
	/*for (int j = 0; j < n; j++) {
		int i = 0;
		p[0][j] = j;
		while (true) {
			static int counti = i;
			static int countj = j;
			if (counti >= n || countj >= n) {
				break;
			}
			while (counti + 1 < n&&countj + 1 < n) {
				p[counti + 1][countj + 1] = j;
				counti++;
				countj++;
			}
			
		}
	}
	for (int i = 1; i < n; i++) {
		int j = 0;
		p[i][0] = i + 4;
		while (true) {
			static int counti = i;
			static int countj = j;
			if (counti >= n || countj >= n) {
				break;
			}
			while(counti + 1 < n&&countj + 1 < n) {
				p[counti + 1][countj + 1] = i + 4;
				counti++;
				countj++;
			}
		}
	}*/
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			p[i][j] = i*n + j;

	//查看输入矩阵的正确性
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << p[i][j] << '\t';
		}
		cout << endl;
	}

	TM<int> test( p, n);
	cout << "第一次显示"<<endl;
	test.show();
	
	cout << "第一次获取3，4:  " << test.get(3, 4) << endl;
	test.set(3, 4, 100);
	cout << "已设置3，4位置的数为100" << endl;
	cout <<"第二次获取3，4  :"<< test.get(3, 4) << endl;
	cout << "第二次显示" << endl;
	test.show();
	system("pause");
	return 0;
}