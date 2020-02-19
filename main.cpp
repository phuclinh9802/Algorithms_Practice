/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

vector<int> bubbleSort(vector<int> arr) {
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr.size() - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return arr;
}

vector<int> selectionSort(vector<int> arr) {
    for (int i = 0; i < arr.size(); i++) {
        int store = i;
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[j] < arr[store]) {
                store = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[store];
        arr[store] = temp;
    }
    return arr;
}

vector<int> insertionSort(vector<int> arr) {
    for (int i = 1; i < arr.size(); i++) {
        int store = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > store) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = store;
    }
    return arr;
}


void merge(int arr[], int start, int mid, int end) {
    
    int l = mid - start + 1;
    int r = end - mid;
    
    int left[l], right[r];
    
    for (int i = 0; i < l; i++) {
        left[i] = arr[start + i];
    }
    for (int i = 0; i < r; i++) {
        right[i] = arr[mid + 1 + i];
    }
    int i, j, k;
    
    i = 0;
    j = 0;
    k = start;
    
    while (i < l && j < r) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        }
        else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    
    while (i < l) {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < r) {
        arr[k] = right[j];
        j++;
        k++;
    }
    
}
void mergeSort(int arr[], int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}
int partition(int arr[], int start, int end) {
    int pivot = arr[end];
    int i = start - 1;
    
    for (int j = start; j < end; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[end]);
    return i + 1;
}
void quickSort(int arr[], int start, int end) {
    if (start < end) {
        int pivot = partition(arr, start, end);
        quickSort(arr, start, pivot - 1);
        quickSort(arr, pivot + 1, end);
    }
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    
    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }
    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }
    
    if (largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[i], arr[0]);
        
        heapify(arr, i, 0);
    }
}
int main()
{
    
    vector<int> arr = {3,4,-1,5,2};
    vector<int> result = bubbleSort(arr);
    // for (int i : result) {
    //     cout << i << " ";
    // }
    
    int arr1[] = {3,4,-1,5,2};
    int arr_length = sizeof(arr1)/sizeof(arr1[0]);
    //mergeSort(arr1, 0, arr_length - 1);
    //quickSort(arr1, 0, arr_length - 1);
    heapSort(arr1, arr_length);
    for (int i = 0; i < arr_length; i++) {
        cout << arr1[i] << " ";
    }
}
