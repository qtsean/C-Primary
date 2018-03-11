#include<iostream>
#include<stdlib.h>
#include<queue>
#include<stack>
#include<ctime>
#define changetime 20
#define trytime 500
using namespace std;
struct node
{
	int matrix[3][3];
	node* nextup;
	node* nextdown;
	node* nextright;
	node* nextleft;
	node* parent;
	int row;
	int col;
	int cost;
	int direction;
};
stack<int> S;
queue<node*> Q;
class greedy 
{
	private:
		int total;
		node *start;
		int end[3][3];
		node *current;
		int succeed;
		int fail;
		int failnum;
		int succeednum;
		double avg_succeed;
		int totalnum;
		int totalstep;
	public:
		greedy();
		int cost(node*);
		void solve();
		void solve2();
		bool islegal(int, int);
		void sort(node**);
		void showway();
		void print(int**);
		node** findway(node*);
		void create(int** initial, int** final);
		void showstatistics();
		void showstatistics2();
		void resetstack();
		int getfail();
};
int greedy::getfail()
{
	return succeed;
}
void greedy::showstatistics2()
{
	cout << "分支限界法： " << endl;
	if (succeednum != 0)
		avg_succeed = 1.0*totalstep / succeednum;
	cout << "total number:" << "\t\t" << succeednum << endl;
	//cout << "fail number:" << "\t\t" << failnum << endl;
	//cout << "total number:" << "\t\t" << totalnum << endl;
	cout << "average steps:" << "\t\t" << avg_succeed << endl;
	//cout << "success rate:" << "\t\t" << 1.0*succeednum / totalnum * 100 << "%" << endl;
}
void greedy::resetstack()
{
	while (S.size() > 0) {
		S.pop();
	}
}
void greedy::showstatistics()
{
	cout << "贪婪法：" << endl;
	if(succeednum!=0)
	avg_succeed = 1.0*totalstep / succeednum;
	cout << "success number:" << "\t\t" << succeednum << endl;
	cout << "fail number:" << "\t\t" << failnum << endl;
	cout << "total number:" << "\t\t" << totalnum << endl;
	cout << "average steps:" << "\t\t" << avg_succeed << endl;
	cout << "success rate:" << "\t\t" << 1.0*succeednum / totalnum *100<<"%"<< endl;
}
void greedy::create(int** initial, int** final)
{
	succeed = 0;
	fail = 0;
	//start = new node;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			start->matrix[i][j] = initial[i][j];
			end[i][j] = final[i][j];
		}
	}
	for (int i = 0; i<3; i++)
	{
		for (int j = 0; j<3; j++)
		{
			if (start->matrix[i][j] == 0)
			{
				start->row = i;
				start->col = j;
				break;
			}
		}
	}
	start->parent = new node;
	start->parent->row = 100;
	start->parent->col = 100;
	current = start;
	start->cost = cost(start);
}
node** greedy::findway(node* _current)
{
	if (islegal(_current->row - 1, _current->col) && ((_current->row - 1 != _current->parent->row) || (_current->col != _current->parent->col)))
	{
		_current->nextup = new node;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				_current->nextup->matrix[i][j] = _current->matrix[i][j];
			}
		}
		int temp = _current->matrix[_current->row - 1][_current->col];
		_current->nextup->matrix[_current->row - 1][_current->col] = 0;
		_current->nextup->matrix[_current->row][_current->col] = temp;
		_current->nextup->cost = cost(_current->nextup);
		_current->nextup->parent = _current;
		_current->nextup->direction = 1;
		_current->nextup->row = _current->row - 1;
		_current->nextup->col = _current->col;
	}
	else {
		_current->nextup = NULL;
	}
	if (islegal(_current->row + 1, _current->col) && ((_current->row + 1 != _current->parent->row) || (_current->col != _current->parent->col)))
	{
		_current->nextdown = new node;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				_current->nextdown->matrix[i][j] = _current->matrix[i][j];
			}
		}
		int temp = _current->matrix[_current->row + 1][_current->col];
		_current->nextdown->matrix[_current->row + 1][_current->col] = 0;
		_current->nextdown->matrix[_current->row][_current->col] = temp;
		_current->nextdown->cost = cost(_current->nextdown);
		_current->nextdown->parent = _current;
		_current->nextdown->direction = 2;
		_current->nextdown->row = _current->row + 1;
		_current->nextdown->col = _current->col;
	}
	else
	{
		_current->nextdown = NULL;
	}
	if (islegal(_current->row, _current->col - 1) && ((_current->row != _current->parent->row) || (_current->col - 1 != _current->parent->col)))
	{
		_current->nextleft = new node;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				_current->nextleft->matrix[i][j] = _current->matrix[i][j];
			}
		}
		int temp = _current->matrix[_current->row][_current->col - 1];
		_current->nextleft->matrix[_current->row][_current->col - 1] = 0;
		_current->nextleft->matrix[_current->row][_current->col] = temp;
		_current->nextleft->cost = cost(_current->nextleft);
		_current->nextleft->parent = _current;
		_current->nextleft->direction = 3;
		_current->nextleft->row = _current->row;
		_current->nextleft->col = _current->col - 1;
	}
	else
	{
		_current->nextleft = NULL;
	}
	if (islegal(_current->row, _current->col + 1) && ((_current->row != _current->parent->row) || (_current->col + 1 != _current->parent->col)))
	{
		_current->nextright = new node;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				_current->nextright->matrix[i][j] = _current->matrix[i][j];
			}
		}
		int temp = _current->matrix[_current->row][_current->col + 1];
		_current->nextright->matrix[_current->row][_current->col + 1] = 0;
		_current->nextright->matrix[_current->row][_current->col] = temp;
		_current->nextright->cost = cost(_current->nextright);
		_current->nextright->parent = _current;
		_current->nextright->direction = 4;
		_current->nextright->row = _current->row;
		_current->nextright->col = _current->col + 1;
	}
	else
	{
		_current->nextright = NULL;
	}
	node** tep = new node*[4];
	tep[0] = _current->nextup;
	tep[1] = _current->nextdown;
	tep[2] = _current->nextleft;
	tep[3] = _current->nextright;
	return tep;
}
void greedy::print(int** a)
{
	cout << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
}
void greedy::showway()
{
	//cout << "succeed" << endl;
	int** mtr;
	mtr = new int*[3];
	for (int i = 0; i < 3; i++)
		mtr[i] = new int[3];
	int x;
	int y;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			mtr[i][j] = start->matrix[i][j];
		}
	}
	int step = S.size();
	int* length = new int[step];
	for (int i = 0; i < step; i++)
	{
		length[i] = S.top();
		S.pop();
	}
	/*for (int i = step-1; i >= 0; i--)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (mtr[i][j] == 0)
				{
					x = i;
					y = j;
				}
			}
		}
		switch (length[i])
		{
			case 1: 
			{
				int temp = mtr[x - 1][y]; 
				mtr[x - 1][y] = 0;
				mtr[x][y] = temp;
				print(mtr);
				break;
			}
			case 2:
			{
				int temp = mtr[x + 1][y];
				mtr[x + 1][y] = 0;
				mtr[x][y] = temp;
				print(mtr);
				break;
			}
			case 3:
			{
				int temp = mtr[x][y - 1];
				mtr[x][y - 1] = 0;
				mtr[x][y] = temp;
				print(mtr);
				break;
			}
			case 4:
			{
				int temp = mtr[x][y + 1];
				mtr[x][y + 1] = 0;
				mtr[x][y] = temp;
				print(mtr);
				break;
			}
		}
	}*/
}
void greedy::sort(node** tep)
{
	int change = 1;
	while (change)
	{
		change = 0;
		for (int i = 0; i < 3; i++)
		{
			if (tep[i] != NULL&&tep[i + 1] == NULL || tep[i] == NULL&&tep[i + 1] == NULL)
			{
				continue;
			}
			else if (tep[i] == NULL&&tep[i + 1] != NULL || tep[i]->cost > tep[i + 1]->cost)
			{
				node* temp = tep[i + 1];
				tep[i + 1] = tep[i];
				tep[i] = temp;
				change = 1;
			}
		}
	}
}
bool greedy::islegal(int row, int col)
{
	if (row >= 0 && row <= 2 && col >= 0 && col <= 2) {
		return true;
	}
	else
		return false;
}
void greedy::solve2()
{
	if (S.size()>20)
	{
		//	cout << "fail: " << S.size() << endl;
		/*fail = 1;
		failnum++;
		totalnum++;
		resetstack();*/
		return;
	}
	if (cost(current) == 0)
	{
		//	cout << "success: " << S.size() << endl;
		succeed = 1;
		succeednum++;
		totalnum++;
		totalstep += S.size();
		showway();
		return;
	}
	node** tep = new node*[4];
	tep = findway(current);
	sort(tep);

	for (int i = 0; i < 4; i++)
	{
		if (tep[i] != NULL)
		{
			current = tep[i];
			S.push(tep[i]->direction);
			//	cout << S.size() << endl;
			solve2();
			if (succeed == 1 )
			{
				break;
			}
			else
				S.pop();
		}
	}

}
void greedy::solve()
{
	if (S.size() > 100)
	{
	//	cout << "fail: " << S.size() << endl;
		fail = 1;
		failnum++;
		totalnum++;
		resetstack();
		return;
	}
	if (cost(current) == 0)
	{
	//	cout << "success: " << S.size() << endl;
		succeed = 1;
		succeednum++;
		totalnum++;
		totalstep += S.size();
		showway();
		return;
	}
	node** tep = new node*[4];
	tep = findway(current);
		sort(tep);
		
		for (int i = 0; i < 4; i++)
		{
			if (tep[i] != NULL)
			{
				current = tep[i];
				S.push(tep[i]->direction);
			//	cout << S.size() << endl;
				solve();
				if (succeed == 1||fail==1)
				{
					break;
				}
				else
					S.pop();
			}
		}
	
}
int greedy::cost(node* _current)
{
	int count = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (_current->matrix[i][j] != 0 && _current->matrix[i][j] != end[i][j])
			{
				count++;
			}
		}
	}
	return count;
}
greedy::greedy() 
{	
	start = new node;
	succeed = 0;
	failnum = 0;
	succeednum = 0;
	avg_succeed = 0;
	totalnum = 0;
	totalstep = 0;
}
void generate(int** a)
{
	//srand((unsigned)time(NULL));
	int b[9] = { 0,1,2,3,4,5,6,7,8 };
	for (int i = 0; i < 8; i++)
	{
		swap(b[i], b[rand() % (8 - i) + i + 1]);
	}
	for (int k = 0; k < 9; k++)
	{
		int i = k / 3;
		int j = k % 3;
		a[i][j] = b[k];
	}
}

