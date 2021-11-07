#include <stdio.h>
#include <stdlib.h>

int main()
{
    float arr[5] = {};
    printf("Enter 5 numbers:\n");
    for (int i = 0; i < 5; i++)
    {
        scanf("%f", &arr[i]);
    }
    int pos_count = 0;
    float pos_sum = 0;
    int neg_count = 0;
    float neg_sum = 0;
    for (int i = 0; i < 5; i++)
    {
        if (arr[i] > 0)
        {
            pos_count++;
            pos_sum += arr[i];
        }
        else
        {
            neg_count++;
            neg_sum += arr[i];
        }
    }
    printf("Number of positive numbers:%d \n", pos_count);
    printf("Number of negative numbers:%d \n", neg_count);
    printf("Average of positive numbers:%.2f \n", pos_sum / pos_count);
    printf("Average of negative numbers:%.2f \n", neg_sum / neg_count);

    return 0;
}
