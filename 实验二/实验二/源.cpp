#include<iostream>
#include<stdlib.h>
#include<ctime>
#include<cmath>
using namespace std;
template<class T>
void showtemp(T *a,int size) {									//�����������������м����
	for (int i = 0; i < size; i++)
		cout << a[i] << "\t" ;
	cout << endl;
}
template<class T>
class Sort {
private:T * element;											//˽�г�Ա����һ��ָ�������ָ�������ĳ���
		int length;
public:void rs();
	   void ss();												//ѡ������
	   void is();												//��������
	   void bs();												//ð������
	   Sort(const T  *arr,int n);
	   void show();
};
template<class T>
void Sort<T>::rs() {
	//T **temp = new T[10][length];
	cout << "����������м�������£�" << endl << endl;
	T **temp = new T*[10];										//����һ����ά���飬������ÿ��������Ԫ��
	for (int i = 0; i < 10; i++)								
		temp[i] = new T[length];
	T max=element[0];											//ȡһ�����ֵ����������Ҫȡ��ѭ���Ĵ���
	//T *store = new T[length];										
	int count[10];												//������ĳλΪĳ�����ֵĸ���
	for (int i = 0; i < 10; i++)								//�ȳ�ʼ��Ϊÿ�����ֶ�Ϊ��
		count[i] = 0;
	for (int i = 0; i < length; i++) {
		if (max < element[i])
			max = element[i];
	}
	int len = 0;
	for (int i = 0; max > 0; i++) {								//���������ֵ��λ��
		max /= 10;
		len = i;
	}
	for (int i = 0; i < len+1; i++)								//��Ϊ����i++û�б����룬������Ҫ������+1
	{
		int num = 0;											//һ������������num=length���ʾȫ��Ԫ���Ѵ���element
		/*
		for (int j = 0; j < length; j++) 
		{
			count[element[i] / pow(10, i) % 10]++;
		}
		*/
		for (int j = 0; j < length; j++)						//��ÿһ��Ԫ�ض��������㣬�������ʵ���λ��
		{
			if (i == 0) {																	//��Ϊpow������������Ϊ0����˷�������	
				temp[element[j] % 10][count[element[j]%10]] = element[j];					//������Ϊ��λ����ֵ����������㿪ʼ�������ֵ���ּ��ξͰ�������	
				count[element[j] % 10]++;													//ÿ����һ����ʹ������ֵļ�����+1
			}
			else {
				temp[(element[j] / int(pow(10, i))) % 10][count[element[j] / int(pow(10, i)) % 10]] = element[j]; //�˴�Ϊi>0�����������ͬ��
				count[element[j] / int(pow(10, i)) % 10]++;
			}
		}
		while (num < length)																//�Ӷ�ά�����ж����������Ԫ�أ�num=length��ʾ���꣬�ж�ѭ��
		{
			for (int j = 0; j < 10; j++)													//���ж�ȡ
			{
				if (count[j] > 0)															//�������ֵļ�����Ϊ0������������Ϊ0��ʼ��ֵ
				{
					int z = 0;																//��һ������������z=count���ʾ��λΪ�����ֵ�Ԫ����ȫ������
					while (z<count[j]) 
					{
						element[num] = temp[j][z];											//ÿһ�а����±���С�����˳���ȡ
						z++;
						num++;
					}
				}
			}
		}
		for(int j=0;j<10;j++)																//ÿ��ѭ��ִ������temp��count�����㣬׼��������һ�ֵĸ�ֵ
			for (int z = 0; z < length; z++) {
				temp[j][z] = 0;
			}
		for (int j = 0; j < 10; j++)
			count[j] = 0;
		show();
	}
	/*delete element;
	element = store;*/
	cout << endl;
	cout << "������������ս������" << endl << endl;
	show();
	cout << endl;
}
template<class T>
void Sort<T>::is() {
	cout << "����������м�������£�" << endl << endl;
	T * temp = new T[length];									//����һ���µ�������������
	temp[0] =element[0];										//��ʹ��һ��Ԫ��Ϊԭ����ĵ�һ��Ԫ��
	int size = 1;												//������¼�Ѳ���Ԫ�صĸ���
	showtemp(temp, size);										//���������м����	
	for (int i = 1; i < length; i++) {							//ԭ�����г���һ��Ԫ�أ������ȫ������temp���е�Ԫ�رȽ�
		for (int j = 0; j < i; j++) {							//׼�������Ԫ��������temp���е�Ԫ�رȽ�,ֱ����ɷ��������Ĳ��룬�ͻ���һ��ԭ�����Ԫ�ؼ����Ƚ�
			if (element[i] <= temp[j]&&element[i]>temp[j-1]) {	//�ҵ���Ҫ��λ�ã�ʹ������Ԫ��ȫ������һλ���ڸ�λ�ò���Ԫ��
				for (int z = 0; z < size-j; z++) {
					temp[size-z] = temp[size - z-1];
				}
				temp[j] = element[i];
				size++;											//ÿ�β����ʹsize+1
				showtemp(temp, size);							//����м����
				break;
			}
			else if (element[i] >= temp[size-1]) {				//����Ԫ�ش���temp�����һ��Ԫ�أ����ڸ�Ԫ�غ����
				temp[size] = element[i];
				size++;
				showtemp(temp, size);
				break;
			}
		}
	}
	delete element;												//ɾ��ԭ��
	element = temp;												//ʹ֮����temp
	cout << endl;
	cout << "������������ս�����£�" << endl << endl;
	show();
	cout << endl;
}
template<class T>
void Sort<T>::bs() {
	cout << "ð��������м��������" << endl <<endl;
	int times = 0;												//�趨���ѭ������Ϊn-1
	while (times < length) {
		bool change = false;									//�鿴ĳһ��ѭ���Ƿ���Ԫ�صĽ�������û�������ѭ��
		for (int i = 0; i < length-1; i++) {					
			if (element[i] > element[i + 1]) {					//ǰ��Ԫ�رȽ�
				T temp = element[i+1];							//��ǰԪ�ش��ں�Ԫ�أ��򽻻�
				element[i + 1] = element[i];
				element[i] = temp;
				change = true;
				this->show();									//����м����
			}
		}
		if (change == false)									//δ���������ѭ��
			break;
		times++;
	}
	cout << endl;
	cout << "ð����������սṹ����" << endl << endl;
	show();
	cout << endl;
}
template<class T>
void Sort<T>::show() {
	for (int i = 0; i<length; i++) {
		cout << element[i]<<"\t";
	}
	cout << endl;
}
template<class T>
Sort<T>::Sort(const T *a,int n) {										//�½�һ�����飬��ÿ��a��ֵ���룬��const��ֹԭ����a���ı�
	element = new T[n];
	for (int i = 0; i < n; i++) {
	element[i] = a[i];
	}
	//element = a;
	length = n;
}
template<class T>
void Sort<T>::ss() {
	cout << "ѡ��������м��������" << endl << endl;;
	T * pointer = element;												//����һ��ָ�룬�õ�element��ֵ
	//length = n;
	for (int z = 0; z<length; z++) {									//��ǰ������
		T * min = &pointer[z];											//�ѵ�һ��������Сֵ
		while (*min != '/0') {
			for (int j = z; j<length; j++) {							//��Сֵ��֮��ÿһ��Ԫ�رȽϣ����и�С���������������е�min	
				if (pointer[j]<*min) {
					min = &element[j];
				}
			}
			T temp = pointer[z];										//������Сֵ���һ��Ԫ��
			pointer[z] = *min;
			*min = temp;
			this->show();
			break;
		}
	}
	cout << endl;
	cout << "ѡ����������ս������" << endl<<endl;
	this->show();
	cout << endl << endl;
}
int main() {
	srand((unsigned)time(NULL));
	int n = 0;
	cin >> n;
	int * a = new int[n];												//����һ��������飬��������
	cout << "����������������" << endl<<endl;
	for (int i = 0; i < n; i++) {
		a[i] = rand();
		cout << a[i]<<"\t";
	}
	cout << endl << endl;;
	Sort<int> testss(a,n);
	testss.ss();
	Sort<int> testbs(a, n);
	testbs.bs();
	Sort<int> testis(a, n);
	testis.is();
	Sort<int> testrs(a, n);
	testrs.rs();
	system("pause");
	return 0;

}