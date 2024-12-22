#include <stdio.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
// return pivot index
int partition(int arr[], int low, int high) {

    // pick the last number
    int pivot = arr[high];

    // starting index - 1
    int i = low;

    // loop through from start to end
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            // swap them
            swap(&arr[i], &arr[j]);
            i++;
        }
    }

    printArray(arr, high + 1);      

    // swap i with pivot
    swap(&arr[i], &arr[high]);

    // i is the new pivot
    return i;
}

// devide array
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}



int main() {
    int arr[] = {14, 3, 10, 4, 5, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);
    printArray(arr, n);

}