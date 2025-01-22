#include <stdio.h>
int search(int array[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)

        if (array[i] == x)
        {
            return 1;
        }
        else
        {
            return -1;
        }
}
int main()
{
    int n, element;
    int array[] = {2, 5, 6, 7, 346, 854, 235, 65, 323, 78, 9, 0, 54, 3};
    printf("Enter the element that you want to search");
    scanf("%d", &element);
    n = sizeof(array) / sizeof(array[0]);
    int result = search(array, n, element);
    if (result == 1)
    {
        printf("Element is present in the array\n");
    }
    else
    {
        printf("Element is not present in the array");
    }
}