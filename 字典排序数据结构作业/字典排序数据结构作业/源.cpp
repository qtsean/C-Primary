#include<iostream>
#include<stdlib.h>
using namespace std;
template<class K,class E>
class SAL{
private:
	pair<K,E> * arr;
	int length;
	int size;
public:
	pair<K, E> find(const K& theKey);
	void insert(const pair<K, E>& thePair);
	void erase(const K& theKey);
	SAL(pair<K, E>*a, int length, int size);
	void show();
};
template<class K,class E>
void SAL<K, E>::show() {
	for (int i = 0; i < length; i++)
		cout << arr[i].first << "   " << arr[i].second << endl;
	cout << "length = " << length <<"      "<< "size = " << size << endl << endl;
}
template<class K,class E>
void SAL<K, E>::erase(const K& theKey) {
	for (int i = 0; i < length; i++) {
		if (theKey == arr[i].first) {
			for (int j = i; j < length; j++) {
				arr[j] = arr[j + 1];
			}
			length--;
		}
	}
	for (int i = 0; i < length; i++) {
		if (theKey == arr[i].first) {
			for (int j = i; j < length; j++) {
				arr[j] = arr[j + 1];
			}
			length--;
		}
	}
}
template<class K,class E>
void SAL<K,E>::insert(const pair<K, E>& thePair){
	if (length == size) {
		size = size * 2;
		pair<K, E> * temp = new pair<K, E>[size];
		for (int i = 0; i < length; i++) {
			temp[i] = arr[i];
		}
		delete arr;
		arr = temp;
	}
	for (int i = 0; i < length; i++) {
		if (thePair.first <= arr[i].first) {
			for (int j = length - 1; j >= i; j--) {
				arr[j + 1] = arr[j];
			}
			arr[i] = thePair;
			break;
		}
	}
	length++;
}
template<class K,class E>
SAL <K, E > ::SAL(pair< K, E>*a, int len, int siz) {
	length = len;
	size = siz;
	arr = new pair<K, E>[size];
	for (int i = 0; i < length; i++) {
		arr[i] = a[i];
	}
}
template<class K,class E>
pair<K, E> SAL<K,E>::find(const K& theKey) {
	for (int i = 0; i < length; i++) {
		if (theKey == arr[i].first)
			return arr[i];
	
	}
}
int main() {
	pair<int, char> *a=new pair<int, char>[10];
	for (int i = 0; i < 5; i++) {
		a[i].first = i;
		a[i].second = char(65 + i);
	}
	SAL<int, char> test(a, 5, 10);
	for (int i = 0; i < 5; i++)
		cout << a[i].first << "    " << a[i].second << endl;
	cout << test.find(3).second << endl << endl;
	test.show();
	test.insert(a[1]);
	test.show();
	test.insert(a[2]);
	test.show();
	test.insert(a[3]);
	test.show();
	test.insert(a[4]);
	test.show();
	test.insert(a[3]);
	test.show();
	test.insert(a[2]);
	test.show();
	test.insert(a[1]);
	test.show();
	test.insert(a[0]);
	cout << test.find(3).second << endl << endl;
	test.show();
	test.insert(a[3]);
	test.show();
	test.erase(2);
	test.show();
	system("pause");
	return 0;

	
}