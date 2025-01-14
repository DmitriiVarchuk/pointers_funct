#include <iostream>
#include <ctime>

using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int j = 2; j * j <= n; ++j)
        if (n % j == 0) return false;
    return true;
}

int main() {

    srand(time(0));


    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100 - 1;
        cout << arr[i] << " ";
    }
    cout << endl;

    int newSize = 0;
    for (int i = 0; i < size; i++) {
        if (!isPrime(arr[i])) {
            newSize++;
        }
    }

    int* temp = new int[newSize];
    int index = 0;
    for (int i = 0; i < size; i++) {
        if (!isPrime(arr[i])) {
            temp[index++] = arr[i];
        }
    }


    cout << "The array without prime numbers: " << endl;
    for (int i = 0; i < newSize; i++) {
        arr[i] = temp[i];
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    delete[] temp;

    return 0;
}