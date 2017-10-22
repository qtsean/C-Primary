#include<iostream>
#include<cstdlib>
#include<Windows.h>
using namespace std;
class Clock
{
private:
	int Hour;
	int Minute;
	int Second;
	float Price;
public:
	void Set(int h, int m, int s, float p);
	void Run();
	void Report_Time();
	void Show_Time() { cout << Hour << ":" << Minute << ":" << Second; };
};
void Clock::Set(int h, int m, int s, float p) {
	Hour = h;
	Minute = m;
	Second = s;
	Price = p;
}
void Clock::Run() {
	int i = 0;
	for (i = 0; i < 10; i++) {
		Second++;
		if (Second == 60) {
			Second = 0;
			Minute++;
			if (Minute == 60) {
				Minute = 0;
				Hour++;
				if (Hour == 24)
					Hour = 0;
			}
		}
		cout << '\r';
		Sleep(1000);
		Show_Time();
	}
}
void Clock::Report_Time() {
	Show_Time();
	if (Minute == 0 && Second == 0) {
		for (int i = 0; i < Hour; i++) {
			cout << "\007";
			Sleep(1000);
		}
	}
}
int main() {
	Clock XJTU_Big_Ben, Omega, Rossini;
	XJTU_Big_Ben.Set(0, 0, 0, 1000);
	cout << "clock set time:"<<endl;
	XJTU_Big_Ben.Show_Time();
	XJTU_Big_Ben.Report_Time();
	XJTU_Big_Ben.Run();
	XJTU_Big_Ben.Set(9, 59, 50, 9000);
	cout <<endl<< "clock set time:"<<endl;
	XJTU_Big_Ben.Run();
	XJTU_Big_Ben.Report_Time();
	cout << endl;
	XJTU_Big_Ben.Show_Time();
	cout << endl;
	system("pause");
	return 0;
}