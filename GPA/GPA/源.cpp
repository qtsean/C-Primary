#include<iostream>
#include<cstdlib>
using namespace std;

int main()
{
	cout << "GPA������" << endl;
	cout << "�����90-100\t4��" << endl;
	cout << "���û�80-89\t3��" << endl;
	cout << "70-79\t\t2��" << endl;
	cout << "�ϸ��Ȳ���" << endl;
	cout << "��-1��������" << endl;
	double totalcredit=0;
	double totalscore=0;
	double score;
	double credit;
	int i = 1;
	cout << "�����"<<i<<"�ſ�4���Ƴɼ��� " << endl;
	cin >> score;
	cout << "�����"<<i<<"�ſ�ѧ�֣� " << endl;
	cin >> credit;
	while (1)
	{
		totalscore += score * credit;
		totalcredit += credit;
		i++;
		cout << "�����" << i << "�ſγɼ��� " << endl;
		cin >> score;
		if (score == -1)
			break;
		cout << "�����" << i << "�ſ�ѧ�֣� " << endl;
		cin >> credit;
	}
	cout << "GPA:  " << 1.0*totalscore / totalcredit;
	system("pause");
	return 0;
}