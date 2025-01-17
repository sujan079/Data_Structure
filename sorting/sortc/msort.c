#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to merge two subarrays
void merge(int A[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temporary arrays
    int L[n1], R[n2];

    // Copy data into temporary arrays
    for (int i = 0; i < n1; i++)
        L[i] = A[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = A[m + 1 + j];

    // Merge the temporary arrays back into A[l..r]
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy any remaining elements of L[]
    while (i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }

    // Copy any remaining elements of R[]
    while (j < n2) {
        A[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int A[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;//

       
        mergeSort(A, l, m);
        mergeSort(A, m + 1, r);

        merge(A, l, m, r);
    }
}

void display(int A[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d, ", A[i]);
    printf("\n");
}

int main()
{
    int A[100000], n;
    clock_t start, end;
    double diff;

    printf("Enter n: ");p
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        A[i] = rand();
    }


    display(A, n);

    start = clock();
    mergeSort(A, 0, n - 1);
    end = clock();

    // Optionally display the sorted array
    printf("Sorted array: ");
    display(A, n);

    // Calculate and display the time taken
    diff = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", diff);

    return 0;
}
