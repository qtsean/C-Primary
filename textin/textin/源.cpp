template<class T>
class arrayListReverse :public arrayList<T>
{
public:
	void reverse(arrayListReverse<T>& a)
};
template<class T>
void arrayListReverse<T>::reverse(arrayListReverse<T>& a)
{
	int beginning = 0;
	int ending = a.Listsize-1;
	while (beginning < ending) {
		T temp = 0;
		 temp= a.element[beginning];
		a.element[ending] = a.element[beginning];
		a.element[beginning] = temp;
		begnning++;
		ending--;
	}
}
template<class T>
void Reverse2(arrayListReverse<T>& a) {
	int beginning = 0;
	int ending = a.size() - 1;
		while (beginning < ending) {
			T temp ;
			temp = get[beginning];
			get[beginning] = get[ending];
			get[ending] = temp;
			beginning++;
			ending--;
	}
}