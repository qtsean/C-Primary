#include<iostream>
#include<stdlib.h>
using namespace std;
void fp(int* number, int *arr, bool* unused , int n, int length){
	if (0 == n) {											//如果n已经为0，代表已经记录每一个整数，开始进行输出
		for (int i = 0; i < length; i++) {
			cout << number[i]<<"\t";
		}
		cout << endl;
	}
	else {														//如果n大于0，则继续进行递归
		for (int i = 0; i < length; i++) {						//循环n次
			if (unused[i] == true) {							//先判断那个整数有没有被用过，如果用过则跳过，没用过则继续后续步骤
				number[length - n] = arr[i];					//每一层递归所用的数位是相同的，把数组中的数传给那个数位
				unused[i] = false;								//用完后标记为已用，在后续的递归中这个数不再出现
				fp(number, arr, unused, n - 1, length);			//递归语句，每次n-1
				unused[i] = true;								//再把这个数位设置为未用，以便这一层递归中的循环语句可以进行
			}
		}
	}
}
int main() {
	int n;														//此处为了实验，用n生成了一个从0开始的数组arr
	cin >> n;
	int * arr = new int[n];
	for (int i = 0; i < n; i++) {
		arr[i] = i;
	}
	int * number = new int[n] ;									//用来记录每一层循环中所用的数字
	bool * unused = new bool[n];								//用来标记某个数字是否已用过
	for (int i = 0; i < n; i++) {								//先全部初始化为未用
		unused[i] = true;
	}
	int length = n;												//因为数组长度n在递归中会改变，因此用length记录n的值
	fp(number, arr, unused, n, length);							//递归开始
	system("pause");
}