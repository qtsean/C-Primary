#include<iostream>
#include<cstdlib>
#include<queue>
#include<stack>
#include<ctime>
#define changetime 40
#define trytime 30000
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
	int depth;
	int distance;//每个不在正确位置的点到正确位置的距离
	int enimate;//cost+distance
};
stack<int> S;
queue<node*> Q;
stack<node*> S1;
class arr
{
public:
	node ** element;
	int size;
	arr();
	void insert(node*);
	void del(node*);
	void sortarr();
	node* find(node*);
};
node* arr::find(node*current)
{
	for (int i = 0; i < size; i++)
	{
		bool equal = 1;
		for (int j = 0; j < 3; j++)
		{
			for (int m = 0; m < 3; m++)
			{
				if (element[i]->matrix[j][m] != current->matrix[j][m])
				{
					equal = 0;
				}
			}
		}
		if (equal == 1)
		{
			return element[i];
		}
	}
	return NULL;
}
void arr::sortarr()
{
	bool change = 1;
	while (change == 1)
	{
		change = 0;
		for (int i = 0; i < size - 1; i++)
		{
			if (element[i]->enimate > element[i + 1]->enimate)
			{
				node*temp = element[i + 1];
				element[i + 1] = element[i];
				element[i] = temp;
				change = 1;
				break;
			}
		}
	}
}
void arr::del(node*current)
{
	for (int i = 0; i < size; i++)
	{
		if (current == element[i])
		{
			for (int j = i; j < size - 1; j++)
			{
				element[j] = element[j + 1];
			}
			size--;
		}
		break;
	}
}
arr::arr()
{
	element = new node*[10000];
	size = 0;
}
void arr::insert(node* current)
{
	element[size] = current;
	size++;
}
arr live;
arr dead;
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
		int steps;
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
		void showstatistics(int flag);
		void showstatistics2();
		void resetstack();
		int getfail();
		void free(node* current);
		node* getstart();
		void setNULL(node* current);
		void solve3();
		void showway2();
		void showparent(node*);
		void resetqueue();
		void resetstack2();
		int hfunc(node*);
		void solve4();
		void findwayA(node*);
};
void greedy::solve4()
{
	totalnum++;
	live.insert(start);
	while (live.size > 0)
	{
		live.sortarr();
		if (hfunc(live.element[0]) == 0)
		{
			totalstep += live.element[0]->depth;
			succeednum++;
			showway2();
			live.size = 0;
			dead.size = 0;
			return;
		}
		current = live.element[0];
		findwayA(live.element[0]);
		live.del(current);
		dead.insert(current);
		//cout << "live: "<<live.size << endl;
		//cout << "dead: "<<dead.size << endl;
	}
	failnum++;
}
void greedy::findwayA(node*_current)
{
	if (islegal(_current->row - 1, _current->col) && ((_current->row - 1 != _current->parent->row) || (_current->col != _current->parent->col)))
	{
		_current->nextup = new node;
		setNULL(_current->nextup);
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
		_current->nextup->row = _current->row - 1;
		_current->nextup->col = _current->col;
		_current->nextup->depth = _current->depth + 1;
		_current->nextup->enimate = current->nextup->depth + hfunc(current->nextup);
		if (live.find(_current->nextup) == NULL && dead.find(_current->nextup) == NULL)
		{
			live.insert(_current->nextup);
		}
		else if (live.find(_current->nextup) !=NULL)
		{
			node* t = live.find(_current->nextup);
			if (t->enimate > _current->nextup->enimate)
			{
				t->enimate = current->nextup->enimate;
				t->parent = current->nextup->parent;
				//delete current->nextup;
			}
		}
		else if (dead.find(current->nextup) != NULL)
		{
			node* t = dead.find(_current->nextup);
			if(t->enimate > _current->nextup->enimate)
			{
				t->enimate = current->nextup->enimate;
				t->parent = current->nextup->parent;
				//delete current->nextup;
				live.insert(t);
				dead.del(t);
			}
		}
	}
	if (islegal(_current->row + 1, _current->col) && ((_current->row + 1 != _current->parent->row) || (_current->col != _current->parent->col)))
	{
		_current->nextdown = new node;
		setNULL(_current->nextdown);
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				_current->nextdown->matrix[i][j] = _current->matrix[i][j];
			}
		}
		int temp = _current->matrix[_current->row + 1][_current->col];
		_current->nextdown->matrix[_current->row + 1][_current->col] = 0;
		_current->nextdown->matrix[_current->row][_current->col] = temp;
		_current->nextdown->cost = cost(_current->nextdown);
		_current->nextdown->parent = _current;
		_current->nextdown->row = _current->row + 1;
		_current->nextdown->col = _current->col;
		_current->nextdown->depth = _current->depth + 1;
		_current->nextdown->enimate = current->nextdown->depth + hfunc(current->nextdown);
		if (live.find(_current->nextdown) == NULL && dead.find(_current->nextdown) == NULL)
		{
			live.insert(_current->nextdown);
		}
		else if (live.find(_current->nextdown) != NULL)
		{
			node* t = live.find(_current->nextdown);
			if (t->enimate > _current->nextdown->enimate)
			{
				t->enimate = current->nextdown->enimate;
				t->parent = current->nextdown->parent;
				//delete current->nextdown;
			}
		}
		else if (dead.find(current->nextdown) != NULL)
		{
			node* t = dead.find(_current->nextdown);
			if (t->enimate > _current->nextdown->enimate)
			{
				t->enimate = current->nextdown->enimate;
				t->parent = current->nextdown->parent;
				//delete current->nextdown;
				live.insert(t);
				dead.del(t);
			}
		}
	}
	if (islegal(_current->row , _current->col-1) && ((_current->row  != _current->parent->row) || (_current->col-1 != _current->parent->col)))
	{
		_current->nextleft = new node;
		setNULL(_current->nextleft);
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				_current->nextleft->matrix[i][j] = _current->matrix[i][j];
			}
		}
		int temp = _current->matrix[_current->row ][_current->col-1];
		_current->nextleft->matrix[_current->row ][_current->col-1] = 0;
		_current->nextleft->matrix[_current->row][_current->col] = temp;
		_current->nextleft->cost = cost(_current->nextleft);
		_current->nextleft->parent = _current;
		_current->nextleft->row = _current->row;
		_current->nextleft->col = _current->col-1;
		_current->nextleft->depth = _current->depth + 1;
		_current->nextleft->enimate = current->nextleft->depth + hfunc(current->nextleft);
		if (live.find(_current->nextleft) == NULL && dead.find(_current->nextleft) == NULL)
		{
			live.insert(_current->nextleft);
		}
		else if (live.find(_current->nextleft) != NULL)
		{
			node* t = live.find(_current->nextleft);
			if (t->enimate > _current->nextleft->enimate)
			{
				t->enimate = current->nextleft->enimate;
				t->parent = current->nextleft->parent;
				//delete current->nextleft;
			}
		}
		else if (dead.find(current->nextleft) != NULL)
		{
			node* t = dead.find(_current->nextleft);
			if (t->enimate > _current->nextleft->enimate)
			{
				t->enimate = current->nextleft->enimate;
				t->parent = current->nextleft->parent;
				//delete current->nextleft;
				live.insert(t);
				dead.del(t);
			}
		}
	}
	if (islegal(_current->row, _current->col + 1) && ((_current->row != _current->parent->row) || (_current->col + 1 != _current->parent->col)))
	{
		_current->nextright = new node;
		setNULL(_current->nextright);
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				_current->nextright->matrix[i][j] = _current->matrix[i][j];
			}
		}
		int temp = _current->matrix[_current->row][_current->col + 1];
		_current->nextright->matrix[_current->row][_current->col + 1] = 0;
		_current->nextright->matrix[_current->row][_current->col] = temp;
		_current->nextright->cost = cost(_current->nextright);
		_current->nextright->parent = _current;
		_current->nextright->row = _current->row;
		_current->nextright->col = _current->col + 1;
		_current->nextright->depth = _current->depth + 1;
		_current->nextright->enimate = current->nextright->depth + hfunc(current->nextright);
		if (live.find(_current->nextright) == NULL && dead.find(_current->nextright) == NULL)
		{
			live.insert(_current->nextright);
		}
		else if (live.find(_current->nextright) != NULL)
		{
			node* t = live.find(_current->nextright);
			if (t->enimate > _current->nextright->enimate)
			{
				t->enimate = current->nextright->enimate;
				t->parent = current->nextright->parent;
				//delete current->nextright;
			}
		}
		else if (dead.find(current->nextright) != NULL)
		{
			node* t = dead.find(_current->nextright);
			if (t->enimate > _current->nextright->enimate)
			{
				t->enimate = current->nextright->enimate;
				t->parent = current->nextright->parent;
				//delete current->nextright;
				live.insert(t);
				dead.del(t);
			}
		}
	}
}

