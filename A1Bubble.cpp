#include <iostream>
using namespace std;

void BubbleSort(int arr[], int n) 
{ 
    int i, j; 
    for (i = 0; i < n - 1; i++) 
        for (j = 0; j < n - i - 1; j++) 
            if (arr[j] > arr[j + 1]) 
                swap(arr[j], arr[j + 1]); 
} 
  
void display(int arr[], int size) 
{ 
    int i; 
    for (i = 0; i < size; i++) 
        cout << arr[i] << " "; 
    cout << endl; 
} 

int main() 
{ 
    int arr[] = {4,2,1,8,10}; 
    int N = sizeof(arr) / sizeof(arr[0]); 
    BubbleSort(arr, N); 
    cout << "Sorted by Bubble Sort: \n"; 
    display(arr, N); 
    return 0; 
}