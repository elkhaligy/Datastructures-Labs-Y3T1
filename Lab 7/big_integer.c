#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
long long int concatenate(long long int x, long long int y);
void swap(long long int *x, long long int *y);

long long int main(void)
{
    
    long long int n;
    scanf("%lld", &n);
    long long int A[n];
    for (long long int i = 0; i < n; i++)
        scanf("%lld", &A[i]);
    for (long long int i = 0; i < n - 1; i++)
    {
        for (long long int j = i; j < n; j++)
            if (concatenate(A[i], A[j]) <= concatenate(A[j], A[i]))
                swap(&A[i], &A[j]);
    }
    long long int max = A[0];
    for (long long int i = 1; i < n; i++)
    {
        if (max < A[i])
            max = A[i];
    }
    if (max == 0)
    {
        printf("0");
        return 0;
    }
    for (long long int i = 0; i < n; i++)
        printf("%lld", A[i]);
    return 0;
}
long long int concatenate(long long int x, long long int y)
{
    long long int pow = 10;
    while (y >= pow)
        pow *= 10;
    return x * pow + y;
}

void swap(long long int *x, long long int *y)
{
    long long int temp = *x;
    *x = *y;
    *y = temp;
}
