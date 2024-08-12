#include <iostream>
#include <vector>
using namespace std;

void BubbleSort(vector<int>& v, int& comparisons, int& swaps) {
    int n = v.size();
    comparisons = swaps = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (v[j] > v[j + 1]) {
                swap(v[j], v[j + 1]);
                swaps++;
            }
        }
    }
}

void InsertionSort(vector<int>& v, int& comparisons, int& swaps) {
    int n = v.size();
    comparisons = swaps = 0;

    for (int i = 1; i < n; i++) {
        int current = v[i];
        int j = i - 1;
        comparisons++;
        while (j >= 0 && v[j] > current) {
            v[j + 1] = v[j];
            j--;
            comparisons++;
            swaps++;
        }
        v[j + 1] = current;
        if (j + 1 != i) swaps++;
    }
}

void SelectionSort(vector<int>& v, int& comparisons, int& swaps) {
    int n = v.size();
    comparisons = swaps = 0;

    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (v[j] < v[min_idx]) {
                min_idx = j;
            }
        }
        if (i != min_idx) {
            swap(v[i], v[min_idx]);
            swaps++;
        }
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> vec(n);
    
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    vector<int> bubble_vec = vec;
    vector<int> insertion_vec = vec;
    vector<int> selection_vec = vec;

    int comparisons, swaps;

    BubbleSort(bubble_vec, comparisons, swaps);
    cout << "Comparisions in Bubble Sort " << comparisons << " Swaps in Bubble Sort " << swaps << endl;

    InsertionSort(insertion_vec, comparisons, swaps);
    cout << "Comparisions in Insertion Sort " << comparisons << " Swaps in Insertion Sort " << swaps << endl;

    SelectionSort(selection_vec, comparisons, swaps);
    cout << "Comparisions in Selection Sort " << comparisons << " Swaps in Selection Sort " << swaps << endl;

    return 0;
}