#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;
struct weight {
	char text;										//输入的字符内容
	int element;									//用0或1标记叶节点和根节点
	int frq;										//频率
	weight* left;			
	weight* right;
};
class huffman {
private:
	weight** tempnode;								//用来储存指向weight的指针的数组
	weight* tree;									//合成后的二叉树的根节点
	int count;										//不同字符数
	char txt[1000];									//储存原始文本，在输出编码时使用
	bool route[50];									//根节点到叶节点的路径，每个字符对应不同的路径即不同的编码
	int steps;										//步数
	bool found;							
public:
	huffman(weight* ip,int count,char* text);		//构造函数
	//void initialize();
	weight* pop();									//弹出最小堆的根节点
	void push(weight*);								//把一个元素插入最小堆
	void sort();									//对最小堆排序
	weight* combine(weight* left, weight* right);	//把两个二叉树合并
	void show();									//输出一个字符的编码
	void findway(char a,weight* current);			//输入一个字符，找到这个字符对应的编码
};
void huffman::findway(char a,weight* current) {
	if (current->element == 1 && a == current->text) {		//判断是否找到
		show();
	}
	if (current->left != NULL) {					//迭代寻找
		route[steps] = 0;
		steps++;
		findway(a, current->left);
		steps--;
	}
	if (current->right != NULL) {
		route[steps] = 1;
		steps++;
		findway(a, current->right);
		steps--;
	}
}
void huffman::show() {
	for (int i = 0; i < steps; i++) {				//输出每一步走的方向，即0或1
		cout << route[i];
	}
	cout << endl;
}
void huffman::push(weight* a) {
	tempnode[count] = a;
	count++;
}
weight* huffman::combine(weight* a, weight* b) {
	weight* c;										//创建一个节点，作为合并的两个子树的根节点
	c = new weight;
	c->element = 0;
	c->frq = a->frq + b->frq;
	c->left = a;
	c->right = b;
	return c;
}
weight* huffman::pop() {
	weight *temp = tempnode[0];
	for (int i = 1; i < count; i++) {
		tempnode[i - 1] = tempnode[i];
	}
	count--;
	return temp;
}
huffman::huffman(weight* ip,int _count,char* text) {
	int steps = 0;
	for (int i = 0; text[i] != '\0'; i++) {
		txt[i] = text[i];
	}
	count = _count;
	tempnode = new weight*[count];					//把weight中的每一个元素的指针赋给tempnode数组
	for (int i = 0; i < count; i++) {
		tempnode[i] = new weight;
	}
	for (int i = 0; i < count; i++) {
		tempnode[i]->element = ip[i].element;
		tempnode[i]->frq = ip[i].frq;
		tempnode[i]->left = ip[i].left;
		tempnode[i]->right = ip[i].right;
		tempnode[i]->text = ip[i].text;
	}
	while (count > 1) {								//重复合并操作，直到只剩下一个根节点
		sort();
		push(combine(pop(), pop()));
	}
	tree = tempnode[0];								//把根节点赋值给tree
	for (int i = 0; txt[i] != '\0'; i++) {
		steps = 0;
		findway(txt[i], tree);
	}
}
void huffman::sort() {
	while (1) {										//最小堆排序，把最小的元素放在根节点
		bool change = false;
		for (int i = 0; i < count - 1; i++) {
			if (tempnode[i]->frq > tempnode[i + 1]->frq) {
				weight* temp = tempnode[i + 1];
				tempnode[i + 1] = tempnode[i];
				tempnode[i] = temp;
				change = true;
			}
		}
		if (change == false)
			break;
	}
}
int countwg(weight* wg) {							//计算不同字符的个数
	int count = 0;
	for (int i = 0; wg[i].element != -1; i++) {
		count++;
	}
	return count;
}
weight* statistic(char* input) {
	weight wg[1000];
	for (int i = 0; i < 1000; i++) {
		wg[i].element = -1;
		wg[i].frq = 0;
		wg[i].left = NULL;
		wg[i].right = NULL;
	}
	wg[0].text = input[0];
	wg[0].element = 1;
	wg[0].frq = 1;
	int wgl = 1;
	int ipl = 1;
	//如果已有相同字符，和频率加1，若还没有，则插入这个字符，频率设置为1

	while (1) {
		bool exist = 0;
		if (input[ipl] == '\0')
			break;
		for (int j = 0; j < wgl; j++) {
			if (wg[j].text == input[ipl]) {
				wg[j].frq++;
				ipl++;
				exist = 1;
				break;
			}
		}
		if (exist == 0) {
			wg[wgl].text = input[ipl];
			wg[wgl].frq++;
			wg[wgl].element = 1;
			wgl++;
			ipl++;
		}

	}
	return wg;
}
int main() {
	//char input[1000]="Early in the day it was whispered that we should sail in a boat,\
						only thou and I, and never a soul in the world would know of this our pilgrimage to no country and to no end.";	//输入的字符
	//cin >> input;
	char input[1000] = "hello world";
	weight* wg;			//weight数组
	wg = statistic(input);		//统计所有出现过的字符和每个字符的频率
	huffman test(wg, countwg(wg),input);
	system("pause");
}