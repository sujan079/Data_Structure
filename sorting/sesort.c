#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionsort(int A[], int n)
{
    int i, least, POS, j, temp;
    for (i = 0; i < n - 1; i++) // Loop through unsorted portion
    {
        least = A[i];
        POS = i;

        // Find the smallest element in the unsorted portion
        for (j = i + 1; j < n; j++)
        {
            if (A[j] < least)
            {
                least = A[j];
                POS = j;
            }
        }

        // Swap the found minimum with the first element of the unsorted portion
        if (i != POS)
        {
            temp = A[i];
            A[i] = A[POS];
            A[POS] = temp;
        }
    }
}

void display(int A[], int n)
{
    int i;
    if (n > 20) // Display partial output for large arrays
    {
        printf("[ ");
        for (i = 0; i < 10; i++)
            printf("%d ", A[i]);
        printf("... ");
        for (i = n - 10; i < n; i++)
            printf("%d ", A[i]);
        printf("]\n");
    }
    else
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
    selectionsort(A, n);
    end = clock();

    // printf("Sorted array:\n");
    // display(A, n);

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("The time taken is %f seconds\n", time_taken);

    return 0;
}