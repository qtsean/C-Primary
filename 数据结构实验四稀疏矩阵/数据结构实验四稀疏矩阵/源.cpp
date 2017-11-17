#include<iostream>
#include<stdlib.h>
using namespace std;
struct store {
	int row;				//记录元素位置
	int col;
	int volume;				//记录元素值
};
class smatrix {
private:
	store * arr;			
	int num;				//元素个数
	int row;				//原矩阵行数
	int col;				//原矩阵列数
public:
	smatrix(int ** a, int n, int _row, int _col);
	void show();
	void tmatrix();
	void smadd(smatrix test);
	store * get();
};
store *smatrix::get() {
	return arr;
}
void smatrix::smadd(smatrix test) {
	cout << "输出相加后的稀疏矩阵：" << endl;
	int count = 0;			//记录相加后一维数组的长度
	int l1 = 0;				//用来遍历两个相加的一维数组
	int l2 = 0;
	store *temp1 = new store[2 * num];	//保险起见设置长度为2*n
	while (l1 < this->num && l2 < test.num) {			//两个数组尚未遍历完全
		if ((arr[l1].row )*col + arr[l1].col < (test.arr[l2].row )*col + test.arr[l2].col) {	//把位置数小的放在前面
			temp1[count] = arr[l1];
			l1++;			//每次操作后必须把索引加1，count也+1
			count++;
		}
		else if ((arr[l1].row )*col + arr[l1].col > (test.arr[l2].row )*col + test.arr[l2].col) {
			temp1[count] = test.arr[l2];
			l2++;
			count++;
		}
		else if(arr[l1].volume+test.arr[l2].volume!=0){											//如果位置一样，且元素值相加不为0，则元素值相加
			temp1[count].row = arr[l1].row;
			temp1[count].col = arr[l1].col;
			temp1[count].volume = arr[l1].volume + test.arr[l2].volume;
			count++;
			l1++;
			l2++;
		}
		else {		//如果元素相加为0，也需要将索引各加1
			l1++;
			l2++;
		}
	}
	//cout << "check51" << endl;
	if (l1 == this->num) {		//在一个数组已遍历完后，另一个数组中剩余的元素顺序插入相加后的数组中
		while (l2 < test.num) {
			temp1[count] = test.arr[l2];
			l2++;
			count++;
		}
	}
	else if (l2 == test.num) {
		while (l1 < this->num) {
			temp1[count] = arr[l1];
			l1++;
			count++;
		}
	}
	//cout << "check64" << endl;
	cout << "输出相加后映射的一维数组" << endl;
	for (int i = 0; i < count; i++) {
		cout << "行: " << temp1[i].row << "\t";
		cout << "列: " << temp1[i].col << "\t";
		cout << "值: " << temp1[i].volume << "\t";
		cout << endl;
	}

	//以下为矩阵的输出
	cout << "输出矩阵" << endl;
	int **temparr1 = new int*[row];
	for (int i = 0; i < row; i++) {
		temparr1[i] = new int[col];
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			temparr1[i][j] = 0;
		}
	}
	for (int i = 0; i < count; i++) {
		temparr1[temp1[i].row][temp1[i].col] = temp1[i].volume;
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << temparr1[i][j] << "\t";
		}
		cout << endl;
	}
}
void smatrix::tmatrix() {
	cout << "输出转置后的矩阵" << endl;
	store *tp = new store[num];
	for (int i = 0; i < num; i++) {
		tp[i] = arr[i];
	}
	for (int i = 0; i < num; i++) {					//因为已经有映射后的一维数组，所以行列坐标交换即可
		int temp = 0;
		temp = tp[i].row;
		tp[i].row = tp[i].col;
		tp[i].col = temp;
	}
	//以下为输出步骤
	int **temparr = new int*[col];
	for (int i = 0; i < col; i++) {
		temparr[i] = new int[row];
	}
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			temparr[i][j] = 0;
		}
	}
	for (int i = 0; i < num; i++) {
		temparr[tp[i].row][tp[i].col] = tp[i].volume;
	}
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			cout << temparr[i][j] << "\t";
		}
		cout << endl;
	}
}
void smatrix::show() {
	cout << "输出稀疏矩阵:" << endl;
	int count = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (i == arr[count].row && j == arr[count].col) {		//若这个点有对应的一维数组里的元素，则输出
				cout << arr[count].volume<<"\t";
				count++;
			}
			else {
				cout << 0 << "\t";
			}
		}
		cout << endl;
	}
}
smatrix::smatrix(int ** a, int n,int _row, int _col) {
	row = _row;
	col = _col;
	num = n;
	int count = 0;
	arr = new store[n];
	for (int i = 0; i < _row; i++) {
		for (int j = 0; j < _col; j++) {
			if (a[i][j] != 0) {
				arr[count].row = i;
				arr[count].col = j;
				arr[count].volume = a[i][j];
				count++;
			}
		}
	}
	cout << "输出映射的一维数组" << endl;
	for (int i = 0; i < count; i++) {
		cout << "行: " << arr[i].row<<"\t";
		cout << "列: " << arr[i].col<<"\t";
		cout << "值: " << arr[i].volume<<"\t";
		cout << endl;
	}
}
void showsm(int row,int col,int **a) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}
}
int main() {
	cout << "第一个稀疏矩阵" << endl;
	int n1 = 0;
	int row1 = 3;
	int col1 = 4;
	int **a1 = new int *[row1];
	for (int i = 0; i < row1; i++) {
		a1[i] = new int[col1];
	}
	int b1[3][4] = 
	{
		{1,0,0,4},
		{0,9,0,11},
		{-4,5,0,0}
	};
	for (int i = 0; i < row1; i++) {
		for (int j = 0; j < col1; j++) {
			a1[i][j]=b1[i][j];
		}
	}
	for (int i = 0; i < row1; i++) {
		for (int j = 0; j < col1; j++) {
			if (a1[i][j] != 0)
				n1++;
		}
	}
	cout << endl;
	cout << "输入的稀疏矩阵1是：" << endl;
	showsm(3, 4, a1);
	smatrix test1(a1, n1, row1, col1);
	test1.show();
	test1.tmatrix();
	cout << endl;
	cout << "第二个稀疏矩阵" << endl;
	int n2 = 0;
	int row2 = 3;
	int col2 = 4;
	int **a2 = new int *[row2];
	for (int i = 0; i < row2; i++) {
		a2[i] = new int[col2];
	}
	int b2[3][4]=
	{
		{2,3,0,0},
		{0,-9,0,0},
		{4,6,0,2}
	};
	for (int i = 0; i < row2; i++) {
		for (int j = 0; j < col2; j++) {
			a2[i][j] = b2[i][j];
			if (b2[i][j] != 0)
				n2++;
		}
	}
	cout << endl;
	cout << "输入的稀疏矩阵1是：" << endl;
	showsm(3, 4, a1);
	cout << "输入的稀疏矩阵2是: " << endl;
	showsm(3, 4, a2);
	smatrix test2(a2, n2, row2, col2);
	test2.smadd(test1);
	system("pause");
	return 0;
}