#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
using namespace std;

const int LIM = 10;			//�Ҷ��룬����Ϊ10

int ct;						//������ʱ����
int total;					//�ܼ�¼��

inline void eatline() { while (cin.get() != '\n')continue; }		//ȥ���س�

void input();				//��һ����������
void correct();				//�޸�����
void add();					//�������
void del();					//ɾ������
void statictis();			//ͳ��
void welcome();				//ϵͳ��ʼ
void read();				//���ļ���ȡ����
void reset();				//���޸ĺ�������ٵ����ļ�
void statistics1();			//��ѧ��ͳ��
void statistics2();			//������ͳ��
void statistics3();			//���ɼ�ͳ��
void statistics4();			//���ɼ�����ͳ��
void statistics5();			//���ɼ�����ͳ������
void math_range();			//��ѧ�ɼ�����ͳ��
void english_range();		//Ӣ��ɼ�����ͳ��
void introduction_range();	//���㵼�۳ɼ�����ͳ��


struct student				//�ṹ����ѧ������
{
	char name[20];			//����
	char number[20];		//ѧ��
	double math;			//��ѧ�ɼ�
	double english;			//Ӣ��ɼ�
	double introduction;	//���㵼�۳ɼ�
};
student stu;				//������ȡ��д���ļ�ʱʹ��
student list[100];			//��������������ѧ������

const char * file = "student.dat";	//�ļ���

void statistics5()
{
	int count_english = 0;		//��ѧ����ָ���ķ��������ڵ�����
	int count_math = 0;
	int count_introduction = 0;
	cout << "please input the score range: \n";		//�Զ���ɼ�����Ĵ�С
	cout << "from: ";
	double min;
	cin >> min;
	cout << "to: ";
	double max;
	cin >> max;
	if (min > max) {
		swap(min, max);
	}

	//ͳ������
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
	//�������
	cout << "English: " << count_english << " students" << endl;
	cout << "Math: " << count_math << " students" << endl;
	cout << "Introduction: " << count_introduction << " students" << endl;
}

void introduction_range()
{
	cout << "please input the Introduction score range: \n";		//��������
	cout << "from: ";
	double min;
	double max;
	cin >> min;
	cout << "to: ";
	cin >> max;
	cout << "here are the results: \n";			//�˺�������ɼ��������ڵ��˵�������Ϣ
	if (min > max)
	{
		swap(max, min);
	}
	bool found = 0;							//���λ�������ж��Ƿ��ҵ�
	for (int i = 0; i < total; i++)
	{
		//���������Ϣ
		if (list[i].introduction >= min&&list[i].introduction <= max)
		{
			cout << setw(LIM) << list[i].number << setw(LIM) << list[i].name
				<< setw(LIM) << setprecision(1) << list[i].math << setw(LIM) << setprecision(1) << list[i].english
				<< setw(LIM) << setprecision(1) << list[i].introduction << endl;
			found = 1;
		}
	}
	if (0 == found)		//���û�ҵ������
	{
		cout << "NO SUCH STUDENT \n";
	}
}
//����ͬ��
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
//����ͬ��
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
//�鿴��ѧ��ָ���ɼ������ڵ��˵�������Ϣ
void statistics4()
{
	while (1)			//���һ�β������˳���ֱ���û�ѡ���˳�
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
	cout << "please input student's score: ";			//����һ����������������гɼ�������ɼ���ͬ��ѧ����������Ϣ
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

void statistics2()										//������������ѧ����������Ϣ
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

void statistics1()									//������ѧ�ŵ�ѧ����������Ϣ
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

void reset()		//���ڰ�д��������д�������
{
	ofstream fout2(file, ios_base::out | ios_base::binary); //���ö������ļ�����ȡ��д����ӷ���
	if (!fout2.is_open())									//����򲻿��ļ��򱨴�
	{
		cerr << "Can't open " << file << "file for output: \n";
		exit(EXIT_FAILURE);
	}
	ct = 0;													//������¼��д����ļ�����ͬʱ��Ϊlist������
	while (ct<total)
	{
		strcpy(stu.number, list[ct].number);				//��stu���и�ֵ����
		strcpy(stu.name, list[ct].name);
		stu.math = list[ct].math;
		stu.english = list[ct].english;
		stu.introduction = list[ct].introduction;
		fout2.write((char *)&stu, sizeof stu);				//��ֵ��ɺ�д���ļ�
		ct++;
	}
	fout2.close();											//�ر������
	cout << "reset complete: \n";
	read();													//��ʾĿǰ�ļ�������
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
	ofstream fout(file, ios_base::out | ios_base::binary);		//�������
	if (!fout.is_open())
	{
		cerr << "Can't open " << file << "file for output: \n";
		exit(EXIT_FAILURE);
	}
	cout << "Enter student number (enter a blank line to quit):\n";			
	cin.get(stu.number, 20);				//����ѧ������Ϣ����Ҫ����ֹͣ
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
		fout.write((char *)&stu, sizeof stu);				//д��
		cout << "Enter student number (enter a blank line to quit):\n";
		cin.get(stu.number, 20);
	}
	fout.close();
	read();		//��ʾ�ļ�����
}

void correct()
{
	cout << "Enter the record you wish to correct: ";
	long rec;			//ȷ����Ҫ�޸ĵ��ļ�������
	cin >> rec;
	if (rec < 0 || rec >= total)		//�Ϸ��Լ���
	{
		cerr << "Invalid record number -- bye\n";
		exit(EXIT_FAILURE);
	}
	cout << "Your selection: " << endl;		//��ʾѡ���ѧ����Ϣ
	cout << setw(LIM) << list[rec].number << setw(LIM) << list[rec].name
		<< setw(LIM) << setprecision(1) << list[rec].math << setw(LIM) << setprecision(1) << list[rec].english
		<< setw(LIM) << setprecision(1) << list[rec].introduction << endl;
	eatline();								//��ʼ�޸�
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
	reset();								//д���޸ĺ�Ľ��
}

void add()									//��ĩβ���һ������
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
	long rec;							//ȷ��ɾ��������
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
	for (int i = rec; i<total - 1; i++)		//�Ѻ�������������ǰ��һ��
	{
		list[i] = list[i + 1];
	}
	total--;								//������һ
	reset();								//д��
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
	cout << fixed << right;			//�Ҷ���
	ifstream fin;
	fin.open(file, ios_base::in | ios_base::binary);		//�򿪶�����������
	ct = 0;
	if (fin.is_open())				//����ļ����Դ򿪣����к�������
	{
		cout << "Here are the current student information\n";
		while (fin.read((char *)&stu, sizeof stu))
		{	//���ļ�����������Ҵ���list�ṹ����
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
		total = ct;		//ͳ������
		fin.close();
	}
	else
	{
		cout << "file does not exist, please input first\n";			//�ļ������ڣ��򴴽�һ���µ��ļ���
		input();
	}
}

int main()
{
	start();
}