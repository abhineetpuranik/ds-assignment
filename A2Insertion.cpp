#include <iostream>
using namespace std;

void InsertionSort(int arr[], int n) 
{ 
    int i, j; 
    for (i = 0; i < n; i++) 
        for (j=i-1;j>=0;j--) 
            if (arr[j+1] <arr[j]){
                swap(arr[j+1], arr[j]);
            }else break;
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
    InsertionSort(arr, N); 
    cout << "Sorted by Insertion Sort: \n"; 
    display(arr, N); 
    return 0; 
}