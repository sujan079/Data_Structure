#include <stdio.h>

// Function to perform quick sort
void quicksort(int a[], int n)
{
    int i, j, temp, pivot;

    if (n < 2)
        return;

    pivot = a[n / 2];

    for (i = 0, j = n - 1;; i++, j--)
    {
        while (a[i] < pivot)
            i++;
        while (a[j] > pivot)
            j--;

        if (i >= j)
            break;

        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    quicksort(a, i);
    quicksort(a + i, n - i);
    
}

// Function to print the aay
void display(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main()
{
    int a[10000];
    int n = sizeof(a) / sizeof(a[0]);

    printf("Original aay: ");
    display(a, n);

    quicksort(a, n);

    printf("Sorted aay: ");
    display(a, n);
    return 0;
}
