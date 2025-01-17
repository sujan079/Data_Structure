#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to heapify a subtree rooted at index i
void heapify(int A[], int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // Left child
    int right = 2 * i + 2; // Right child

    // If left child is larger than root
    if (left < n && A[left] > A[largest]) {
        largest = left;
    }

    // If right child is larger than largest so far
    if (right < n && A[right] > A[largest]) {
        largest = right;
    }

    // If largest is not root
    if (largest != i) {
        int temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;

        // Recursively heapify the affected sub-tree
        heapify(A, n, largest);
    }
}

// Main function to perform heap sort
void HeapSort(int A[], int n) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(A, n, i);
    }

    // One by one extract elements from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        int temp = A[0];
        A[0] = A[i];
        A[i] = temp;

        // Call max heapify on the reduced heap
        heapify(A, i, 0);
    }
}

void display(int A[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", A[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("\n");
}

int main() {
    int A[100000], n;
    clock_t start, end;
    double diff;

    printf("Enter n: ");
    scanf("%d", &n);

    // Seed the random number generator
    srand(time(NULL)); // so that rand() generates different numbers each time

    for (int i = 0; i < n; i++) {
        A[i] = rand();
    }

    // printf("Unsorted array:\n");
    // display(A, n);

    start = clock();
    HeapSort(A, n);
    end = clock();

    // printf("Sorted array:\n");
    // display(A, n);

    diff = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", diff);

    return 0;
}
