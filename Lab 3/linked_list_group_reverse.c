#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
typedef struct node *node;
struct node
{
    int data;
    struct node *next;
} *first_1 = NULL, *first_2 = NULL;

node insert_at_first(struct node *head, int d)
{
    struct node *p;
    if (head == NULL)
    {
        head = (struct node *)malloc(sizeof(struct node));
        head->data = d;
        head->next = NULL;
    }
    else
    {
        p = (struct node *)malloc(sizeof(struct node));
        p->data = d;
        p->next = head;
        head = p;
    }
    return head;
}
node reverse(struct node *p)
{
    struct node *r, *q;
    r = NULL;
    q = NULL;
    while (p != NULL)
    {
        //Sliding
        r = q;
        q = p;
        p = p->next;
        //Changing
        q->next = r;
    }
    return q;
}
void display(struct node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
void append(struct node *head_1, struct node *head_2)
{
    struct node *prev;
    while (head_1 != NULL)
    {
        prev = head_1;
        head_1 = head_1->next;
    }
    while (head_2 != NULL)
    {
        prev->next = head_2;
        head_2 = head_2->next;
        prev = prev->next;
    }
}
node insert_at_pos(struct node *p, int d, int n)
{
    if (n == 0)
    {
        struct node *t = (struct node *)malloc(sizeof(struct node));
        t->data = d;
        t->next = NULL;
        first_1 = t;
        return first_1;
    }
    struct node *t = (struct node *)malloc(sizeof(struct node));
    t->data = d;
    p = first_1;
    for (int i = 0; i < n - 1; i++)
    {
        p = p->next;
    }
    t->next = p->next;
    p->next = t;
    return first_1;
}

void reverse(struct node *p)
{
    struct node *r, *q;
    r = NULL;
    q = NULL;
    while (p != NULL)
    {
        //Sliding
        r = q;
        q = p;
        p = p->next;
        //Changing
        q->next = r;
    }
    first_1 = q;
}
void algo(struct node *p, int groups)
{
    // Get length of ll
    int ll_length = 0;
    while (p)
    {
        ll_length++;
        p = p->next;
    }
    p = first_1;
    // --- --- ---

    // Create 2D matrix which is ll_length/groups x groups
    int rows = (int)ceil((ll_length / (float)groups));
    int cols = groups;
    int **x;
    x = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
    {
        x[i] = (int *)malloc(cols * sizeof(int));
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            x[i][j] = 0;
        }
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols && p; j++)
        {
            x[i][j] = p->data;
            p = p->next;
        }
    }

    // --- --- ---

    // Reverse each element in the matrix
    int **y;
    y = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
    {
        y[i] = (int *)malloc(cols * sizeof(int));
    }
    int l_save = ll_length;
    int count = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            y[i][cols - 1 - j] = x[i][j];
            count++;
        }
    }
    if (ll_length < count)
    {
        for (int i = 0, j = cols - 1; i < j; i++, j--)
        {
            int temp = y[rows - 1][i];
            y[rows - 1][i] = y[rows - 1][j];
            y[rows - 1][j] = temp;
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (ll_length != 0)
            {
                printf("%d", y[i][j]);
                ll_length--;
            }
        }
    }
}

int main(void)
{
    int size = 0, element = 0, n = 0, k = 0;

    scanf("%d", &size);
    scanf("%d", &n);
    while (size > 0)
    {
        scanf("%d", &element);
        first_1 = insert_at_pos(first_1, element, k++);
        size--;
    }

    algo(first_1, n);
    return 0;
}
