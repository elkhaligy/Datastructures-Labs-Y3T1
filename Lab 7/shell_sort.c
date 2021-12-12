#include <stdio.h>
#include <stdlib.h>

void shell_sort(int A[], int n)
{
    int gap, i, j, temp;

    for (gap = n / 2; gap >= 1; gap /= 2)
    {
        for (i = gap; i < n; i++)
        {
            temp = A[i];
            j = i - gap;
            while (j >= 0 && A[j] > temp)
            {
                A[j + gap] = A[j];
                j = j - gap;
            }
            A[j + gap] = temp;
        }
    }
}

int main(void)
{
    int n, k;
    scanf("%d%d", &n, &k);
    int A[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);
    shell_sort(A, n);
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
    printf("%d", A[n - k]);
    return 0;
}
