#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
using namespace std;

const int LIM = 10;			//右对齐，长度为10

int ct;						//输出输出时计算
int total;					//总记录数

inline void eatline() { while (cin.get() != '\n')continue; }		//去除回车

void input();				//第一次输入数据
void correct();				//修改数据
void add();					//添加数据
void del();					//删除数据
void statictis();			//统计
void welcome();				//系统开始
void read();				//从文件读取数据
void reset();				//把修改后的数据再导入文件
void statistics1();			//按学号统计
void statistics2();			//按姓名统计
void statistics3();			//按成绩统计
void statistics4();			//按成绩区间统计
void statistics5();			//按成绩区间统计人数
void math_range();			//数学成绩区间统计
void english_range();		//英语成绩区间统计
void introduction_range();	//计算导论成绩区间统计


struct student				//结构保存学生数据
{
	char name[20];			//姓名
	char number[20];		//学号
	double math;			//数学成绩
	double english;			//英语成绩
	double introduction;	//计算导论成绩
};
student stu;				//用来读取和写入文件时使用
student list[100];			//程序中用来保存学生数据

const char * file = "student.dat";	//文件名

void statistics5()
{
	int count_english = 0;		//各学科在指定的分数区间内的人数
	int count_math = 0;
	int count_introduction = 0;
	cout << "please input the score range: \n";		//自定义成绩区间的大小
	cout << "from: ";
	double min;
	cin >> min;
	cout << "to: ";
	double max;
	cin >> max;
	if (min > max) {
		swap(min, max);
	}

	//统计人数
	for (int i = 0; i < total; i++)
	{
		if (list[i].english >= min&&list[i].english <= max)
		{
			count_english++;
		}
		if (list[i].math >= min&&list[i].math <= max)
		{
			count_math++;
		}
		if (list[i].introduction >= min&&list[i].introduction <= max)
		{
			count_introduction++;
		}
	}
	//输出人数
	cout << "English: " << count_english << " students" << endl;
	cout << "Math: " << count_math << " students" << endl;
	cout << "Introduction: " << count_introduction << " students" << endl;
}

void introduction_range()
{
	cout << "please input the Introduction score range: \n";		//输入区间
	cout << "from: ";
	double min;
	double max;
	cin >> min;
	cout << "to: ";
	cin >> max;
	cout << "here are the results: \n";			//此函数输出成绩在区间内的人的所有信息
	if (min > max)
	{
		swap(max, min);
	}
	bool found = 0;							//标记位，用来判断是否找到
	for (int i = 0; i < total; i++)
	{
		//输出所有信息
		if (list[i].introduction >= min&&list[i].introduction <= max)
		{
			cout << setw(LIM) << list[i].number << setw(LIM) << list[i].name
				<< setw(LIM) << setprecision(1) << list[i].math << setw(LIM) << setprecision(1) << list[i].english
				<< setw(LIM) << setprecision(1) << list[i].introduction << endl;
			found = 1;
		}
	}
	if (0 == found)		//如果没找到则输出
	{
		cout << "NO SUCH STUDENT \n";
	}
}
//基本同上
void english_range()	
{
	cout << "please input the english score range: \n";
	cout << "from: ";
	double min;
	double max;
	cin >> min;
	cout << "to: ";
	cin >> max;
	cout << "here are the results: \n";
	if (min > max)
	{
		swap(max, min);
	}
	bool found = 0;
	for (int i = 0; i < total; i++)
	{
		if (list[i].english >= min&&list[i].english <= max)
		{
			cout << setw(LIM) << list[i].number << setw(LIM) << list[i].name
				<< setw(LIM) << setprecision(1) << list[i].math << setw(LIM) << setprecision(1) << list[i].english
				<< setw(LIM) << setprecision(1) << list[i].introduction << endl;
			found = 1;
		}
	}
	if (0 == found)
	{
		cout << "NO SUCH STUDENT \n";
	}
}
//基本同上
void math_range()
{
	cout << "please input the math score range: \n";
	cout << "from: ";
	double min;
	double max;
	cin >> min;
	cout << "to: ";
	cin >> max;
	cout << "here are the results: \n";
	if (min > max)
	{
		swap(max, min);
	}
	bool found = 0;
	for (int i = 0; i < total; i++)
	{
		if (list[i].math >= min&&list[i].math <= max)
		{
			cout << setw(LIM) << list[i].number << setw(LIM) << list[i].name
				<< setw(LIM) << setprecision(1) << list[i].math << setw(LIM) << setprecision(1) << list[i].english
				<< setw(LIM) << setprecision(1) << list[i].introduction << endl;
			found = 1;
		}
	}
	if (0 == found)
	{
		cout << "NO SUCH STUDENT \n";
	}
}
//查看各学科指定成绩区间内的人的所有信息
void statistics4()
{
	while (1)			//完成一次操作后不退出，直到用户选择退出
	{
		cout << "please select a course \n";
		cout << "Math(1) " << "English(2) " << "Introduction(3) " << "quit(4) \n";
		int command;
		cin >> command;
		switch (command)
		{
		case 1:math_range();
			continue;
		case 2:english_range();
			continue;
		case 3:introduction_range();
			continue;
		case 4:break;
		}
		break;
	}
}


