void setV(int *a, int size, int v)
{
	for (int i = 0; i < size; i++)
	{
		a[i] = v;
	}
}
void merge(int *a, int asize, int* b, int bsize, int* c)
{
	for (int i = 0; i < asize; i++)
	{
		c[i] = a[i];
	}
	for (int j = 0; j < bsize; j++)
	{
		c[j + asize] = b[j];
	}
}
int search(const int* a,int size, int v)
{
	for (int i = 0; i < size; i++)
	{
		if (a[i] == v)
		{
			return i;
		}
	}
	return -1;
}
int del(int *a, int size, int v)
{
	for (int i = 0; i < size; i++)
	{
		if (a[i] == v)
		{
			for (int j = i; j < size-1; j++)
			{
				a[j] = a[j + 1];
			}
			i--;
			size--;
		}
	}
	return size;
}
void sort(int* a, int size)
{
	int times = 0;
	while (times < size)
	{
		bool change = false;
		for (int i = 0; i < size - 1; i++)
		{
			if (a[i] > a[i + 1])
			{
				int temp = a[i + 1];
				a[i + 1] = a[i];
				a[i] = temp;
				change = true;
			}
		}
		if (change == false)
		{
			break;
		}
		times++;
	}
}