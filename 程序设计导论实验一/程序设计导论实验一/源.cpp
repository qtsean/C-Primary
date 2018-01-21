#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;
struct planet {
	char name[20];
	double population;
	double g;
};
planet pl;
int main() {
	ofstream fout("planet.txt", ios_base::out | ios_base::app);
	strcpy(pl.name, "apple");
	pl.population = 200;
	pl.g = 9.9;
	fout << pl.name << pl.g << pl.population;
	system("pause");
	return 0;
}
