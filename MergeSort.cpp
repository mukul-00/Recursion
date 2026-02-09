#include <iostream>
using namespace std;

// Merge two sorted parts
void merge(int *arr, int s, int e) {

    int mid = (s + e) / 2;

    int n1 = mid - s + 1;
    int n2 = e - mid;

    int *L = new int[n1];
    int *R = new int[n2];

    int k = s;

    // copy left
    for(int i = 0; i < n1; i++)
        L[i] = arr[k++];

    // copy right
    k = mid + 1;
    for(int i = 0; i < n2; i++)
        R[i] = arr[k++];

    int i = 0, j = 0;
    k = s;

    // merge
    while(i < n1 && j < n2) {
        if(L[i] < R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    // remaining left
    while(i < n1)
        arr[k++] = L[i++];

    // remaining right
    while(j < n2)
        arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void sortArr(int *arr, int s, int e) {

    if(s >= e) return;

    int mid = (s + e) / 2;

    sortArr(arr, s, mid);
    sortArr(arr, mid + 1, e);

    merge(arr, s, e);
}

int main() {

    int arr[15] = {3,7,0,1,5,8,3,2,34,66,87,23,12,12,12};
    int n = 15;

    sortArr(arr, 0, n - 1);

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
