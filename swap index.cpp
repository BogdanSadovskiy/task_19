using namespace std;

#include <iostream>
void fillthearr(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100 + 1;
    }
}
void outputarr(int* arr, int size) {
    
    for (int i = 0; i < size; i++) {
        cout <<"#"<<i+1<< " - "<< arr[i]<<endl;
    }
}
void swapindex(int* arr, int size) {                //міняє міцями парні з непарними індекси масива
    for (int i = 1; i < size; i++) {
        int n = arr[i];
        arr[i] = arr[i - 1];
        arr[i - 1] = n;
        i++;
    }
}
int main()
{
    start:
    cout << "Input size of array ";
    int size; cin >> size;
    if (size == 0) {
        goto start;
    }
    int* arr = new int[size];
    fillthearr(arr, size);
    outputarr(arr, size);
    swapindex(arr, size);
    cout << endl;
    cout << "The new array after swap:\n";
    outputarr(arr, size);


}

