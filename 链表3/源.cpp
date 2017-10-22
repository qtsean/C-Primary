#include"chain.h"
#include"chainNode.h"
#include"linearList.h"
#include"myExceptions.h"
#include<stdlib.h>
int main() {
	chain<int> a(5);
	a.output(cout);
	a.reverse();
	a.output(cout);
	system("pause");
}
