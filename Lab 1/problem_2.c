#include <stdio.h>
#include <stdlib.h>

int main()
{

    // Read Employees Data
    int *p;
    int *q;
    p = (int *)malloc(1 * sizeof(int));
    int a = 0;
    int i = 0;
    printf("Enter Employee 1 gross sale(-1 to end): \n");
    while (scanf("%d", &a) != -1 && a != -1)
    {
        p[i] = a;
        q = (int *)malloc((i+2) * sizeof(int));
        for (int j = 0; j < (i + 1); j++)
        {
            q[j] = p[j];
        }
        free(p);
        p = q;
        q = NULL;
        i++;
        printf("Enter Employee %d gross sale(-1 to end): \n", i + 1);
    }
    printf("You entered the gross sales of total %d employees \n", i);
    printf("\n");
    // Compute the Salary of Each Employee
    int salary = 0;
    int *salaries;
    salaries = (int *)malloc(i * sizeof(int));
    for (int j = 0; j < i; j++)
    {
        salary = p[j] * (0.09) + 200;
        salaries[j] = salary;
        printf("Employee %d salary is $%d \n", j + 1, salaries[j]);
    }

    // Printing the Salaries Ranges
    int ranges[9] = {};
    for (int j = 0; j < i; j++)
    {
        if (salaries[j] >= 200 && salaries[j] <= 299)
            ranges[0]++;
        if (salaries[j] >= 300 && salaries[j] <= 399)
            ranges[1]++;
        if (salaries[j] >= 400 && salaries[j] <= 499)
            ranges[2]++;
        if (salaries[j] >= 500 && salaries[j] <= 599)
            ranges[3]++;
        if (salaries[j] >= 600 && salaries[j] <= 699)
            ranges[4]++;
        if (salaries[j] >= 700 && salaries[j] <= 799)
            ranges[5]++;
        if (salaries[j] >= 800 && salaries[j] <= 899)
            ranges[6]++;
        if (salaries[j] >= 900 && salaries[j] <= 999)
            ranges[7]++;
        if (salaries[j] >= 1000)
            ranges[8]++;
    }
    printf("Employees in the range: \n");
    printf("$200 <-> $299: %d \n", ranges[0]);
    printf("$300 <-> $399: %d \n", ranges[1]);
    printf("$400 <-> $499: %d \n", ranges[2]);
    printf("$500 <-> $599: %d \n", ranges[3]);
    printf("$600 <-> $699: %d \n", ranges[4]);
    printf("$700 <-> $799: %d \n", ranges[5]);
    printf("$800 <-> $899: %d \n", ranges[6]);
    printf("$900 <-> $999: %d \n", ranges[7]);
    printf("Over $1000: %d \n", ranges[8]);

    free(q);
    free(p);
    return 0;
}
