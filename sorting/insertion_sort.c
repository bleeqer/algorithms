#include <stdio.h>

void insertionSort(int arr[], int n) {
    // 12, 11, 13, 5, 6
    // 11, 12, 13, 5, 6
    // 11, 12, 13, 5, 6
    // 5, 11, 12, 13, 6
    // 5, 6, 11, 12, 13
    for (int i = 1; i < n; i++) {
        // 11
        // 13
        // 5
        // 6
        int key = arr[i];
        // 0
        // 1
        // 2
        // 3
        int j = i - 1;

        // 12 > 11 = true
        // 12 > 13 = false
        // 13 > 5 = true
        // 12 > 5 = true
        // 11 > 5 = true
        // 13 > 6 = true
        // 12 > 6 = true
        // 11 > 6 = true
        // 5 > 6 = false
        while (j >= 0 && arr[j] > key) {
            
            // arr[1] = 12
            // arr[3] = 13
            // arr[2] = 12
            // arr[1] = 11
            // arr[4] = 13
            // arr[3] = 12
            // arr[2] = 11
            arr[j + 1] = arr[j];
            // -1
            // 1
            // 0
            // -1
            // 2
            // 1
            // 0
            j = j - 1;
        }

        // arr[0] = 11
        // arr[2] = 13
        // arr[0] = 5
        // arr[1] = 6
        arr[j + 1] = key;


    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);
    printArray(arr, n);
    return 0;
}
