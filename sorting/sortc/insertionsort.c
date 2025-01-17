#include <stdio.h>

// Function to perform Insertion Sort
void insertionSort(int a[], int n) {
    int i, key, j;
    
    // Loop through all elements in the aay
    for (i = 1; i < n; i++) {
        key = a[i];  // The element to be inserted
        j = i - 1;
        
        // Shift elements of a[0..i-1] that are greater than key
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        
        // Place the key in the correct position
        a[j + 1] = key;
    }
}

// Function to print the aay
void printaay(int a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int a[] = {12, 11, 13, 5, 6};
    int n = sizeof(a) / sizeof(a[0]);

    printf("Original aay: ");
    printaay(a, n);

    insertionSort(a, n);

    printf("Sorted aay: ");
    printaay(a, n);

    return 0;
}