int greedy::hfunc(node* current)
{
	int count = 0;
	int x1;
	int y1;
	int x2;
	int y2;
	for (int i = 1; i < 9; i++)
	{
		for (int j = 0; j < 3; j++) 
		{
			for (int m = 0; m < 3; m++)
			{
				if (current->matrix[j][m] == i)
				{
					x1 = j;
					y1 = m;
				}
			}
		}
		for (int j = 0; j < 3; j++)
		{
			for (int m = 0; m < 3; m++)
			{
				if (end[j][m] == i)
				{
					x2 = j;
					y2 = m;
				}
			}
		}
		count += abs(x1 - x2) + abs(y1 - y2);
	}
	return count;
}
void greedy::resetstack2()
{
	while (S1.size() != 0)
	{
		S1.pop();
	}
}
void greedy::resetqueue()
{
	while (Q.size() != 0) 
	{
		Q.pop();
	}
}
void greedy::showparent(node* current)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << current->matrix[i][j]<<" ";
		}
		cout << endl;
	}
}
void greedy::showway2()
{
	//static int j = 0;
	//j++;
	//cout << j << endl;
	int i = 0;
	while (current->col != 100)
	{
		S1.push(current);
		current = current->parent;
	}
	while (S1.size() > 0)
	{
		//cout << "第"<<i << "次 :" << endl;
		current = S1.top();
		S1.pop();
	//	showparent(current);
		i++;
	}
}
void greedy::solve3()
{
	totalnum++;
	Q.push(current);
	while (Q.size()>0)
	{
		if (cost(current) == 0)
		{
			totalstep += current->depth;
			succeednum++;
			steps = current->depth;
			resetqueue();
			showway2();
			break;
		}
		if (islegal(current->row - 1, current->col) && current->depth + cost(current) < changetime && ((current->row - 1 != current->parent->row) || (current->col != current->parent->col)))
		{
			current->nextup = new node;
			setNULL(current->nextup);
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					current->nextup->matrix[i][j] = current->matrix[i][j];
				}
			}
			int temp = current->matrix[current->row - 1][current->col];
			current->nextup->matrix[current->row - 1][current->col] = 0;
			current->nextup->matrix[current->row][current->col] = temp;
			current->nextup->cost = cost(current->nextup);
			current->nextup->parent = current;
			current->nextup->direction = 1;
			current->nextup->row = current->row - 1;
			current->nextup->col = current->col;
			current->nextup->depth = current->depth + 1;
			Q.push(current->nextup);
			S.push(current->nextup->direction);
		}
		if (islegal(current->row + 1, current->col) && current->depth + cost(current) < changetime && ((current->row + 1 != current->parent->row) || (current->col != current->parent->col)))
		{
			current->nextdown = new node;
			setNULL(current->nextdown);
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					current->nextdown->matrix[i][j] = current->matrix[i][j];
				}
			}
			int temp = current->matrix[current->row + 1][current->col];
			current->nextdown->matrix[current->row + 1][current->col] = 0;
			current->nextdown->matrix[current->row][current->col] = temp;
			current->nextdown->cost = cost(current->nextdown);
			current->nextdown->parent = current;
			current->nextdown->direction = 2;
			current->nextdown->row = current->row + 1;
			current->nextdown->col = current->col;
			current->nextdown->depth = current->depth + 1;
			Q.push(current->nextdown);
			S.push(current->nextdown->direction);
		}
		if (islegal(current->row, current->col-1) && current->depth + cost(current) <changetime  && ((current->row != current->parent->row) || (current->col - 1 != current->parent->col)))
		{
			current->nextleft = new node;
			setNULL(current->nextleft);
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					current->nextleft->matrix[i][j] = current->matrix[i][j];
				}
			}
			int temp = current->matrix[current->row ][current->col-1];
			current->nextleft->matrix[current->row ][current->col-1] = 0;
			current->nextleft->matrix[current->row][current->col] = temp;
			current->nextleft->cost = cost(current->nextleft);
			current->nextleft->parent = current;
			current->nextleft->direction = 3;
			current->nextleft->row = current->row;
			current->nextleft->col = current->col-1;
			current->nextleft->depth = current->depth + 1;
			Q.push(current->nextleft);
			S.push(current->nextleft->direction);
		}
		if (islegal(current->row, current->col + 1) && current->depth + cost(current) <changetime && ((current->row != current->parent->row) || (current->col + 1 != current->parent->col)))
		{
			current->nextright = new node;
			setNULL(current->nextright);
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					current->nextright->matrix[i][j] = current->matrix[i][j];
				}
			}
			int temp = current->matrix[current->row][current->col + 1];
			current->nextright->matrix[current->row][current->col + 1] = 0;
			current->nextright->matrix[current->row][current->col] = temp;
			current->nextright->cost = cost(current->nextright);
			current->nextright->parent = current;
			current->nextright->direction = 4;
			current->nextright->row = current->row;
			current->nextright->col = current->col + 1;
			current->nextright->depth = current->depth + 1;
			Q.push(current->nextright);
			S.push(current->nextright->direction);
		}
		Q.pop();
		current = Q.front();
	}
	resetstack();
}
void greedy::setNULL(node* current)
{
	current->nextup = NULL;
	current->nextdown = NULL;
	current->nextleft = NULL;
	current->nextright = NULL;
}
node* greedy::getstart()
{
	return start;
}
void greedy::free(node* current)
{
	
	if (current == NULL)
		return;
	free(current->nextup);
	free(current->nextdown);
	free(current->nextleft);
	free(current->nextright);
	delete current;
	current = NULL;
	return;
}
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
void greedy::showstatistics(int flag)
{
	if(flag==1)
		cout << "贪婪法：" << endl;
	if(flag==2)
		cout << "必有解的贪婪法：" << endl;
	if (flag == 3)
		cout << "分支限界法： " << endl;
	if (flag == 4)
		cout << "启发法： " << endl;
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
	start = new node;
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
	start->nextup = NULL;
	start->nextdown = NULL;
	start->nextleft = NULL;
	start->nextright = NULL;
	current = start;
	start->cost = cost(start);
	start->depth = 0;
	start->enimate = hfunc(start);
}
node** greedy::findway(node* _current)
{
	//_current->nextup = NULL;
	
	if (islegal(_current->row - 1, _current->col) && ((_current->row - 1 != _current->parent->row) || (_current->col != _current->parent->col)))
	{	
		_current->nextup = new node;
		setNULL(_current->nextup);
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
	//else {
	//	_current->nextup = NULL;
	//}
	//_current->nextdown = NULL;
	
	if (islegal(_current->row + 1, _current->col) && ((_current->row + 1 != _current->parent->row) || (_current->col != _current->parent->col)))
	{
		_current->nextdown = new node;
		setNULL(_current->nextdown);
		
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
	/*else
	{
		_current->nextdown = NULL;
	}*/
	//_current->nextleft = NULL;
	
	if (islegal(_current->row, _current->col - 1) && ((_current->row != _current->parent->row) || (_current->col - 1 != _current->parent->col)))
	{
		_current->nextleft = new node;
		setNULL(_current->nextleft);
		
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
	/*else
	{
		_current->nextleft = NULL;
	}*/
	//_current->nextright = NULL;
	
	if (islegal(_current->row, _current->col + 1) && ((_current->row != _current->parent->row) || (_current->col + 1 != _current->parent->col)))
	{
		_current->nextright = new node;
		setNULL(_current->nextright);
		
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
	/*else
	{
		_current->nextright = NULL;
	}*/
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
	delete mtr;
	delete length;
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
	if (S.size()>changetime)
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
	node** tep = findway(current);
	
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
	delete tep;
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
	node** tep = findway(current);
	
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
		delete tep;
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
	greedy test3;
	greedy test4;
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
	/*	cout << "start: " << endl;
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
		if (same != 1) 
		{
			static int j = 0;
			j++;
			cout << j << endl;
			test4.create(start, end);
			test4.solve4();
			test4.free(test4.getstart());
			test3.create(start, end);
			test3.solve3();
			test3.free(test3.getstart());
			test.create(start, end);
			test.solve();
			test.free(test.getstart());
			/*test2.create(start, end);
			test2.solve2();
			test2.free(test2.getstart());*/
			/*if (test2.getfail() != 1) 
			{
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
			}*/
		}
	}
	test.showstatistics(1);
	test2.showstatistics(2);
	test3.showstatistics(3);
	test4.showstatistics(4);
	system("pause");
	return 0;

}