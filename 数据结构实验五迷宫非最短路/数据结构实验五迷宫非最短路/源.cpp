#include<iostream>
#include<stdlib.h>
#include<ctime>
using namespace std;
struct mesh {
	int iswall;				//障碍
	int used;				//走过的路不能重复走
};
class maze {
private:
	int start;
	mesh **mz;				//迷宫文件
	int size;
public:
	int found;						//判断是否有路
	maze(mesh**a, int size);
	void show();					//输出原迷宫
	void findway(int row, int col);
	void showway();
};
void maze::showway() {	
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (mz[i][j].iswall == 1) {
				cout << "# ";
			}
			else if (mz[i][j].used == 1) {
				cout << "。";
			}
			else {
				cout << "  ";
			}
		}
		cout << endl;
	}
	//#表示障碍，*表示路径
}
void maze::findway(int row, int col) {
	if (found == 1) {
		return;
	}
	if (start == 0) {
		row = 1;
		col = 1;
		start = 1;
	}
	mz[row][col].used = 1;
	if (row == size - 2 && col == size - 1) {
		found = 1;
		showway();
	}
	if (found == 1) {
		return;
	}
	if (mz[row][col + 1].iswall == 0 && mz[row][col + 1].used == 0) {
		findway(row, col + 1);
		mz[row][col + 1].used = 0;
	}
	if (found == 1) {
		return;
	}
	if (mz[row + 1][col].iswall == 0 && mz[row + 1][col].used == 0) {
		findway(row + 1, col);
		mz[row + 1][col].used = 0;
	}
	if (found == 1) {
		return;
	}
	if (mz[row][col - 1].iswall == 0 && mz[row][col - 1].used == 0) {
		findway(row, col - 1);
		mz[row][col - 1].used = 0;
	}
	if (found == 1) {
		return;
	}
	if (mz[row - 1][col].iswall == 0 && mz[row - 1][col].used == 0) {
		findway(row - 1, col);
		mz[row - 1][col].used = 0;
	}
}
void maze::show() {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (mz[i][j].iswall == 1) {
				cout << "# ";
			}
			else {
				cout << "  ";
			}
		}
		cout << endl;
	}
}
maze::maze(mesh**a, int _size) {

	found = 0;
	start = 0;
	size = _size;
	mz = new mesh*[size];
	for (int i = 0; i < size; i++) {
		mz[i] = new mesh[size];
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			mz[i][j] = a[i][j];
		}
	}
}
int main() {
	srand((unsigned)time(NULL));			//创建随机迷宫
	int size;
	cin >> size;
	mesh**a = new mesh*[size];
	for (int i = 0; i < size; i++) {
		a[i] = new mesh[size];
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			a[i][j].iswall = 0;
			a[i][j].used = 0;
			if (i == 0 || j == 0 || i == size - 1 || j == size - 1) {
				a[i][j].iswall = 1;
			}
		}
	}
	for (int i = 1; i < size - 1; i++) {
		for (int j = 1; j < size - 1; j++) {
			if (rand() % 3 == 1) {
				a[i][j].iswall = 1;
			}
		}
	}
	a[1][0].iswall = 0;
	a[1][1].iswall = 0;
	a[1][0].used = 1;
	a[size - 2][size - 1].iswall = 0;
	a[size - 2][size - 2].iswall = 0;
	maze test(a, size);
	test.findway(0, 0);
	if (test.found == 0) {
		test.show();
		cout << "no exit" << endl;
	}
	system("pause");
	return 0;
}