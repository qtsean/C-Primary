#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;
class Date 
{
private:
	int year, month, day;
	void SetSystemDate();
public:
	Date(int y = 1900, int m = 1, int d = 1) {
		year = y;
		month = m;
		day = d;
	}
	void init(int, int, int);
	void print_ymd();
	void print_mdy();
	int get_year() { return year; }
	int get_month() { return month; }
	int get_day() {return day;}
	bool IsLeapYear();
};
void Date::SetSystemDate()
{
	tm *gm;
	time_t t=time(NULL);
	gm = gmtime(&t);
	year = 1900 + gm->tm_year;
	month = gm->tm_mon + 1;
	day = gm->tm_mday;
}
void Date::init(int yy, int mm, int dd) {
	if (yy >= 1900 && yy <= 9999)
		year = yy;
	else {
		SetSystemDate();
		return;
	}
	if (mm >= 1 && mm <= 12)
		month = mm;
	else {
		SetSystemDate();
		return;
	}
	if (dd >= 1 && dd <= 31)
		day = dd;
	else {
		SetSystemDate();
		return;
	}
}
void Date::print_ymd() {
	cout << year << "-" << month << "-" << day << endl;
}
void Date::print_mdy() {
	cout << month << "-" << day << "-" << year << endl;
}
bool Date::IsLeapYear() {
	if (year % 400 == 0 || year % 100 != 0 && year % 4 == 0)
		return true;
	else
		return false;
}
int main() {
	Date date1;
	date1.print_ymd();
	system("pause");
	date1.init(2008, 3, 28);
	date1.print_ymd();
	system("pause");
	Date date2(2007,12,12);
	date2.print_mdy();
	system("pause");
	date2.init(2006, 13, 28);
	date2.print_mdy();
	system("pause");
	if (date1.IsLeapYear())
		cout << date1.get_year() << "ÊÇ" << endl;
	else
		cout << date1.get_year() << "is not" << endl;
	system("pause");
	return 0;
}