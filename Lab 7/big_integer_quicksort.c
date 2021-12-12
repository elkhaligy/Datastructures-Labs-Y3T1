#include <stdio.h>
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
long long int concatenate(long long int x, long long int y)
{
    long long int pow = 10;
    while (y >= pow)
        pow *= 10;
    return x * pow + y;
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++)
    {
        if (concatenate(arr[j], pivot) < concatenate(pivot, arr[j]))
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (1 + i);
}
void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int j = partition(arr, low, high);
        quicksort(arr, low, j - 1);
        quicksort(arr, j + 1, high);
    }
}
int main(void)
{

    int n;
    scanf("%d", &n);
    int A[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);
    quicksort(A, 0, n - 1);
    for (int i = n - 1; i >= 0; i--)
        printf("%d", A[i]);
    return 0;
}
