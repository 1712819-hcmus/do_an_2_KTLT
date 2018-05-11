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
		cout << a[i]<<"  ";
}
/*void SWAP(int &a, int &b)
{
	int temp;
	temp =a;
	a = b;
	b = temp;
}
void SelectionSort(int a[], int n)
{
	int i, j, pos;
	for (int i = 0; i < n - 1; i++) {
		pos = i;
		for (int j = i + 1; j < n; j++)
			if (a[j] < a[pos])
				pos = j;
		SWAP(a[i], a[pos]);
	}
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
void InsertionSortwithSentine(int a[], int n)
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
void ShakeSort(int a[], int n)
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
}*/
int main()
{
	int n ;
	cout << "Nhap vao so phan tu: ";
	cin >> n;
	int *a = new int[n];
	aray(a, n);
	xuat(a, n);
	system("pause");
	return 0;
}
