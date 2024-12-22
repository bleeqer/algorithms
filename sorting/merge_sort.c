#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l, int m, int r) {
    int i, j, k;

    // middle - left + 1
    int n1 = m - l + 1;

    // right + middle
    int n2 = r - m;

    // arrays of lengths of n1, n2
    int L[n1], R[n2];

    // put elements from arr starting from zero
    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }

    // put elements from arr starting from middle
    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = l; // left

    // loop through L and R
    while (i < n1 && j < n2) {

        // if L[i] is equal or smaller than R[j]
        if (L[i] <= R[j]) {

            // put smaller number in the array first at left and increment i by one
            arr[k] = L[i]; 
            i++; 
        } else { // if R[j] is smaller than L[i]
            arr[k] = R[j]; // put smaller number which is R[j] in the array and increment j by one
            j++;
        }
        k++; // increment k by one
    }

    // put the rest(which is bigger numbers) into the array 
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // put the rest(which is bigger numbers) into the array 
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {

    // left < right
    if (l < r) {

        // middle of left and right
        int m = l + (r - l) / 2;

        // divide again
        mergeSort(arr, l, m);

        // divide the other half
        mergeSort(arr, m + 1, r);

        // merge
        merge(arr, l, m, r);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    printf("Given array is \n");
    printArray(arr, arrSize);

    mergeSort(arr, 0, arrSize - 1);

    printf("\nSourted array is\n");
    printArray(arr, arrSize);
    return 0;
}