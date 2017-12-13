#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;
struct weight {
	char text;
	int element;
	int frq;
	weight* left;
	weight* right;
};
class huffman {
private:
	weight** tempnode;
	weight* tree;
	int count;
	char txt[1000];
	bool route[50];
	int steps;
	bool found;
public:
	huffman(weight* ip,int count,char* text);
	void initialize();
	weight* pop();
	void push(weight*);
	void sort();
	weight* combine(weight* left, weight* right);
	void show();
	void findway(char a,weight* current);
};
void huffman::findway(char a,weight* current) {
	if (current->element == 1 && a == current->text) {
		show();
	}
	if (current->left != NULL) {
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
	for (int i = 0; i < steps; i++) {
		cout << route[i];
	}
	cout << endl;
}
void huffman::push(weight* a) {
	tempnode[count] = a;
	count++;
}
weight* huffman::combine(weight* a, weight* b) {
	weight* c;
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
	tempnode = new weight*[count];
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
	while (count > 1) {
		sort();
		push(combine(pop(), pop()));
	}
	tree = tempnode[0];
	for (int i = 0; txt[i] != '\0'; i++) {
		steps = 0;
		findway(txt[i], tree);
	}
}
void huffman::sort() {
	while (1) {
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
int countwg(weight* wg) {
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
	char input[1000]="Early in the day it was whispered that we should sail in a boat,\
						only thou and I, and never a soul in the world would know of this our pilgrimage to no country and to no end.";
	//cin >> input;
	weight* wg;
	wg = statistic(input);
	huffman test(wg, countwg(wg),input);
	system("pause");
}