void statistics3()
{
	cout << "please input student's score: ";			//输入一个分数，输出所有有成绩与输入成绩相同的学生的所有信息
	double score;
	cin >> score;
	bool found = 0;
	for (int i = 0; i < total; i++)
	{
		if (list[i].math == score || list[i].english == score || list[i].introduction == score)
		{
			cout << setw(LIM) << list[i].number << setw(LIM) << list[i].name
				<< setw(LIM) << setprecision(1) << list[i].math << setw(LIM) << setprecision(1) << list[i].english
				<< setw(LIM) << setprecision(1) << list[i].introduction << endl;
			found = 1;
		}
	}
	if (0 == found)
	{
		cout << "NO SUCH STUDENT \n";
	}
}

void statistics2()										//输出这个姓名的学生的所有信息
{
	cout << "please input student name: ";
	char name[20];
	cin >> name;
	bool found = 0;
	for (int i = 0; i < total; i++)
	{
		if (!strcmp(list[i].name, name))
		{
			cout << setw(LIM) << list[i].number << setw(LIM) << list[i].name
				<< setw(LIM) << setprecision(1) << list[i].math << setw(LIM) << setprecision(1) << list[i].english
				<< setw(LIM) << setprecision(1) << list[i].introduction << endl;
			found = 1;
		}
	}
	if (0 == found)
	{
		cout << "NO SUCH STUDENT \n";
	}
}

void statistics1()									//输出这个学号的学生的所有信息
{
	cout << "please input student number: ";
	char num[20];
	cin >> num;
	bool found = 0;
	for (int i = 0; i < total; i++)
	{
		if (!strcmp(list[i].number, num))
		{
			cout << setw(LIM) << list[i].number << setw(LIM) << list[i].name
				<< setw(LIM) << setprecision(1) << list[i].math << setw(LIM) << setprecision(1) << list[i].english
				<< setw(LIM) << setprecision(1) << list[i].introduction << endl;
			found = 1;
		}
	}
	if (0 == found)
	{
		cout << "NO SUCH STUDENT \n";
	}
}

void reset()		//用于把写完后的数据写入程序中
{
	ofstream fout2(file, ios_base::out | ios_base::binary); //采用二进制文件，读取和写入更加方便
	if (!fout2.is_open())									//如果打不开文件则报错
	{
		cerr << "Can't open " << file << "file for output: \n";
		exit(EXIT_FAILURE);
	}
	ct = 0;													//用来记录已写入的文件数，同时作为list的索引
	while (ct<total)
	{
		strcpy(stu.number, list[ct].number);				//对stu进行赋值操作
		strcpy(stu.name, list[ct].name);
		stu.math = list[ct].math;
		stu.english = list[ct].english;
		stu.introduction = list[ct].introduction;
		fout2.write((char *)&stu, sizeof stu);				//赋值完成后，写入文件
		ct++;
	}
	fout2.close();											//关闭输出流
	cout << "reset complete: \n";
	read();													//显示目前文件的内容
}

void welcome()
{
	cout << "Welcomt to student information manage system" << endl;
}

void choices()
{
	cout << "Correct(C)" << "Add(A)" << "Delete(D)" << "Statistic(S)" << "Quit(Q)" << endl;
}

void input()
{
	ofstream fout(file, ios_base::out | ios_base::binary);		//打开输出流
	if (!fout.is_open())
	{
		cerr << "Can't open " << file << "file for output: \n";
		exit(EXIT_FAILURE);
	}
	cout << "Enter student number (enter a blank line to quit):\n";			
	cin.get(stu.number, 20);				//输入学生的信息，需要空行停止
	while (stu.number[0] != '\0')
	{
		eatline();
		cout << "Enter student name: ";
		cin >> stu.name;
		cout << "Enter his math score: ";
		cin >> stu.math;
		cout << "Enter his english score: ";
		cin >> stu.english;
		cout << "Enter his introduction score: ";
		cin >> stu.introduction;
		eatline();
		fout.write((char *)&stu, sizeof stu);				//写入
		cout << "Enter student number (enter a blank line to quit):\n";
		cin.get(stu.number, 20);
	}
	fout.close();
	read();		//显示文件内容
}

