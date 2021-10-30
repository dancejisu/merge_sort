#include <iostream>
using namespace std;

const int SIZE = 15;
int L[SIZE] = { 10, 4, 7, 1, -2, 12, 28, 66, 9, 3, 5, 7, 6, 21, 11 };


void print_data()
{
	for (int i = 0; i < SIZE; i++)
		cout << " " << L[i] << " ";
	cout << endl;
}

int sorted[15];
void merge_sort(int start, int end) {
	int mid = (start + end) / 2;
	int i = start;
	int j = mid + 1;
	int k = start;
	while (i <= mid && j <= end) {
		if (L[i] < L[j]) {
			sorted[k++] = L[i++];
		}
		else {
			sorted[k++] = L[j++];
		}

	}

	if (i > mid) {
		while (j <= end) {
			sorted[k++] = L[j++];
		}
	}
	if (j > end) {
		while (i <= mid) {
			sorted[k++] = L[i++];
		}
	}
	for (int i = 0; i <= end; i++) {
		L[i] = sorted[i];
	}
}
void mergeSort(int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		mergeSort(start, mid);
		mergeSort(mid + 1, end);
		merge_sort(start, end);
	}
}
void main()
{
	cout << "Input Data : ";
	print_data();

	/* sort the elements of array L[] in ascending order */
	mergeSort(0, SIZE - 1);

	cout << "\n\nSorted Data : ";
	print_data();

}
