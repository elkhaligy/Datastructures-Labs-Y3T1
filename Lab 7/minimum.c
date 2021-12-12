#include <stdio.h>

int main()
{
    int n, r;
    //printf("Enter no of elements and removals:\n");
    scanf("%d", &n);
    scanf("%d", &r);

    int A[n][2], B[n][2];

    //printf("Enter array elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i][0]);
        A[i][1] = 0;
    }

    // Making B (2D Matrix With Unique Items)
    int k = 0, freq;
    for (int i = 0; i < n; i++)
    {
        if (A[i][1] == 0)
        {
            freq = 1;
            for (int j = i + 1; j < n; j++)
            {
                if (A[i][0] == A[j][0])
                {
                    A[j][1] = 1;
                    freq++;
                }
            }
            B[k][0] = A[i][0];
            B[k][1] = freq;
            k++;
        }
    }
    n = k;

    // Sorting B (Based on frequency)
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        temp = B[i][1];
        for (int j = i + 1; j < n; j++)
        {
            if (temp < B[j][1])
            {
                temp = B[j][1];
                B[j][1] = B[i][1];
                B[i][1] = temp;

                temp = B[j][0];
                B[j][0] = B[i][0];
                B[i][0] = temp;
            }
        }
    }

    // for (int i = n - 1; i >= 0; i--)
    // {
    //     printf("%d %d\n", B[i][0], B[i][1]);
    // }

    int uniq = 0;
    int ind = n - 1;
    while (1)
    {
        if (B[ind][1] != 0 && r != 0)
        {
            B[ind][1]--;
            r--;
        }
        else
            ind--;
        //r--;
        if (r == 0 || r < 0)
            break;
    }
    // for (int i = n - 1; i >= 0; i--)
    // {
    //     if (r == 0 || r < 0)
    //         break;
    //     if (B[i][1] != 0)
    //     {
    //         B[i][1]--;
    //         r--;
    //     }
    // }

    // for (int i = n - 1; i >= 0; i--)
    // {
    //     printf("%d %d\n", B[i][0], B[i][1]);
    // }

    for (int i = n - 1; i >= 0; i--)
    {
        //printf("%d", B[i][0]);
        if (B[i][1] != 0)
            uniq++;
    }
    printf("%d", uniq);
    return 0;
}
