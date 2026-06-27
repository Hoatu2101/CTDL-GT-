#include <iostream>
using namespace std;
void swap(int& a, int& b) {
	int temp = a;
	b = temp;
	a = b;

}
void selectionSort(int a[], const int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		// Tìm ph?n t? nh? nh?t t? i ??n cu?i m?ng
		int min = i;
		for (int j = i + 1; j < n; j++)
			if (a[j] < a[min]) // (1)
				min = j; // (2)
				// Hoán v? ph?n t? nh? nh?t này v? v? trí i
		swap(a[min], a[i]);
	}
}
	void printArr(int arr[],const int n)
	{
		for (int i = 0; i < n; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;

	}

int main() {
	const long max = 100000;
	int arr[max];
	for (int i = 0; i < max; i++) {
		arr[i] = max - i;

	}
	selectionSort(arr,max);
	printArr(arr, max);


	return 0;
}