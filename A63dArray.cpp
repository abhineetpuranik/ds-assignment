#include<iostream>
using namespace std;

int main() {
    // Step 1: Input the type of array
    string t;
    cout << "Enter type of array: ";
    cin >> t;

    int typeSize;
    if (t == "int") typeSize = sizeof(int);
    else if (t == "char") typeSize = sizeof(char);
    else if (t == "float") typeSize = sizeof(float);
    else {
        cout << "Unsupported type!" << endl;
        return 1;
    }

    int r, c, d;
    cout << "Enter rows:";
    cin >> r;
    cout << "Enter columns:";
    cin >> c;
    cout << "Enter depth: ";
    cin >> d;

    string arrangement;
    cout << "Enter memory arrangement (ROW/COLUMN): ";
    cin >> arrangement;

    int baseAddress;
    cout << "Enter the base address of the array: ";
    cin >> baseAddress;

    int i, j, k;
    cout << "Enter the index of the element (i j k): ";
    cin >> i >> j >> k;

    int address;
    if (arrangement == "ROW") {
        address = baseAddress + ((i * c * d) + (j * d) + k) * typeSize;
    } else if (arrangement == "COLUMN") {
        address = baseAddress + ((k * r * c) + (j * r) + i) * typeSize;
    } else {
        cout << "Invalid memory arrangement!" << endl;
        return 1;
    }

    cout << "The address of the element at (" << i << ", " << j << ", " << k << ") is: " << address << endl;

    return 0;
}