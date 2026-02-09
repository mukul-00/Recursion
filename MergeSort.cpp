#include <iostream>
using namespace std;

// Merge two sorted parts of array: [start..mid] and [mid+1..end]
void mergeArrays(int *arr, int start, int end) {

    int mid = (start + end) / 2;

    // Length of left and right subarrays
    int leftSize = mid - start + 1;
    int rightSize = end - mid;

    // Create temporary arrays
    int *left = new int[leftSize];
    int *right = new int[rightSize];

    // Copy data into left array
    int mainIndex = start;
    for(int i = 0; i < leftSize; i++) {
        left[i] = arr[mainIndex++];
    }

    // Copy data into right array
    mainIndex = mid + 1;
    for(int i = 0; i < rightSize; i++) {
        right[i] = arr[mainIndex++];
    }

    // Merge both sorted arrays back into original array
    int leftIndex = 0;
    int rightIndex = 0;
    mainIndex = start;

    while(leftIndex < leftSize && rightIndex < rightSize) {
        if(left[leftIndex] < right[rightIndex]) {
            arr[mainIndex++] = left[leftIndex++];
        } else {
            arr[mainIndex++] = right[rightIndex++];
        }
    }

    // Copy remaining elements of left array (if any)
    while(leftIndex < leftSize) {
        arr[mainIndex++] = left[leftIndex++];
    }

    // Copy remaining elements of right array (if any)
    while(rightIndex < rightSize) {
        arr[mainIndex++] = right[rightIndex++];
    }

    // Free dynamically allocated memory
    delete[] left;
    delete[] right;
}

// Recursive Merge Sort function
void mergeSort(int *arr, int start, int end) {

    // Base case: single element
    if(start >= end) return;

    int mid = (start + end) / 2;

    // Sort left half
    mergeSort(arr, start, mid);

    // Sort right half
    mergeSort(arr, mid + 1, end);

    // Merge both halves
    mergeArrays(arr, start, end);
}

int main() {

    int arr[15] = {3,7,0,1,5,8,3,2,34,66,87,23,12,12,12};
    int n = 15;

    // Perform Merge Sort
    mergeSort(arr, 0, n - 1);

    // Print sorted array
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
