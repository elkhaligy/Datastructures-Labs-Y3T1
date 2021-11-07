#include <stdio.h>
#include <stdlib.h>

void insertion_sort_asc(int A[], int n)
{
    int j = 0;
    int x = 0;
    for (int i = 1; i < n; i++)
    {
        j = i - 1;
        x = A[i];
        while (j > -1 && A[j] > x)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = x;
    }
}
int main(void)
{
    int n=0; // number of developers
    int q=0; // number of tasks
    scanf("%d", &n);
    scanf("%d", &q);
    int *h;
    int *t;
    h = (int *)calloc(n, sizeof(int)); // hours of each developer
    t = (int *)calloc(q, sizeof(int)); // hours of each task


    for (int i = 0; i < n; i++)
    {
        scanf("%d", h + i);
    }
    for (int i = 0; i < q; i++)
    {
        scanf("%d", t + i);
    }
    insertion_sort_asc(h, n);
    insertion_sort_asc(t, q);
   /* for (int i = 0; i < n; i++)
    {
        printf("%d ", *(h + i));
    }
    printf("\n");
    for (int i = 0; i < q; i++)
    {
        printf("%d ", *(t + i));
    }
    printf("\n");
    */
    int max_devs = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = max_devs; j < q; j++)
        {
            // j+=max_devs;
            if (h[i] >= t[j])
            {
                max_devs++;
                break;
            }
            break;
        }
    }
    printf("%d", max_devs);
    
    free(h);
    free(t);
}
