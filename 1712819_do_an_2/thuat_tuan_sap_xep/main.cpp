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
void SelectionSort(int a[], int n)
{
	int i, j, pos;
	for ( i = 0; i < n - 1; i++) {
		pos = i;
		for ( j = i + 1; j < n; j++)
			if (a[j] < a[pos])
				pos = j;
		SWAP(a[i], a[pos]);
	}
}
void dummySelection(int a[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = i + 1; j < n; j++)
			if (a[i] > a[j])
				SWAP(a[i], a[j]);
}
void InsertionSort(int a[], int n)
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
void InsertionSortwithSentine(int a[], int n)//lỗi
{
	int x, i, j;
	for (i = 2; i <= n; i++)
	{
		x = a[i];
		a[0] = x;
		j = i - 1;
		while (x < a[j])
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
}
void BinaryInsertionSort(int a[], int n)
{
	int i, j, left, right, mid, x;
	for (i = 1; i < n; i++)
	{
		x = a[i];
		left = 0;
		right = i - 1;
		while (left <= right)
		{
			mid = (left + right) / 2;
			if (x < a[mid])
				right = mid - 1;
			else
				left = mid + 1;
		}
		for (j = i - 1; j >= left; j--)
			a[j + 1] = a[j];
		a[left] = x;
	}
}
void BubbSort(int a[], int n)
{
	int i, j;
	for (i = 1; i < n; i++)
		for (j = n - 1; j >= i; j--)
			if (a[j - 1] > a[j])
				SWAP(a[j - 1], a[j]);
}
void ShakeSort(int a[],int n)
{
	int left, right, j, k;
	left = 1;
	right = n - 1;
	do {
		for (j = right; j >= left; j--)
			if (a[j - 1] > a[j]) {
				SWAP(a[j], a[j - 1]);
				k = j;
			}
		left = k + 1;
		for (j = left; j <= right; j++)
			if (a[j - 1] > a[j]) {
				SWAP(a[j], a[j - 1]);
				k = j;
			}
		right = k - 1;
	} while (left <= right);
}
void SelectionSort(int a[], int n, int &countAssign, int &countcompare)
{
	countAssign = 0;
	countcompare = 0;
	int i, j, pos;
	for ( i = 0, countAssign++;++countcompare && i < n - 1 ; i++, countAssign++) 
	{
		pos = i;
		countAssign++;
		for ( j = i + 1, countAssign++; ++countcompare && j < n; j++, countAssign++)
			if (++countcompare && a[j] < a[pos]) {
				pos = j;
				countAssign++;
			}
		SWAP(a[i], a[pos]);
	}
}
void InsertionSort(int a[], int n, int &countAssign, int &countcompare)
{
	countAssign = 0;
	countcompare = 0;
	int x, i, j;
	for (i = 1, countAssign++; ++countcompare && i < n; i++, countAssign++)
	{
		x = a[i];
		j = i - 1;
		countAssign = +2;
		while (++countcompare && j >= 0 && ++countcompare  && a[j] > x)//*
		{
			a[j + 1] = a[j];
			j--;
			countAssign = +2;
		}
		a[j + 1] = x;
		countAssign++;
	}
}
void BinaryInsertionSort(int a[], int n, int &countAssign, int &countcompare)
{
	countAssign = 0;
	countcompare = 0;
	int i, j, left, right, mid, x;
	for (i = 1, countAssign++ ;++countcompare && i < n; i++, countAssign++)
	{
		x = a[i];
		left = 0;
		right = i - 1;
		countAssign = +3;
		while (++countcompare && left <= right)
		{
			mid = (left + right) / 2;
			countAssign++;
			if (++countcompare && x < a[mid])
			{
				right = mid - 1;
				countAssign++;
			}
			else
			{
				left = mid + 1;
				countAssign++;
			}
		}
		for (j = i - 1, countAssign++ ; ++countcompare && j >= left; j--, countAssign++)
		{
			a[j + 1] = a[j];
			countAssign++;
		}
		a[left] = x;
		countAssign++;
	}
}
void BubbSort(int a[], int n, int &countAssign, int &countcompare)
{
	countAssign = 0;
	countcompare = 0;
	int i, j;
	for (i = 1, countAssign++; ++countcompare && i < n; i++, countAssign++)
		for (j = n - 1, countAssign++; ++countcompare && j >= i; j--, countAssign++)
			if (++countcompare && a[j - 1] > a[j])
				SWAP(a[j - 1], a[j]);
}
void ShakeSort(int a[], int n,int &countAssign,int &countcompare)
{
	countAssign = 0;
	countcompare = 0;
	int left, right, j, k;
	left = 1;
	right = n - 1;
	countAssign += 2;
	do {
		for (j = right, countAssign++; ++countcompare && j >= left ; j--, countAssign++)
			if (++countcompare && a[j - 1] > a[j] ) {
				SWAP(a[j], a[j - 1]);
				k = j;
				countAssign++;
			}
		left = k + 1;
		countAssign++;
		for (j = left, countAssign++ ; ++countcompare && j <= right ; j++, countAssign++)
			if (++countcompare && a[j - 1] > a[j] ) {
				SWAP(a[j], a[j - 1]);
				k = j;
				countAssign++;
			}
		right = k - 1;
		countAssign++;
	} while (++countcompare && left <= right );
}
int main()
{
	int n,coutAssign1,countcompera1 ;
	cout << "Nhap vao so phan tu: ";
	cin >> n;
	int *a = new int[n];
	aray(a, n);
	clock_t t1, t2;
	t1 = clock();
	ShakeSort(a, n);
	t2 = clock();
	double d = double(t2 - t1)/ CLOCKS_PER_SEC;
	cout << d;
	ShakeSort(a, n, coutAssign1, countcompera1);
	cout << coutAssign1 <<"  " << countcompera1;
	delete[]a;
	system("pause");
	return 0;
}
