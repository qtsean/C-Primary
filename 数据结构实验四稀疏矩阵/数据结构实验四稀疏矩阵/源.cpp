#include<iostream>
#include<stdlib.h>
using namespace std;
struct store {
	int row;				//��¼Ԫ��λ��
	int col;
	int volume;				//��¼Ԫ��ֵ
};
class smatrix {
private:
	store * arr;			
	int num;				//Ԫ�ظ���
	int row;				//ԭ��������
	int col;				//ԭ��������
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
	cout << "�����Ӻ��ϡ�����" << endl;
	int count = 0;			//��¼��Ӻ�һά����ĳ���
	int l1 = 0;				//��������������ӵ�һά����
	int l2 = 0;
	store *temp1 = new store[2 * num];	//����������ó���Ϊ2*n
	while (l1 < this->num && l2 < test.num) {			//����������δ������ȫ
		if ((arr[l1].row )*col + arr[l1].col < (test.arr[l2].row )*col + test.arr[l2].col) {	//��λ����С�ķ���ǰ��
			temp1[count] = arr[l1];
			l1++;			//ÿ�β���������������1��countҲ+1
			count++;
		}
		else if ((arr[l1].row )*col + arr[l1].col > (test.arr[l2].row )*col + test.arr[l2].col) {
			temp1[count] = test.arr[l2];
			l2++;
			count++;
		}
		else if(arr[l1].volume+test.arr[l2].volume!=0){											//���λ��һ������Ԫ��ֵ��Ӳ�Ϊ0����Ԫ��ֵ���
			temp1[count].row = arr[l1].row;
			temp1[count].col = arr[l1].col;
			temp1[count].volume = arr[l1].volume + test.arr[l2].volume;
			count++;
			l1++;
			l2++;
		}
		else {		//���Ԫ�����Ϊ0��Ҳ��Ҫ����������1
			l1++;
			l2++;
		}
	}
	//cout << "check51" << endl;
	if (l1 == this->num) {		//��һ�������ѱ��������һ��������ʣ���Ԫ��˳�������Ӻ��������
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
	cout << "�����Ӻ�ӳ���һά����" << endl;
	for (int i = 0; i < count; i++) {
		cout << "��: " << temp1[i].row << "\t";
		cout << "��: " << temp1[i].col << "\t";
		cout << "ֵ: " << temp1[i].volume << "\t";
		cout << endl;
	}

	//����Ϊ��������
	cout << "�������" << endl;
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
	cout << "���ת�ú�ľ���" << endl;
	store *tp = new store[num];
	for (int i = 0; i < num; i++) {
		tp[i] = arr[i];
	}
	for (int i = 0; i < num; i++) {					//��Ϊ�Ѿ���ӳ����һά���飬�����������꽻������
		int temp = 0;
		temp = tp[i].row;
		tp[i].row = tp[i].col;
		tp[i].col = temp;
	}
	//����Ϊ�������
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
	cout << "���ϡ�����:" << endl;
	int count = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (i == arr[count].row && j == arr[count].col) {		//��������ж�Ӧ��һά�������Ԫ�أ������
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
	cout << "���ӳ���һά����" << endl;
	for (int i = 0; i < count; i++) {
		cout << "��: " << arr[i].row<<"\t";
		cout << "��: " << arr[i].col<<"\t";
		cout << "ֵ: " << arr[i].volume<<"\t";
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
	cout << "��һ��ϡ�����" << endl;
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
	cout << "�����ϡ�����1�ǣ�" << endl;
	showsm(3, 4, a1);
	smatrix test1(a1, n1, row1, col1);
	test1.show();
	test1.tmatrix();
	cout << endl;
	cout << "�ڶ���ϡ�����" << endl;
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
	cout << "�����ϡ�����1�ǣ�" << endl;
	showsm(3, 4, a1);
	cout << "�����ϡ�����2��: " << endl;
	showsm(3, 4, a2);
	smatrix test2(a2, n2, row2, col2);
	test2.smadd(test1);
	system("pause");
	return 0;
}