void random(int** a,int** b)
{
	int x;
	int y;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			b[i][j] = a[i][j];
			if (a[i][j] == 0) {
				x = i;
				y = j;
			}
		}
	}
//	srand((unsigned)time(NULL));
	for (int i = 0; i < changetime; i++)
	{
		int z = rand() % 5;
	//	cout << z << endl;
		switch (z)
		{
		case 0:
			break;
		case 1:
			if (x - 1 >= 0) {
				swap(b[x][y], b[x - 1][y]);
				x = x - 1;
			}
			break;
		case 2:
			if (x + 1 <= 2) {
				swap(b[x][y], b[x + 1][y]);
				x = x + 1;
			}
			break;
		case 3:
			if (y - 1 >= 0) {
				swap(b[x][y], b[x][y - 1]);
				y = y - 1;
			}
			break;
		case 4:
			if (y + 1 <= 2) {
				swap(b[x][y], b[x][y + 1]);
				y = y + 1;
			}
			break;
		}
	}
}

int main() 
{
	srand((unsigned)time(NULL));
	int** start;
	start = new int*[3];
	for (int i = 0; i < 3; i++)
		start[i] = new int[3];
	int** end;
	end = new int*[3];
	for (int i = 0; i < 3; i++)
		end[i] = new int[3];
	int** a = new int*[3];
	for (int i = 0; i < 3; i++)
		a[i] = new int[3];
	int** b = new int*[3];
	for (int i = 0; i < 3; i++)
		b[i] = new int[3];
	greedy test;
	greedy test2;
	for (int i = 0; i < trytime; i++) 
	{
		generate(a);
		/*for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << a[i][j] << " ";
			}
			cout << endl;
		}*/
		random(a, b);
		/*
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << b[i][j] << " ";
			}
			cout << endl;
		}*/
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				start[i][j] = a[i][j];
				end[i][j] = b[i][j];
			}
		}
		/*cout << "start: " << endl;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << start[i][j] << " ";
			}
			cout << endl;
		}
		cout << "end: " << endl;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << end[i][j] << " ";
			}
			cout << endl;
		} */
		int same = 1;
		for (int m = 0; m < 3; m++) {
			for (int n = 0; n < 3; n++) {
				if (start[m][n] != end[m][n])
				{
					same = 0;
				}
			}
		}
		if (same != 1) {
			test.create(start, end);
			test.solve();
			test2.create(start, end);
			test2.solve2();
			if (test2.getfail() != 1) {
				cout << "start: " << endl;
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						cout << start[i][j] << " ";
					}
					cout << endl;
				}
				cout << "end: " << endl;
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						cout << end[i][j] << " ";
					}
					cout << endl;
				}
			}
		}
	}
	test.showstatistics();
	test2.showstatistics2();
	system("pause");
	return 0;

}