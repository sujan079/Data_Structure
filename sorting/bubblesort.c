#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void BubbleSort(int A[], int n) {
    int i, j, temp;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - 1; j++) {
            if (A[j] > A[j + 1]) {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

void display(int A[], int n) {
    int i;
    for (i = 0; i < n; i++) {
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
    BubbleSort(A, n);
    end = clock();

    // printf("Sorted array:\n");
    // display(A, n);

    diff = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", diff);

    return 0;
}