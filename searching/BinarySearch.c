#include <stdio.h>
int binarysearch(int array[], int N, int x)
{

    int l=0,h=N-1;
    while (l <= h)
    {
        int m = l + (h - l) / 2;

        if (array[m] == x)
            return m;
        if (array[m] < x) // if the element is greater
        {

            l = m + 1;
        }
        else
        { // if the element is lesser make change to h
            h = m - 1;
        }
    }
    return -1;
    
}
int main()
{
    int element, result;
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(array) / sizeof(array[0]);
    printf("Enter the element that you want to search\n");
    scanf("%d", &element);
    result = binarysearch(array, n, element);
    if (result == -1)
        printf("Search Unsucessful\n");
    else
        printf("Element is present at index %d", result);
}