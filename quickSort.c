#include <stdio.h>
int a[10] = {43, 12, 74, 25, 22, 32, 47, 98, 7, 1};

int partition(int low, int high)
{
    int i = low;
    int pivot = a[low];
    int j = high;
    int temp;
    while (i < j)
    {

        while (a[i] <= pivot)
        {
            i++;
        }
        while (a[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {

            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    temp = a[j];
    a[j] = a[low];
    a[low] = temp;
    return j;
}

void quickSort(int low, int high)
{
    int k;
    if (low < high)
    {
        k = partition(low, high);
        quickSort(low, k - 1);
        quickSort(k + 1, high);
    }
}

int main()
{
    int n = 10;
    printf("Unsorted array is \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", a[i]);
    }
    printf("\n");
    quickSort(0, n - 1);
    printf("Sorted array is \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", a[i]);
    }

    return 0;
}
