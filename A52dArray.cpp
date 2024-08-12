#include <iostream>
using namespace std;

int main() {
    char t,arrangement; 
    int r,c,baseadd,i,j; 

    cout << "Enter Array type ";
    cin >> t;

    cout << "Enter number of rows: ";
    cin >> r;

    cout << "Enter number of columns: ";
    cin >> c;

    cout << "Enter the memory arrangement (R/C Major): ";
    cin >> arrangement;

    cout << "Enter the base address of array: ";
    cin >> baseadd;

    cout << "Enter the index of the element: ";
    cin >> i >> j;

    int size; 
    if (t == 'i') {
        size = sizeof(int);
    } else if (t == 'c') {
        size = sizeof(char);
    } else if (t == 'f') {
        size = sizeof(float);
    } else {
        cout << "Invalid type" << endl;
        return 1;
    }

    int address;
    if (arrangement == 'R' || arrangement == 'r') {
        address = baseadd + (i * c + j) * size;
    } else if (arrangement == 'C' || arrangement == 'c') {
        address = baseadd + (j * r + i) * size;
    } else {
        cout << "Invalid arrangement" << endl;
        return 1;
    }

    cout << "The address of the element at (" << i << ", " << j << ") is: " << address << endl;

    return 0;
}