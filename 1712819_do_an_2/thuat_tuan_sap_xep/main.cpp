#include<iostream>
#include<time.h>
#include <stdlib.h>
using namespace std;
void aray(int *a, int n)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		*(a + i) = rand()%1000;
}
void xuat(int *a, int n)
{
	for (int i = 0; i < n; i++)
		cout << *(a+i)<<"   ";
}
void SWAP(int &a, int &b)
{
	int temp;
	temp =a;
	a = b;
	b = temp;
}
void reset_arry(int *a, int *b, int n)//luu tru hoac khoi phuc mang ban dau
{
	for (int i = 0; i < n; i++)
		b[i] = a[i];
}
//các thuật toán sắp xếp
void InsertionSort(int a[], int n)//
{
	int x, i, j;
	for (i = 1; i < n; i++)
	{
		x = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > x)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
}
void BubbleSort(int a[], int n)//
{
	int i, j;
	for (i = 1; i < n; i++)
		for (j = n - 1; j >= i; j--)
			if (a[j - 1] > a[j])
				SWAP(a[j - 1], a[j]);
}
void Sharksort(int a[], int N, int left, int right)
{
	left = 0;
	right = N - 1;
	int k = N - 1, j;
	while (left<right)
	{
		j = right;
		while (j>left)
		{
			if (a[j]<a[j - 1])
			{

				SWAP(a[j], a[j - 1]);
				k = j;
			}
			j--;
		}
		left = k;
		j = left;
		while (j<right)
		{
			if (a[j]>a[j + 1])
			{
				SWAP(a[j], a[j + 1]);
				k = j;
			}
			j++;
		}
		right = k;
	}
}
void ShellSort(int A[], int n)
{
	int h = 1, x, i, j;
	while (h <= n/ 3)
	{
		h = h * 3 + 1;
	}
	while (h > 0)
	{
		for (i = h; i < n; i++)
		{
			x = A[i];
			j = i;
			while (A[j - h] > x && j > h - 1)
			{
				A[j] = A[j - h];
				j -= h;
			}
			A[j] = x;
		}
		h = (h - 1) / 3;
	}
}
void QuickSort(int a[], int left, int right)
{
	long int i = left, j = right;
	long int x = a[(left + right) / 2];
	do
	{
		while (a[i]<x)
		{
			i++;
		}
		while (a[j]>x)
		{
			j--;
		}
		if (i <= j)
		{
			SWAP(a[i], a[j]);
			i++;
			j--;
		}
	} while (i<j);
	if (left<j)
	{
		QuickSort(a, left, j);
	}
	if (i<right)
	{
		QuickSort(a, i, right);
	}
}
void Merge(int a[], int left, int mid, int right)
{
	int *temp;
	int i = left;
	int j = mid + 1;
	temp = new int[right - left + 1];
	for (int k = 0; k <= right - left; k++)
	{
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			i++;
		}
		else
		{
			temp[k] = a[j];
			j++;
		}

		if (i == mid + 1)
		{
			while (j <= right)
			{
				k++;
				temp[k] = a[j];
				j++;
			}
			break;
		}
		if (j == right + 1)
		{

			while (i <= mid)
			{
				k++;
				temp[k] = a[i];
				i++;
			}
			break;
		}
	}

	for (int k = 0; k <= right - left; k++)
	{
		a[left + k] = temp[k];
	}

	delete temp;
}
void MergeSort(int a[], int left, int right)
{
	if (right > left)
	{
		int mid;
		mid = (left + right) / 2;
		MergeSort(a, left, mid);
		MergeSort(a, mid + 1, right);
		Merge(a, left, mid, right);
	}
}
void RadixSort(int a[], int N)
{
	int i, m = a[0], exp = 1;
	int *b = new int[N];
	for (i = 0; i<N; i++)
	{
		if (a[i]>m)
		{
			m = a[i];
		}
	}
	while (m / exp>0)
	{
		int temp[10] = { 0 };
		for (i = 0; i<N; i++)
		{
			temp[a[i] / exp % 10]++;
		}
		for (i = 1; i < 10; i++)
		{
			temp[i] += temp[i - 1];
		}
		for (i = N - 1; i >= 0; i--)
		{
			b[--temp[a[i] / exp % 10]] = a[i];
		}

		for (i = 0; i < N; i++)
		{
			a[i] = b[i];
		}
		exp *= 10;
	}
}
void Heapify(int a[], int offset, int size)
{
	int l, r, max;
	l = 2 * offset;
	r = 2 * offset + 1;

	if (l <= size && a[l] > a[offset])
	{
		max = l;
	}
	else
	{
		max = offset;
	}

	if (a[r] > a[max] && r <= size)
	{
		max = r;
	}

	if (max != offset)
	{
		SWAP(a[offset], a[max]);
		Heapify(a, max, size);
	}
}
void CreateHeap(int a[], int N)
{
	int offset, size;
	size = N - 1;

	for (offset = (N / 2); offset >= 0; offset--)
	{
		Heapify(a, offset, size);
	}
}
void HeapSort(int a[], int N)
{
	CreateHeap(a, N);
	int size, offset;
	size = N - 1;
	for (offset = size; offset >= 0; offset--)
	{
		SWAP(a[0], a[size]);
		size--;
		Heapify(a, 0, size);
	}
}
//để đo và thống kê được chính xác ta cần viết hàm rieeg để  tính số phép so sánh và số phép gán ,khi t tính thời gian thì t chạy các hàm sắp xếp  trên sẽ chính xác và hợp lí hơn 
long   coutntAssign_QuickSort = 0, countcompare_QuickSort = 0, coutntAssign_MergeSort = 0, countcompare_MergeSort = 0, coutntAssign_HeapSort = 0, countcompare_HeapSort = 0, coutntAssign_Sharksort = 0, countcompare_Sharksort = 0;
void InsertionSort(int a[], int n, long &countAssign, long &countcompare)
{
	countAssign = 0;
	countcompare = 0;
	int x, i, j;
	for (i = 1, countAssign++; ++countcompare && i < n; i++, countAssign++)
	{
		x = a[i];
		j = i - 1;
		countAssign = +2;
		while (++countcompare && j >= 0 && ++countcompare  && a[j] > x)
		{
			a[j + 1] = a[j];
			j--;
			countAssign = +2;
		}
		a[j + 1] = x;
		countAssign++;
	}
}
void BubbleSort(int a[], int n, long &countAssign, long &countcompare)
{
	countAssign = 0;
	countcompare = 0;
	int i, j;
	for (i = 1, countAssign++; ++countcompare && i < n; i++, countAssign++)
		for (j = n - 1, countAssign++; ++countcompare && j >= i; j--, countAssign++)
			if (++countcompare && a[j - 1] > a[j])
			{
				SWAP(a[j - 1], a[j]);
				countAssign = countAssign + 3;// ham SWAP co 3 phep gan 
			}
}
void Sharksort_(int a[], int N, int left, int right)
{
	left = 0;
	right = N - 1;
	int k = N - 1, j;
	coutntAssign_Sharksort = coutntAssign_Sharksort + 3;
	while (++countcompare_Sharksort  && left<right)
	{
		j = right;
		coutntAssign_Sharksort++;
		while (++countcompare_Sharksort  && j>left)
		{
			if (++countcompare_Sharksort  && a[j]<a[j - 1])
			{

				SWAP(a[j], a[j - 1]);
				k = j;
				coutntAssign_Sharksort = coutntAssign_Sharksort + 4;
			}
			j--;
			coutntAssign_Sharksort++;
		}
		left = k;
		j = left;
		coutntAssign_Sharksort = coutntAssign_Sharksort + 2;
		while (++countcompare_Sharksort  && j<right)
		{
			if (++countcompare_Sharksort  && a[j]>a[j + 1])
			{
				SWAP(a[j], a[j + 1]);
				k = j;
				coutntAssign_Sharksort = coutntAssign_Sharksort + 4;
			}
			j++;
			coutntAssign_Sharksort++;
		}
		right = k;
		coutntAssign_Sharksort++;
	}
}
void ShellSort(int A[], int n, long &countAssign, long &countcompare)
{
	int h = 1, x, i, j;
	countAssign = 1;
	countcompare = 0;
	while (++countcompare && h <= n / 3)
	{
		h = h * 3 + 1;
		countAssign++;
	}
	while (++countcompare && h > 0)
	{
		for (i = h,countAssign++;++countcompare  && i < n; i++,countAssign++)
		{
			x = A[i];
			j = i;
			countAssign = countAssign + 2;
			while (++countcompare && A[j - h] > x && ++countcompare  && j > h - 1)
			{
				A[j] = A[j - h];
				j -= h;
				countAssign = countAssign + 2;
			}
			A[j] = x;
			countAssign++;
		}
		h = (h - 1) / 3;
		countAssign++;
	}
}
void QuickSort_(int a[], int left, int right)
{
	long int i = left, j = right;
	long int x = a[(left + right) / 2];
	coutntAssign_QuickSort = coutntAssign_QuickSort + 3;
	do
	{
		while (++countcompare_QuickSort && a[i]<x)
		{
			i++;
			coutntAssign_QuickSort++;
		}
		while (++countcompare_QuickSort && a[j]>x)
		{
			j--;
			coutntAssign_QuickSort++;
		}
		if (++countcompare_QuickSort && i <= j)
		{
			SWAP(a[i], a[j]);
			i++;
			j--;
			coutntAssign_QuickSort = coutntAssign_QuickSort + 5;//do SWAP co 3 phep gan
		}
	} while (++countcompare_QuickSort && i<j);
	if (++countcompare_QuickSort && left<j)
	{
		QuickSort(a, left, j);
	}
	if (++countcompare_QuickSort && i<right)
	{
		QuickSort(a, i, right);
	}
}
void Merge_(int a[], int left, int mid, int right)
{
	int *temp;
	int i = left;
	int j = mid + 1;
	coutntAssign_MergeSort = coutntAssign_MergeSort + 2;
	temp = new int[right - left + 1];
	int k;
	for (coutntAssign_MergeSort++, k = 0; ++countcompare_MergeSort && k <= right - left; k++, coutntAssign_MergeSort++)
	{
		if (++countcompare_MergeSort && a[i] < a[j])
		{
			temp[k] = a[i];
			i++;
			coutntAssign_MergeSort = coutntAssign_MergeSort + 2;
		}
		else
		{
			temp[k] = a[j];
			j++;
			coutntAssign_MergeSort = coutntAssign_MergeSort + 2;
		}

		if (++countcompare_MergeSort && i == mid + 1)
		{
			while (++countcompare_MergeSort && j <= right)
			{
				k++;
				temp[k] = a[j];
				j++;
				coutntAssign_MergeSort = coutntAssign_MergeSort + 3;
			}
			break;
		}
		if (++countcompare_MergeSort && j == right + 1)
		{

			while (++countcompare_MergeSort && i <= mid)
			{
				k++;
				temp[k] = a[i];
				i++;
				coutntAssign_MergeSort = coutntAssign_MergeSort + 3;
			}
			break;
		}
	}
	int k1;
	for (coutntAssign_MergeSort++,k1 = 0; ++countcompare_MergeSort && k1 <= right - left; k1++, coutntAssign_MergeSort++)
	{
		a[left + k1] = temp[k1];
		coutntAssign_MergeSort++;
	}

	delete temp;
}
void MergeSort_(int a[], int left, int right)
{
	if (++countcompare_MergeSort && right > left)
	{
		int mid;
		mid = (left + right) / 2;
		coutntAssign_MergeSort++;
		MergeSort_(a, left, mid);
		MergeSort_(a, mid + 1, right);
		Merge_(a, left, mid, right);
	}
}
void RadixSort(int a[], int N, long &countAssign, long &countcompare)
{
	int i, m = a[0], exp = 1;
	int *b = new int[N];
	countAssign = 2;
	countcompare = 0;
	for (countAssign++, i = 0; ++countcompare && i < N; i++, countAssign++)
	{
		if (++countcompare && a[i] > m)
		{
			m = a[i];
			countAssign++;
		}
	}
	while (++countcompare && m / exp > 0)
	{
		int temp[10] = { 0 };
		for (i = 0, countAssign++; ++countcompare && i < N; i++, countAssign++)
		{
			temp[a[i] / exp % 10]++;
			countAssign++;
		}
		for (countAssign++, i = 1; ++countcompare && i < 10; i++, countAssign++)
		{
			temp[i] += temp[i - 1];
			countAssign++;
		}
		for (i = N - 1, countAssign++; ++countcompare && i >= 0; i--, countAssign++)
		{
			b[--temp[a[i] / exp % 10]] = a[i];
			countAssign++;
		}

		for (i = 0, countAssign++; ++countcompare && i < N; i++, countAssign++)
		{
			a[i] = b[i];
			countAssign++;
		}
		exp *= 10;
		countAssign++;
	}
}
void Heapify_(int a[], int offset, int size)
{
	int l, r, max;
	l = 2 * offset;
	r = 2 * offset + 1;
	coutntAssign_HeapSort = coutntAssign_HeapSort + 2;
	if (++countcompare_HeapSort  && l <= size && ++countcompare_HeapSort  &&  a[l] > a[offset])
	{
		max = l;
		coutntAssign_HeapSort++;
	}
	else
	{
		max = offset;
		coutntAssign_HeapSort++;
	}

	if (++countcompare_HeapSort  && a[r] > a[max] && ++countcompare_HeapSort  &&  r <= size)
	{
		max = r;
		coutntAssign_HeapSort++;
	}

	if (++countcompare_HeapSort  && max != offset)
	{
		SWAP(a[offset], a[max]);
		coutntAssign_HeapSort = coutntAssign_HeapSort + 3;
		Heapify_(a, max, size);
	}
}
void CreateHeap_(int a[], int N)
{
	int offset, size;
	size = N - 1;
	coutntAssign_HeapSort++;
	for (coutntAssign_HeapSort++,offset = (N / 2); ++countcompare_HeapSort  && offset >= 0; coutntAssign_HeapSort++,offset--)
	{
		Heapify_(a, offset, size);
	}
}
void HeapSort_(int a[], int N)
{
	CreateHeap_(a, N);
	int size, offset;
	size = N - 1;
	coutntAssign_HeapSort++;
	for (coutntAssign_HeapSort++,offset = size;++countcompare_HeapSort  &&  offset >= 0; coutntAssign_HeapSort++, offset--)
	{
		SWAP(a[0], a[size]);
		size--;
		coutntAssign_HeapSort = coutntAssign_HeapSort + 4;
		Heapify_(a, 0, size);
	}
}
int main()
{
	int n;
	long coutAssign, countcompera;
	cout << "Nhap vao so phan tu: ";
	cin >> n;
	int *a = new int[n];
	int *b = new int[n];
	aray(a, n);
	reset_arry(a, b, n);// sao chép mảng a vào b đê lưu trữ dữ liệu ban đầu của mảng a 
	clock_t t1, t2;
	cout << "----------InsertionSort----------" << endl;
	t1 = clock();
	InsertionSort(a, n);
	t2 = clock(); 
	double d = double(t2 - t1) / CLOCKS_PER_SEC;
	InsertionSort(a, n,coutAssign, countcompera);
	cout << "So phep gan:  " << coutAssign << endl;
	cout << "So phep so sanh:  " << countcompera << endl;
	cout << "Thoi gian chay:  " << d << endl;
	reset_arry(b, a, n);//sau 1 lần sắp xếp t khôi phục lại mảng a ban đầu 
	//
	cout << "----------BubbleSort----------" << endl;
	t1 = clock();
	BubbleSort(a, n);
	t2 = clock();
	 d = double(t2 - t1) / CLOCKS_PER_SEC;
	 BubbleSort(a, n, coutAssign, countcompera);
	cout << "So phep gan:  " << coutAssign << endl;
	cout << "So phep so sanh:  " << countcompera << endl;
	cout << "Thoi gian chay:  " << d << endl;
	reset_arry(b, a, n);//sau 1 lần sắp xếp t khôi phục lại mảng a ban đầu 
	//
	cout << "----------RadixSort----------" << endl;
	t1 = clock();
	RadixSort(a, n);
	t2 = clock();
	d = double(t2 - t1) / CLOCKS_PER_SEC;
	RadixSort(a, n, coutAssign, countcompera);
	cout << "So phep gan:  " << coutAssign << endl;
	cout << "So phep so sanh:  " << countcompera << endl;
	cout << "Thoi gian chay:  " << d << endl;
	reset_arry(b, a, n);//sau 1 lần sắp xếp t khôi phục lại mảng a ban đầu 
	//
	cout << "----------ShellSort----------" << endl;
	t1 = clock();
	ShellSort(a, n);
	t2 = clock();
	d = double(t2 - t1) / CLOCKS_PER_SEC;
	ShellSort(a, n, coutAssign, countcompera);
	cout << "So phep gan:  " << coutAssign << endl;
	cout << "So phep so sanh:  " << countcompera << endl;
	cout << "Thoi gian chay:  " << d << endl;
	reset_arry(b, a, n);//sau 1 lần sắp xếp t khôi phục lại mảng a ban đầu
	//
	cout << "----------MergeSort----------" << endl;
	t1 = clock();
	MergeSort(a, 0,n-1);
	t2 = clock();
	d = double(t2 - t1) / CLOCKS_PER_SEC;
	MergeSort_(a, 0, n - 1);
	cout << "So phep gan:  " << coutntAssign_MergeSort << endl;
	cout << "So phep so sanh:  " << countcompare_MergeSort << endl;
	cout << "Thoi gian chay:  " << d << endl;
	reset_arry(b, a, n);//sau 1 lần sắp xếp t khôi phục lại mảng a ban đầu
	//
	cout << "----------QuickSort----------" << endl;
	t1 = clock();
	QuickSort(a, 0, n - 1);
	t2 = clock();
	d = double(t2 - t1) / CLOCKS_PER_SEC;
	QuickSort_(a, 0, n - 1);
	cout << "So phep gan:  " << coutntAssign_QuickSort << endl;
	cout << "So phep so sanh:  " << countcompare_QuickSort<< endl;
	cout << "Thoi gian chay:  " << d << endl;
	reset_arry(b, a, n);//sau 1 lần sắp xếp t khôi phục lại mảng a ban đầu
	//
	cout << "----------HeapSort----------" << endl;
	t1 = clock();
	HeapSort(a, n);
	t2 = clock();
	d = double(t2 - t1) / CLOCKS_PER_SEC;
	HeapSort_(a, n);
	cout << "So phep gan:  " << coutntAssign_HeapSort << endl;
	cout << "So phep so sanh:  " << countcompare_HeapSort << endl;
	cout << "Thoi gian chay:  " << d << endl;
	reset_arry(b, a, n);//sau 1 lần sắp xếp t khôi phục lại mảng a ban đầu
	//
	cout << "----------Sharksort----------" << endl;
	t1 = clock();
	Sharksort(a, n,0,n-1);
	t2 = clock();
	d = double(t2 - t1) / CLOCKS_PER_SEC;
	Sharksort_(a, n,0,n-1);
	cout << "So phep gan:  " << coutntAssign_Sharksort << endl;
	cout << "So phep so sanh:  " << countcompare_Sharksort << endl;
	cout << "Thoi gian chay:  " << d << endl;
	reset_arry(b, a, n);//sau 1 lần sắp xếp t khôi phục lại mảng a ban đầu
	delete[]a;
	delete[]b;
	system("pause");
	return 0;
}
