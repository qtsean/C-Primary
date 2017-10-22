#include"iostream"
#include"stdlib.h"
using namespace std;
int main()
{
	char name1[50];
	char name2[50];
	cin.getline(name1,50);
	cin.getline(name2,50);
	cout << "########################" << endl;
	cout << name1 << endl;
	cout << endl;
	cout << "happy birthday to you" << endl;
	cout << endl;
	cout << "    sincerely youres "<<name2<<endl;
	cout << "##########################" << endl;
	system("pause");
	return 0;
}