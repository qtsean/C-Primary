#include<iostream>
#include<cstdlib>
using namespace std;

int main()
{
	cout << "GPA计算器" << endl;
	cout << "优秀或90-100\t4分" << endl;
	cout << "良好或80-89\t3分" << endl;
	cout << "70-79\t\t2分" << endl;
	cout << "合格先不算" << endl;
	cout << "按-1结束输入" << endl;
	double totalcredit=0;
	double totalscore=0;
	double score;
	double credit;
	int i = 1;
	cout << "输入第"<<i<<"门课4分制成绩： " << endl;
	cin >> score;
	cout << "输入第"<<i<<"门课学分： " << endl;
	cin >> credit;
	while (1)
	{
		totalscore += score * credit;
		totalcredit += credit;
		i++;
		cout << "输入第" << i << "门课成绩： " << endl;
		cin >> score;
		if (score == -1)
			break;
		cout << "输入第" << i << "门课学分： " << endl;
		cin >> credit;
	}
	cout << "GPA:  " << 1.0*totalscore / totalcredit;
	system("pause");
	return 0;
}