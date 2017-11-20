#include<iostream>
#include<stdlib.h>
#include<ctime>
using namespace std;
int dsize = 500;
int divisor = 961;
struct node{
	pair<int, int>element;					//��element������pair
	int used;								//��used���ж����Ͱ��û�б��ù�
};
class lh {
private:
	node*dic;								//˽��Ԫ��Ϊָ��node��ָ��
public:
	lh(pair<int,int>*a);
	int search(int);
	int find(int);
};
int lh::find(int index) {
	return dic[search(index)].element.second;		//���ظ�������Ӧ��ֵ
}
int lh::search(int index) {
	int j = index%divisor;					//��ʼ��jΪ������divisor��ȡ����ֵ
	int i = j;								//����j��ֵ��i���Ժ������ж��Ƿ����������ɢ�б�
	if (dic[j].used != 0 && dic[j].element.first == index)		//������Ͱ����Ԫ��������Ϊindex����ֱ�����
		return j;								
	else if (dic[j].used == 0) {			//������Ͱδ�ù��������������
		return -1;
	}
	else {									//���Ͱ��������������Ϊindex����˳�������ң�ֱ���ҵ��������ɢ�б��������Ͱ
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
	dic = new node[divisor];					//��Ϊɢ�б����ռ�
	for (int i = 0; i < divisor; i++) {
		dic[i].used = 0;						//ȫ����ʼ��Ϊδ��
	}
	for (int i = 0; i < dsize; i++) {			//�����ֵ�
		if (dic[a[i].first%divisor].used == 0) {
			dic[a[i].first%divisor].element = a[i];
			dic[a[i].first%divisor].used = 1;
		}
		else {
			int count = 0;						//���ж��Ƿ���
			for (int j = a[i].first%divisor+1; count < divisor; j++) {		//����λ���ѱ�ռ�ã����ж���һ���㣬ֱ���п�λ���߱�����ȫ
				if (dic[j%divisor].used == 0) {
					dic[j%divisor].element = a[i];
					dic[j%divisor].used = 1;
					break;
				}
				count++;
			}
		}
	}
	cout << "����Ѵ�����ֵ䣺" << endl;
	for (int i = 0; i < divisor; i++) {
		if (dic[i].used != 0) {
			cout << "λ�ã�" << i <<"\t"<< "������" << dic[i].element.first << "\t" << "ֵ��" << dic[i].element.second << endl;
		}
	}
}
int main() {
	srand((unsigned)time(NULL));
	pair<int, int>*a = new pair<int, int>[dsize];
	cout << "������ֵ�:" << endl;
	for (int i = 0; i < dsize; i++) {
		a[i].first = rand();
		a[i].second = a[i].first + 1;
		cout << "������" << a[i].first << "\t" << "ֵ��" << a[i].second<<endl;
	}
	lh test1(a);
	cout << "������ҪѰ�ҵ�����ֵ" << endl;
	int index;
	cin >> index;
	int d=test1.search(index);
	if (d == -1) {
		cout << "������������" << endl;
	}
	else {
		cout << "��������Ӧ��ֵΪ��" << test1.find(index);
	}
	system("pause");
	return 0;
}