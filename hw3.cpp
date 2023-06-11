using namespace std;
#include <iostream>
void output(int* arr, int size) {

	for (int i = 0; i < size; i++) {		//вивід масива на екран
		cout << arr[i] << " ";
	}
	if (size == 0) {
		cout << "None";
	}
	cout << "\n-----------------------------------------\n";
	cout << endl;
}
void sort(int* arr, int size) { //сортування
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

void fill(int* arr, int size) {		//запоанення рамдомними числами
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 10 + 1;
	}
}

void connect2arr(int* arr, int size, int* arr2, int size2) {
	int newsize = size + size2;
	int* newarr = new int[newsize];
	for (int i = 0; i < newsize; i++) {
		while (i < size) {
			newarr[i] = arr[i];
			i++;
		}
		for (int j = 0; j < size2; j++) {
			newarr[i] = arr2[j];
			i++;
		}
	}
	cout << "Arr of two arrays:\n";
	sort(newarr, newsize);
	output(newarr, newsize);
}
void generalelements(int* arr, int size, int* arr2, int size2) {
	int newsize = 0;
	int count = 0;
	if (size <= size2) {
		newsize = size;
		count = size2;
	}
	else {
		newsize = size2;
		count = size;
	}
	int* newarr = new int[newsize];
	int k = 0;
	for (int i = 0; i < newsize; i++) {
		for (int j = 0; j < count; j++) {
			if (count == size2) {
				if (arr[i] == arr2[j]) {
					newarr[k] = arr2[j];
					k++;
					break;
				}
			}
			else {
				if (arr2[i] == arr[j]) {
					newarr[k] = arr[j];
					k++;
					break;
				}
			}
		}
	}
	newsize = k ;
	for (int i = 1; i < newsize; i++) {
		if (newarr[i] == newarr[i - 1]) {
			newsize--;
			i--;
			for (int j = i; j < size; j++) {
				newarr[j] = newarr[j + 1];
			}
		}
	}
	cout << "General numb arr:\n";
	sort(newarr, newsize);
	output(newarr, newsize);
	
}
void Aelements(int* arr, int size, int* arr2, int size2) {
	int* newarr = new int[size];
	int k = 0;
	int newsize = size;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size2; j++) {
			if (arr[i] == arr2[j]) {
				newsize--;
				break;
			}
			if (j == size2 - 1) {
				newarr[k] = arr[i];
				k++;
			}
		}
	}
	size = newsize;
	for (int i = 1; i < size; i++) {
		if (newarr[i] == newarr[i - 1]) {
			size--;
			
			for (int j = i; j < size; j++) {
				newarr[j] = newarr[j + 1];
			}
			i--;
		}
	}
	cout << "The elements of first arr that not repeated in second arr:\n";
	output(newarr, size);
}

void Belements(int* arr, int size, int* arr2, int size2) {
	int* newarr = new int[size2];
	int k = 0;
	int newsize = size2;
	for (int i = 0; i < size2; i++) {
		for (int j = 0; j < size; j++) {
			if (arr2[i] == arr[j]) {
				newsize--;
				break;
			}
			if (j == size - 1) {
				newarr[k] = arr2[i];
				k++;
			}
		}
	}
	size2 = newsize;
	for (int i = 1; i < size2; i++) {
		if (newarr[i] == newarr[i - 1]) {
			size2--;
			
			for (int j = i; j < size2; j++) {
				newarr[j] = newarr[j + 1];
			}
			i--;
		}
	}
	cout << "The elements of second arr that not repeated in first arr:\n";
	output(newarr, size2);
}
void notrepeated(int* arr, int size, int* arr2, int size2) {
	int* newarr = new int[size + size2];
	int k = 0;
	int newsize = size2+size;
	for (int i = 0; i < size2; i++) {
		for (int j = 0; j < size; j++) {
			if (arr2[i] == arr[j]) {
				newsize--;
				break;
			}
			if (j == size - 1) {
				newarr[k] = arr2[i];
				k++;
			}
		}
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size2; j++) {
			if (arr[i] == arr2[j]) {
				newsize--;
				break;
			}
			if (j == size2 - 1) {
				newarr[k] = arr[i];
				k++;
			}
		}
	}
	sort(newarr, newsize);
	for (int i = 1; i < newsize; i++) {
		if (newarr[i] == newarr[i - 1]) {
			newsize--;
			
			for (int j = i; j < newsize; j++) {
				newarr[j] = newarr[j + 1];
			}
			i--;
		}
	}
	cout << "The elements that not repeated in two arrs:\n";
	output(newarr, newsize);
}

int main()
{
	int sizefirst, sizesecond;
start:
	cout << "Input size of first array  ";
	cin >> sizefirst;
	if (sizefirst < 1) {
		goto start;
	}
	int* arr = new int[sizefirst];

start2:
	cout << "Input size of second array  ";
	cin >> sizesecond;
	if (sizesecond < 1) {
		goto start2;
	}
	int* arr2 = new int[sizesecond];
	cout << "First arr:\n";
	fill(arr, sizefirst);
	sort(arr, sizefirst);
	output(arr, sizefirst);

	cout << "Second arr:\n";
	fill(arr2, sizesecond);
	sort(arr2, sizesecond);
	output(arr2, sizesecond);
	

	connect2arr(arr, sizefirst, arr2, sizesecond);

	generalelements(arr, sizefirst, arr2, sizesecond);

	Aelements(arr, sizefirst, arr2, sizesecond);

	Belements(arr, sizefirst, arr2, sizesecond);

	notrepeated(arr, sizefirst, arr2, sizesecond);


}
