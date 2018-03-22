#include<iostream>
#include<cstdlib>
using namespace std;

float* ravg(int row, int col, float** m)
{
	float* avg = new float[row];
	for (int i = 0; i < row; i++)
	{
		float sum = 0;
		for (int j = 0; j < col; j++)
		{
			sum += m[i][j];
		}
		avg[i] = 1.0*sum / col;
	}
	return avg;
}
float* cavg(int row, int col, float** m)
{
	float* avg = new float[col];
	for (int i = 0; i < col; i++)
	{
		float sum = 0;
		for (int j = 0; j < row; j++)
		{
			sum += m[j][i];
		}
		avg[i] = 1.0*sum / row;
	}
	return avg;
}
float** remover(int row, int col, float**m,int index)
{

	float** n = new float*[row - 1];
	for (int i = 0; i < row - 1; i++)
	{
		n[i] = new float[col];
	}
	for (int i = index; i < row - 1; i++)
	{
		for (int j = 0; j < col; j++)
		{
			m[i][j] = m[i + 1][j];
		}
	}
	for (int i = 0; i < row - 1; i++)
	{
		for (int j = 0; j < col; j++)
		{
			n[i][j] = m[i][j];
		}
	}
	delete m;
	return n;
}
float** removec(int row, int col, float**m,int index)
{
	float** n = new float*[row];
	for (int i = 0; i < row; i++)
	{
		n[i] = new float[col - 1];
	}
	for (int i = index; i < col - 1; i++)
	{
		for (int j = 0; j < row; j++)
		{
			m[j][i] = m[j][i + 1];
		}
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col - 1; j++)
		{
			n[i][j] = m[i][j];
		}
	}
	delete m;
	return n;
}
float* times(int row, int col, float**m, float* x)
{
	float* result = new float[row];
	for (int i = 0; i < row; i++)
	{
		float sum = 0;
		for (int j = 0; j < col; j++)
		{
			sum += m[i][j] * x[j];
		}
		result[i] = sum;
	}
	return result;
}
void showmatrix(int row, int col, float** m)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
}
void showresult(int number, float*x)
{
	for (int i = 0; i < number; i++)
	{
		cout << x[i] << " ";
	}
	cout << endl;
}
int main()
{
	cout << "输入行数，列数" << endl;
	int row;
	int col;
	float *avgr;
	float *avgc;
	float *result;
	float*x;
	float **m;
	int index;
	cin >> row;
	cin >> col;
	m = new float*[row];
	for (int i = 0; i < row; i++)
	{
		m[i] = new float[col];
	}
	cout << "输入一个" << row << "*" << col << "的二维数组" << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cin >> m[i][j];
		}
	}
	x = new float[col];
	cout << "输入一个长度为" << col << "的一维数组" << endl;
	for (int i = 0; i < col; i++)
	{
		cin >> x[i];
	}
	cout << "行平均数为：" << endl;
	avgr = ravg(row, col, m);
	showresult(row, avgr);
	cout << "列平均数为： " << endl;
	avgc = cavg(row, col, m);
	showresult(col, avgc);
	cout << "和一维数组相乘的结果： " << endl;
	result = times(row, col, m, x);
	showresult(row, result);
	cout << "你要移除第几行，从0开始数： " << endl;
	cin >> index;
	m = remover(row, col, m,index);
	row = row - 1;
	cout << "移除一行的结果： " << endl;
	showmatrix(row, col, m);
	cout << "你要移除第几列，从0开始数： " << endl;
	cin >> index;
	m = removec(row, col, m,index);
	col = col - 1;
	cout << "移除一列的结果： " << endl;
	showmatrix(row, col, m);
	system("pause");
	return 0;
}