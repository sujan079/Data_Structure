#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void mergeSort(int A[], int n)
{
    int i, j, temp;

    for (i = 0; i < n; i++)
    {
        temp = A[i];

        while (j >= 0 && temp < A[j])
        {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = temp;
    }
}

void display(int A[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ,", A[i]);
    }
    printf("\n");
}
int main()
{

    int A[10000], n, 
    clock_t start,end,diff;
    printf("Enter n:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        A[i] = rand();
    }
    // display(A, n);
    start = clock();
    mergeSort(A, n);
    end = clock();
    // display(A, n);
    int diff = end - start;
    printf("time taken %f", (float)diff / CLOCKS_PER_SEC);
}
