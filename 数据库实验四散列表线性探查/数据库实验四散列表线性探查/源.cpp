#include<iostream>
#include<stdlib.h>
#include<ctime>
using namespace std;
int dsize = 500;
int divisor = 961;
struct node{
	pair<int, int>element;					//用element来储存pair
	int used;								//用used来判断这个桶有没有被用过
};
class lh {
private:
	node*dic;								//私有元素为指向node的指针
public:
	lh(pair<int,int>*a);
	int search(int);
	int find(int);
};
int lh::find(int index) {
	return dic[search(index)].element.second;		//返回该索引对应的值
}
int lh::search(int index) {
	int j = index%divisor;					//初始化j为索引对divisor的取余后的值
	int i = j;								//保存j的值到i，以后用来判断是否遍历了整个散列表
	if (dic[j].used != 0 && dic[j].element.first == index)		//如果这个桶内有元素且索引为index，则直接输出
		return j;								
	else if (dic[j].used == 0) {			//如果这个桶未用过，则输出不存在
		return -1;
	}
	else {									//如果桶内有数且索引不为index，则顺序往后找，直到找到或遍历完散列表或遇到空桶
		do {
			j = (j + 1) % divisor;
			if (dic[j].element.first == index) {
				return j;
			}
		} while (i != j);
	}
	return -1;

}
lh::lh(pair<int, int>*a) {
	dic = new node[divisor];					//先为散列表创建空间
	for (int i = 0; i < divisor; i++) {
		dic[i].used = 0;						//全部初始化为未用
	}
	for (int i = 0; i < dsize; i++) {			//插入字典
		if (dic[a[i].first%divisor].used == 0) {
			dic[a[i].first%divisor].element = a[i];
			dic[a[i].first%divisor].used = 1;
		}
		else {
			int count = 0;						//来判断是否满
			for (int j = a[i].first%divisor+1; count < divisor; j++) {		//若该位置已被占用，则判断下一个点，直到有空位或者遍历完全
				if (dic[j%divisor].used == 0) {
					dic[j%divisor].element = a[i];
					dic[j%divisor].used = 1;
					break;
				}
				count++;
			}
		}
	}
	cout << "输出已存入的字典：" << endl;
	for (int i = 0; i < divisor; i++) {
		if (dic[i].used != 0) {
			cout << "位置：" << i <<"\t"<< "索引：" << dic[i].element.first << "\t" << "值：" << dic[i].element.second << endl;
		}
	}
}
int main() {
	srand((unsigned)time(NULL));
	pair<int, int>*a = new pair<int, int>[dsize];
	cout << "输入的字典:" << endl;
	for (int i = 0; i < dsize; i++) {
		a[i].first = rand();
		a[i].second = a[i].first + 1;
		cout << "索引：" << a[i].first << "\t" << "值：" << a[i].second<<endl;
	}
	lh test1(a);
	cout << "输入需要寻找的索引值" << endl;
	int index;
	cin >> index;
	int d=test1.search(index);
	if (d == -1) {
		cout << "该索引不存在" << endl;
	}
	else {
		cout << "该索引对应的值为：" << test1.find(index);
	}
	system("pause");
	return 0;
}