#include <iostream>
#include <ctime>

using namespace std;

void menu(int** data, int* length);
void allocateMemory(int** data, int* length);
void initializeArray(int* data, int length);
void printArray(int* data, int length);
void freeMemory(int*& data);
void appendElement(int** data, int* length, int value);
void insertElement(int** data, int* length, int value, int position);
void removeElement(int** data, int* length, int position);

int main() {

	srand(time(0)); 

    int* data = nullptr;
    int length = 0;
    menu(&data, &length);
    if (data != nullptr) {
        freeMemory(data);
    }
    return 0;
}

void menu(int** data, int* length) {

    int choice;
    do {
        cout << "Menu:\n";
        cout << "1. Allocate memory\n";
        cout << "2. Initialize array\n";
        cout << "3. Print array\n";
        cout << "4. Append element\n";
        cout << "5. Insert element at position\n";
        cout << "6. Remove element from position\n";
        cout << "7. Free memory and exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        system("cls");

        switch (choice) {
        case 1:
            allocateMemory(data, length);
            break;
        case 2:
            if (*data == nullptr) {
                cout << "Array not allocated. Please allocate memory first.\n";
            }
            else {
                initializeArray(*data, *length);
            }
            break;
        case 3:
            if (*data == nullptr) {
                cout << "Array not allocated. Please allocate memory first.\n";
            }
            else {
                printArray(*data, *length);
            }
            break;
        case 4: {
            if (*data == nullptr) {
                cout << "Array not allocated. Please allocate memory first.\n";
            }
            else {
                int value;
                cout << "Enter value to append: ";
                cin >> value;
                appendElement(data, length, value);
            }
            break;
        }
        case 5: {
            if (*data == nullptr) {
                cout << "Array not allocated. Please allocate memory first.\n";
            }
            else {
                int value, position;
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter position: ";
                cin >> position;
                insertElement(data, length, value, position);
            }
            break;
        }
        case 6: {
            if (*data == nullptr) {
                cout << "Array not allocated. Please allocate memory first.\n";
            }
            else {
                int position;
                cout << "Enter position to remove: ";
                cin >> position;
                removeElement(data, length, position);
            }
            break;
        }
        case 7:
            freeMemory(*data);
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);
}

void allocateMemory(int** data, int* length) {
    if (*data != nullptr) {
        delete[] * data;
    }
    cout << "Enter the size of the array: ";
    cin >> *length;
    *data = new int[*length];
}

void initializeArray(int* data, int length) {
    for (int i = 0; i < length; i++) {
        data[i] = rand() % 100 - 1;;
    }
}

void printArray(int* data, int length) {
    for (int i = 0; i < length; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

void freeMemory(int*& data) {
    delete[] data;
    data = nullptr;
}

void appendElement(int** data, int* length, int value) {
    int* newData = new int[*length + 1];
    for (int i = 0; i < *length; i++) {
        newData[i] = (*data)[i];
    }
    newData[*length] = value;
    delete[] * data;
    *data = newData;
    *length += 1;
}

void insertElement(int** data, int* length, int value, int position) {
    if (position < 0 || position > *length) {
        cout << "Position out of range.\n";
        return;
    }
    int* newData = new int[*length + 1];
    for (int i = 0; i < position; i++) {
        newData[i] = (*data)[i];
    }
    newData[position] = value;
    for (int i = position + 1; i < *length + 1; i++) {
        newData[i] = (*data)[i - 1];
    }
    delete[] * data;
    *data = newData;
    *length += 1;
}

void removeElement(int** data, int* length, int position) {
    if (position < 0 || position >= *length) {
        cout << "Position out of range.\n";
        return;
    }
    int* newData = new int[*length - 1];
    for (int i = 0; i < position; i++) {
        newData[i] = (*data)[i];
    }
    for (int i = position; i < *length - 1; i++) {
        newData[i] = (*data)[i + 1];
    }
    delete[] * data;
    *data = newData;
    *length -= 1;
}
