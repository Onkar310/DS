#include <stdio.h>
int a[10] = {75, 10, 52, 35, 45, 78, 1, 99, 44, 88};
int b[10];
void merge(int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            i++;
            k++;
        }
        else
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }

    while (i <= mid)
    {
        b[k] = a[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        b[k] = a[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        a[i] = b[i];
    }
}

void mergeSort(int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(low, mid);
        mergeSort(mid + 1, high);
        merge(low, mid, high);
    }
}

int main()
{
    int n = 10;
    mergeSort(0, n - 1);
    printf("Sorted array is \n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d  ", b[i]);
    }
    return 0;
}