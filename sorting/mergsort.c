#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void display(int arr[], int n)
{
  int i;
  for (i = 0; i < n; i++)
  {
    printf(" %d", arr[i]);
  }
  printf("\n");
}

void merge(int arr[], int left, int mid, int right)
{
  int i = left, j = mid, k = right;
  int temp[1000000];
  while (i < mid && j <= right)
  {
    if (arr[i] < arr[j])
    {
      temp[k++] = arr[i++];
    }
    else
    {
      temp[k++] = arr[j++];
    }
  }

  for (; i < mid; i++, k++)
  {
    temp[k] = arr[j];
  }

  for (k = left; k <= right; k++)
  {
    arr[k] = temp[k];
  }
}
void mergeSort(int arr[], int left, int right)
{
  if (left < right)
  {
    int mid = left + (right - left) / 2;

    // Sort first and second halves
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    // Merge the sorted halves
    merge(arr, left, mid, right);
  }
}

int main()
{

  int n, i;
  srand(time(NULL));
  clock_t start, end, diff;

  printf("Enter n: ");
  scanf("%d", &n);

  int arr[n];

  for (i = 0; i < n; i++)
  {
    arr[i] = rand() % 100;
  }

//   printf("Original: \n");
//   display(arr, n);
  start = clock();
  mergeSort(arr, 0, n);
  end = clock();
//   printf("\n\nSorted: \n");
//   display(arr, n);

  diff = end - start;
  printf("Time taken %f\n", (float)(diff / CLOCKS_PER_SEC));
  return 0;
}