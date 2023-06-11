using namespace std;
#include <iostream>
void output(int* arr, int size) {
	
	for (int i = 0; i < size; i++) {		//вивід масива на екран
		cout << arr[i] << " ";
	}
	cout << "\n-----------------------------------------\n";
	cout << endl;
}
void fill(int* arr, int size) {		//запоанення рамдомними числами
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 100 + 1;
	}
}
void sort(int*arr,int size){ //сортування
	int m = size;
	do {
		int a;
		for (int i = 1; i < m; i++) {
			if (arr[i - 1] > arr[i]) {
				a = arr[i - 1];
				arr[i - 1] = arr[i];
				arr[i] = a;
			}
		}
		m--;
	} while (m > 1);
	
}
void connecting(int*& arr, int& size, int*arr2, int sizesecond) { //функція для обєднання масивів
	int newsize = size + sizesecond;
	int* newarr = new int[size];
	for (int i = 0; i < newsize; i++) {
		while (i < size) {
			newarr[i] = arr[i];
			i++;
	    }
		for (int j = 0; j < sizesecond; j++) {
			newarr[i] = arr2[j];
			i++;
		}
	}
	size = newsize;
	delete[]arr;
	arr = newarr;
}
void secondarr(int*& arr, int& size) { // проміжна функція для створення другого масиву і фінальної передачі даних першого і друого масивів в третій
start2:
	int sizesecond;
	cout << "Input size of second array  ";
	cin >> sizesecond;
	if (sizesecond < 1) {
		goto start2;
	}
	int* arr2 = new int[sizesecond];
	fill(arr2, sizesecond);
	sort(arr2, sizesecond);
	cout << "The second arr:\n";
	output(arr2, sizesecond);
	connecting(arr, size, arr2, sizesecond);
	
}

int main()
{
	int sizefirst;
start:
	cout << "Input size of first array  ";
	cin >> sizefirst;
	if (sizefirst < 1) {
		goto start;
	}
	int* arr = new int[sizefirst];
	fill(arr, sizefirst);
	sort(arr, sizefirst);
	cout << "The first arr:\n";
	output(arr, sizefirst);

	secondarr(arr, sizefirst);
	sort(arr, sizefirst);

	cout << "New arr is:\n";	//вивід нового масиву (сукупність 1 і 2 масивів)
	output(arr, sizefirst);

	
	
	
}

