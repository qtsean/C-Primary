#include<iostream>
#include<stdlib.h>
#include<ctime>
using namespace std;
struct mesh {
	int iswall;				//�ϰ�
	int used;				//�߹���·�����ظ���
};
class maze {
private:
	int *length;			//
	int start1;
	int start;
	mesh **mz;				//�Թ��ļ�
	mesh **copy;			//�����Թ��ļ�
	int size;
	mesh***temp;			//��ά����������е�·��
	int count;				//ͳ�ƿ��е�·����
	int cr;					//create������
public:
	void find2(int row,int col);	//��·��
	int found;						//�ж��Ƿ���·
	maze(mesh**a,int size);
	void show();					//���ԭ�Թ�
	void findway(int row, int col);
	void showway(int);
	void create();					//���ݿ��е�·����������ά����Ŀռ�
	void record(mesh**);			//��¼·��
	void countlength();				//����ÿ��·���Ĳ������ҵ���̵����
};
void maze::find2(int row, int col) {//�ҵĹ���
	
	if (start1 == 0) {				//������ڵ㣬������
		row = 1;
		col = 1;
		start1 = 1;
	}
	copy[row][col].used = 1;
	if (row == size - 2 && col == size - 1) {		//����Ϊ����
		record(copy);
		return;
	}
	//�ݹ��������
	if (copy[row][col + 1].iswall == 0 && copy[row][col + 1].used == 0) {
		find2(row, col + 1);
		copy[row][col+1].used = 0;
	}
	if (copy[row + 1][col].iswall == 0 && copy[row + 1][col].used == 0) {
		find2(row + 1, col);
		copy[row+1][col].used = 0;
	}
	if (copy[row][col - 1].iswall == 0 && copy[row][col - 1].used == 0) {
		find2(row, col - 1);
		copy[row][col-1].used = 0;
	}
	if (copy[row - 1][col].iswall == 0 && copy[row - 1][col].used == 0) {
		find2(row - 1, col);
		copy[row-1][col].used = 0;
	}
}
void maze::countlength() {
	cout << "start countlength" << endl;
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < size; j++) {
			for (int z = 0; z < size; z++) {
				if (temp[i][j][z].used == 1) {
					length[i]++;
				}
			}
		}
	}
	int * a = new int[count];
	for (int i = 0; i < count; i++) {
		a[i] = length[i];
	}
	while (1) {		//�������ҵ����·����¼����
		if (count == 1)
			break;
		bool change = 0;
		for (int i = 0; i < count-1; i++) {
			if (length[i] > length[i + 1]) {
				int t = length[i + 1];
				length[i + 1] = length[i];
				length[i] = t;
				change = 1;
			}
		}
		if (change == 0)
			break;
	}
	for (int i = 0; i < count; i++) {	//����һ��length���飬�õ����в���Ϊ��̵������������������Ӧ����ά�����е��Թ���·��
		if (length[0] == a[i]) {
			showway(i);
		}
	}
}
void maze::record(mesh**a) {
	static int z = 0;
	z++;
	cout << "start record" << z<<endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			temp[cr][i][j].iswall = a[i][j].iswall;
			temp[cr][i][j].used = a[i][j].used;
		}
	}
	cr++;
}
void maze::create() {
	cout << "start create" << endl;
	length = new int[count];
	for (int i = 0; i < count; i++) {
		length[i] = 0;
	}
	temp = new mesh**[count];
	for (int i = 0; i < count; i++) {
		temp[i] = new mesh*[size];
		for (int j = 0; j < size; j++) {
			temp[i][j] = new mesh[size];
		}
	}
}
void maze::showway(int i) {			//#��ʾ�ϰ���*��ʾ·��
	cout << "start showway" << endl;
	for (int z = 0; z < size; z++) {
		for (int j = 0; j < size; j++) {
			if (temp[i][z][j].iswall == 1) {
				cout << "# ";
			}
			else if(temp[i][z][j].used==1){
				cout << "��";
			}
			else {
				cout << "  ";
			}
		}
		cout << endl;
	}


	/*
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (mz[i][j].used == 1) {
				cout << "* ";
			}else
			if (mz[i][j].iswall == 1) {
				cout << "# ";
			}
			else {
				cout << "  ";
			}
		}
		cout << endl;
	}
	*/
}
void maze::findway(int row, int col) {
	if (start == 0) {
		row = 1;
		col = 1;
		start = 1;
	}
	mz[row][col].used = 1;
	if (row == size - 2 && col == size - 1) {
		found = 1;
		count++;
		cout << "found: "<<count<< endl;
		return;
	}
	if (mz[row][col + 1].iswall == 0 && mz[row][col + 1].used == 0) {
		findway(row, col + 1);
		mz[row][col+1].used = 0;
	}
	if (mz[row + 1][col].iswall == 0 && mz[row + 1][col].used == 0) {
		findway(row + 1, col);
		mz[row+1][col].used = 0;
	}
	if (mz[row][col - 1].iswall == 0 && mz[row][col - 1].used == 0) {
		findway(row, col - 1);
		mz[row][col-1].used = 0;
	}
	if (mz[row - 1][col].iswall == 0 && mz[row - 1][col].used == 0) {
		findway(row - 1, col);
		mz[row-1][col].used = 0;
	} 
}
void maze::show() {
	cout << "start show" << endl;
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
maze::maze(mesh**a,int _size) {
	start1 = 0;
	cr = 0;
	count = 0;
	found = 0;
	start = 0;
	size = _size;
	mz = new mesh*[size];
	for (int i = 0; i < size; i++) {
		mz[i] = new mesh[size];
	}
	copy = new mesh*[size];
	for(int i = 0; i < size; i++) {
		copy[i] = new mesh[size];
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			mz[i][j] = a[i][j];
			copy[i][j] = a[i][j];
		}
	}
}
int main() {
	srand((unsigned)time(NULL));			//��������Թ�
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
	/*
	for (int i = 1; i < size - 1; i++) {
		for (int j = 1; j < size - 1; j++) {
			if (a[i][j].iswall == 0 && a[i - 1][j].iswall == 0 && a[i + 1][j].iswall == 0 && a[i][j - 1].iswall == 0 && a[i][j + 1].iswall == 0) {
				a[i][j].iswall = 1;
			}
		}
	}
	*/
	a[1][0].iswall = 0;
	a[1][1].iswall = 0;
	a[1][0].used = 1;
	a[size - 2][size - 1].iswall = 0;
	a[size - 2][size - 2].iswall = 0;
	

	/*
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (a[i][j].iswall == 1) {
				cout << "# ";
			}
			else {
				cout << "  ";
			}
		}
		cout << endl;
	}

	*/
	maze test(a, size);
	test.show();
	//system("pause");
	cout << "start findway" << endl;
	test.findway(0, 0);
	if (test.found == 1) {
		test.create();
		cout << "start find2" << endl;
		test.find2(0, 0);
		test.countlength();
	}
	else {
		cout << "NO WAY FOUND" << endl;
	}
	//test.showway();
	system("pause");

	return 0;
}