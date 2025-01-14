#include <iostream>
#include <ctime>

using namespace std;

void split(const int* array, int size, int* positive_array, int* negative_array, int* zero_array, int* pos_count, int* neg_count, int* zero_count) {
    *pos_count = 0;
    *neg_count = 0;
    *zero_count = 0;

    for (int i = 0; i < size; i++) {
        if (array[i] > 0) {
            positive_array[(*pos_count)++] = array[i];
        }
        else if (array[i] < 0) {
            negative_array[(*neg_count)++] = array[i];
        }
        else {
            zero_array[(*zero_count)++] = array[i];
        }
    }
}

int main() {

    srand(time(0));


    const int size = 5;
    int array[size] = {};
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 7 - 3;
        cout << array[i] << " ";
    }

    cout << endl;

    int* positive_array = new int[size] {};
    int* negative_array = new int[size] {};
    int* zero_array = new int[size] {};

    int* pos_count = new int;
    int* neg_count = new int;
    int* zero_count = new int;

    split(array, size, positive_array, negative_array, zero_array, pos_count, neg_count, zero_count);

    cout << "Positive: ";
    for (int i = 0; i < *pos_count; i++) {
        cout << positive_array[i] << " ";
    }
    cout << endl;

    cout << "Negative: ";
    for (int i = 0; i < *neg_count; i++) {
        cout << negative_array[i] << " ";
    }
    cout << endl;

    cout << "Zero: ";
    for (int i = 0; i < *zero_count; i++) {
        cout << zero_array[i] << " ";
    }
    cout << endl;

    delete[] positive_array;
    delete[] negative_array;
    delete[] zero_array;
    delete pos_count;
    delete neg_count;
    delete zero_count;

    return 0;
}