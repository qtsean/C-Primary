#include<iostream>
#include<stdlib.h>
#include<ctime>
#include<cmath>
using namespace std;
template<class T>
void showtemp(T *a,int size) {									//用来输出插入排序的中间过程
	for (int i = 0; i < size; i++)
		cout << a[i] << "\t" ;
	cout << endl;
}
template<class T>
class Sort {
private:T * element;											//私有成员包含一个指向数组的指针和数组的长度
		int length;
public:void rs();
	   void ss();												//选择排序
	   void is();												//插入排序
	   void bs();												//冒泡排序
	   Sort(const T  *arr,int n);
	   void show();
};
template<class T>
void Sort<T>::rs() {
	//T **temp = new T[10][length];
	cout << "基数排序的中间过程如下：" << endl << endl;
	T **temp = new T*[10];										//创建一个二维数组，来储存每次排序后的元素
	for (int i = 0; i < 10; i++)								
		temp[i] = new T[length];
	T max=element[0];											//取一个最大值，来计算需要取余循环的次数
	//T *store = new T[length];										
	int count[10];												//来储存某位为某个数字的个数
	for (int i = 0; i < 10; i++)								//先初始化为每个数字都为零
		count[i] = 0;
	for (int i = 0; i < length; i++) {
		if (max < element[i])
			max = element[i];
	}
	int len = 0;
	for (int i = 0; max > 0; i++) {								//来计算最大值的位数
		max /= 10;
		len = i;
	}
	for (int i = 0; i < len+1; i++)								//因为最后的i++没有被算入，所以需要在这里+1
	{
		int num = 0;											//一个计数器，当num=length则表示全部元素已存入element
		/*
		for (int j = 0; j < length; j++) 
		{
			count[element[i] / pow(10, i) % 10]++;
		}
		*/
		for (int j = 0; j < length; j++)						//对每一个元素都进行运算，并存入适当的位置
		{
			if (i == 0) {																	//因为pow函数参数不能为0，因此分类讨论	
				temp[element[j] % 10][count[element[j]%10]] = element[j];					//行坐标为该位的数值，列坐标从零开始，这个数值出现几次就包含几列	
				count[element[j] % 10]++;													//每存入一个，使这个数字的计数器+1
			}
			else {
				temp[(element[j] / int(pow(10, i))) % 10][count[element[j] / int(pow(10, i)) % 10]] = element[j]; //此处为i>0的情况，基本同上
				count[element[j] / int(pow(10, i)) % 10]++;
			}
		}
		while (num < length)																//从二维数组中读回已排序的元素，num=length表示读完，中断循环
		{
			for (int j = 0; j < 10; j++)													//按行读取
			{
				if (count[j] > 0)															//若该数字的计数器为0，则跳过，不为0则开始赋值
				{
					int z = 0;																//另一个计数器，当z=count后表示该位为该数字的元素已全部读入
					while (z<count[j]) 
					{
						element[num] = temp[j][z];											//每一行按从下标由小到大的顺序读取
						z++;
						num++;
					}
				}
			}
		}
		for(int j=0;j<10;j++)																//每个循环执行完后吧temp和count都清零，准备进行下一轮的赋值
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
	cout << "基数排序的最终结果如下" << endl << endl;
	show();
	cout << endl;
}
template<class T>
void Sort<T>::is() {
	cout << "插入排序的中间过程如下：" << endl << endl;
	T * temp = new T[length];									//创建一个新的数组用来插入
	temp[0] =element[0];										//先使第一个元素为原数组的第一个元素
	int size = 1;												//用来记录已插入元素的个数
	showtemp(temp, size);										//输出排序的中间过程	
	for (int i = 1; i < length; i++) {							//原数组中除第一个元素，其余的全部都与temp表中的元素比较
		for (int j = 0; j < i; j++) {							//准备插入的元素与已在temp表中的元素比较,直到完成符合条件的插入，就换下一个原数组的元素继续比较
			if (element[i] <= temp[j]&&element[i]>temp[j-1]) {	//找到需要的位置，使后续的元素全部后移一位，在该位置插入元素
				for (int z = 0; z < size-j; z++) {
					temp[size-z] = temp[size - z-1];
				}
				temp[j] = element[i];
				size++;											//每次插入后都使size+1
				showtemp(temp, size);							//输出中间过程
				break;
			}
			else if (element[i] >= temp[size-1]) {				//若该元素大于temp中最后一个元素，则在该元素后插入
				temp[size] = element[i];
				size++;
				showtemp(temp, size);
				break;
			}
		}
	}
	delete element;												//删除原表
	element = temp;												//使之等于temp
	cout << endl;
	cout << "插入排序的最终结果如下：" << endl << endl;
	show();
	cout << endl;
}
template<class T>
void Sort<T>::bs() {
	cout << "冒泡排序的中间过程如下" << endl <<endl;
	int times = 0;												//设定最多循环次数为n-1
	while (times < length) {
		bool change = false;									//查看某一遍循环是否有元素的交换，若没有则结束循环
		for (int i = 0; i < length-1; i++) {					
			if (element[i] > element[i + 1]) {					//前后元素比较
				T temp = element[i+1];							//若前元素大于后元素，则交换
				element[i + 1] = element[i];
				element[i] = temp;
				change = true;
				this->show();									//输出中间过程
			}
		}
		if (change == false)									//未交换则结束循环
			break;
		times++;
	}
	cout << endl;
	cout << "冒泡排序的最终结构如下" << endl << endl;
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
Sort<T>::Sort(const T *a,int n) {										//新建一个数组，把每个a的值传入，用const防止原数组a被改变
	element = new T[n];
	for (int i = 0; i < n; i++) {
	element[i] = a[i];
	}
	//element = a;
	length = n;
}
template<class T>
void Sort<T>::ss() {
	cout << "选择排序的中间过程如下" << endl << endl;;
	T * pointer = element;												//设置一个指针，得到element的值
	//length = n;
	for (int z = 0; z<length; z++) {									//从前向后进行
		T * min = &pointer[z];											//把第一个当作最小值
		while (*min != '/0') {
			for (int j = z; j<length; j++) {							//最小值与之后每一个元素比较，若有更小的则用它代替现有的min	
				if (pointer[j]<*min) {
					min = &element[j];
				}
			}
			T temp = pointer[z];										//交换最小值与第一个元素
			pointer[z] = *min;
			*min = temp;
			this->show();
			break;
		}
	}
	cout << endl;
	cout << "选择排序的最终结果如下" << endl<<endl;
	this->show();
	cout << endl << endl;
}
int main() {
	srand((unsigned)time(NULL));
	int n = 0;
	cin >> n;
	int * a = new int[n];												//生成一个随机数组，用来测试
	cout << "输入的随机数组如下" << endl<<endl;
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