void correct()
{
	cout << "Enter the record you wish to correct: ";
	long rec;			//确定需要修改的文件的索引
	cin >> rec;
	if (rec < 0 || rec >= total)		//合法性检验
	{
		cerr << "Invalid record number -- bye\n";
		exit(EXIT_FAILURE);
	}
	cout << "Your selection: " << endl;		//显示选择的学生信息
	cout << setw(LIM) << list[rec].number << setw(LIM) << list[rec].name
		<< setw(LIM) << setprecision(1) << list[rec].math << setw(LIM) << setprecision(1) << list[rec].english
		<< setw(LIM) << setprecision(1) << list[rec].introduction << endl;
	eatline();								//开始修改
	cout << "Enter new student number :\n";
	cin.get(list[rec].number, 20);
	eatline();
	cout << "Enter new student name: ";
	cin.get(list[rec].name, 20);
	eatline();
	cout << "Enter new math score: ";
	cin >> list[rec].math;
	eatline();
	cout << "Enter new english score: ";
	cin >> list[rec].english;
	eatline();
	cout << "Enter new introduction score: ";
	cin >> list[rec].introduction;
	//eatline();
	reset();								//写入修改后的结果
}

void add()									//在末尾添加一行数据
{
	cout << "Enter new student number :\n";
	cin.clear();
	cin >> list[total].number;
	eatline();
	cout << "Enter new student name: ";
	cin >> list[total].name;
	eatline();
	cout << "Enter new math score: ";
	cin >> list[total].math;
	eatline();
	cout << "Enter new english score: ";
	cin >> list[total].english;
	eatline();
	cout << "Enter new introduction score: ";
	cin >> list[total].introduction;
	total++;
	reset();
}

void del()									
{
	cout << "Which one do you want to delete? \n";
	long rec;							//确定删除的索引
	cin >> rec;
	if (rec < 0 || rec >= total)
	{
		cerr << "Invalid record number -- bye\n";
		exit(EXIT_FAILURE);
	}
	cout << "Your selection: " << endl;
	cout << setw(LIM) << list[rec].number << setw(LIM) << list[rec].name
		<< setw(LIM) << setprecision(1) << list[rec].math << setw(LIM) << setprecision(1) << list[rec].english
		<< setw(LIM) << setprecision(1) << list[rec].introduction << endl;
	eatline();
	for (int i = rec; i<total - 1; i++)		//把后续的数据依次前移一格。
	{
		list[i] = list[i + 1];
	}
	total--;								//总数减一
	reset();								//写入
}

void statictis()
{
	while (1)
	{
		cout << "search by number(1) " << "search by name(2) " << "search by score(3) " << "search by score range(4) " << "static by score range(5) " << "quit(6) \n";
		int command;
		cin >> command;
		switch (command)
		{
		case 1:statistics1();
			continue;
		case 2:statistics2();
			continue;
		case 3:statistics3();
			continue;
		case 4:statistics4();
			continue;
		case 5:statistics5();
			continue;
		case 6:break;
		}
		break;
	}
}

void start()
{
	read();
	while (1)
	{
		welcome();
		choices();
		cin.clear();
		char command;
		cin >> command;
		switch (command)
		{
			/*	case 'i':
			case 'I':input();
			continue;*/
		case 'c':
		case 'C':correct();
			continue;
		case 'a':
		case 'A':add();
			continue;
		case 'd':
		case 'D':del();
			continue;
		case 's':
		case 'S':statictis();
			continue;
		case 'q':
		case 'Q':break;
		default:cout << "invalid command, try again" << endl;
			continue;
		}
		break;
	}
}

void read()
{
	cout << fixed << right;			//右对齐
	ifstream fin;
	fin.open(file, ios_base::in | ios_base::binary);		//打开二进制输入流
	ct = 0;
	if (fin.is_open())				//如果文件可以打开，进行后续操作
	{
		cout << "Here are the current student information\n";
		while (fin.read((char *)&stu, sizeof stu))
		{	//把文件内容输出并且存入list结构数组
			strcpy(list[ct].name, stu.name);
			strcpy(list[ct].number, stu.number);
			list[ct].english = stu.english;
			list[ct].math = stu.math;
			list[ct].introduction = stu.introduction;
			cout << ct << ":" << "  number: " << setw(LIM) << list[ct].number << "  name: " << setw(LIM) << list[ct].name << "  math: "
				<< setw(LIM) << setprecision(1) << list[ct].math << "  english: " << setw(LIM) << setprecision(1) << list[ct].english << "  introduction: "
				<< setw(LIM) << setprecision(1) << list[ct].introduction << endl;
			ct++;
			/*cout << ct++ << ":" << setw(LIM) << stu.number << setw(LIM) << stu.name
			<< setw(LIM) << setprecision(1) << stu.math << setw(LIM) << setprecision(1) << stu.englsih
			<< setw(LIM) << setprecision(1) << stu.introduction << endl;*/
		}
		total = ct;		//统计总数
		fin.close();
	}
	else
	{
		cout << "file does not exist, please input first\n";			//文件不存在，则创建一个新的文件。
		input();
	}
}

int main()
{
	start();
}