#include<iostream>
#include<cstdlib>
using namespace std;
void circle(double r, double *plength, double *parea) {
	*plength = 2 * 3.1415926*r;
	*parea = 3.1415926*r*r;
}
int main() {
	double length;
	double area;
	int r;
	cin >> r;
	circle(r, &length, &area);
	cout << "length:" << length << endl;
	cout << "area:" << area << endl;
	system("pause");
	return 0;
}