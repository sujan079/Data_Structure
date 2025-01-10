#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int A[], int n)
{
    int i, j, temp;
    for (i = 1; i < n; i++) // Start from the second element
    {
        temp = A[i]; // Store the current element
        j = i - 1;

        // Shift elements of A[0..i-1] that are greater than temp
        while (j >= 0 && temp < A[j])
        {
            A[j + 1] = A[j];
            j = j - 1;
        }

        A[j + 1] = temp; // Place temp in the correct position
    }
}

void display(int A[], int n)
{
    int i;
    if (n > 20) // If array size is large, display first and last 10 elements
    {
        printf("[ ");
        for (i = 0; i < 10; i++)
            printf("%d ", A[i]);
        printf("... ");
        for (i = n - 10; i < n; i++)
            printf("%d ", A[i]);
        printf("]\n");
    }
    else // Display full array for smaller inputs
    {
        for (i = 0; i < n; i++)
            printf("%d ", A[i]);
        printf("\n");
    }
}

int main()
{
    int A[100000], n, i;
    clock_t start, end;
    double time_taken;

    printf("Enter n (1-100000): ");
    scanf("%d", &n);

    if (n <= 0 || n > 100000)
    {
        printf("Invalid input for n. Please enter a value between 1 and 100000.\n");
        return 1;
    }

    srand(time(0)); // Initialize random seed
    for (i = 0; i < n; i++)
        A[i] = rand() % 10000; // Limit random values for readability

    // printf("Unsorted array:\n");
    // display(A, n);

    start = clock();
    insertionSort(A, n);
    end = clock();

    // printf("Sorted array:\n");
    // display(A, n);

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("The time taken is %f seconds\n", time_taken);

    return 0;
}