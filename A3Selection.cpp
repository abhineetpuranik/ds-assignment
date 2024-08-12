#include <iostream>
using namespace std;

void SelectionSort(int arr[], int n)  
{  
    int i, j;  
    for (i = 0; i < n-1; i++)  
    {  
        for (j = i+1; j < n; j++)  
        if (arr[j] < arr[i]) {
            swap(arr[j],arr[i]);
        }
              
          
    }  
}  
void display(int arr[], int size)  
{  
    int i;  
    for (i=0; i < size; i++)  
        cout << arr[i] << " ";  
    cout << endl;  
}  
  
int main()  
{  
    int arr[] = {2,89,16,27,52};  
    int n = sizeof(arr)/sizeof(arr[0]);  
    SelectionSort(arr, n);  
    cout << "Sorted by Selection Sort: ";  
    display(arr, n);  
    return 0;  
}  