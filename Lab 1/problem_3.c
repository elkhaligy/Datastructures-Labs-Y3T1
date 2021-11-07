#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int matrix_1[3][3] = {};
    int matrix_2[3][3] = {};
    printf("Enter matrix 1 (3x3) values:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &matrix_1[i][j]);
        }
    }
    printf("\n");
    printf("Enter matrix 2 (3x3) values:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &matrix_2[i][j]);
        }
    }

    printf("\n");
    printf("Matrix 1 (3x3) values:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d  ", matrix_1[i][j]);
        }
        printf("\n");
    }
    printf("Matrix 2 (3x3) values:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d  ", matrix_2[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    int *p1;
    p1 = &matrix_1[0][0];
    int *p2;
    p2 = &matrix_2[0][0];
    int sum[3][3] = {};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            sum[i][j] = *p1 + *p2;
            p1++;
            p2++;
        }
    }
    printf("Sum of matrix 1 and matrix 2 is:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d  ", sum[i][j]);
        }
        printf("\n");
    }
    return 0;
}
