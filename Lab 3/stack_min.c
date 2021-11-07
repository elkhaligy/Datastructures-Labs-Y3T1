#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node *node;
struct node
{
    int data;
    struct node *next;
} * top;
void push(int x)
{
    node new_node = (node)malloc(sizeof(struct node));
    new_node->data = x;
    new_node->next = top;
    top = new_node;
}
void pop()
{
    node p;
    //int x = -1;
    if (top == NULL)
        // printf("Empty\n");
        return;
    else
    {
        p = top;
        top = top->next;
        //x = p->data;
        free(p);
    }
    //return x;
}
void display()
{
    node p = top;
    while (p != NULL)
    {
        printf(" %d \n", p->data);
        printf("---\n");
        p = p->next;
    }
}
int peek(int pos)
{
    node p = top;
    for (int i = 0; i < pos - 1 && p != NULL; i++)
        p = p->next;
    if (p != NULL)
        return p->data;
    else
        return -1;
}
int is_empty()
{
    if (top == NULL)
        return 1;
    return 0;
}
int stack_top()
{
    if (top != NULL)
        return top->data;
    return -1;
}
int stack_min()
{

    node p = top;
    int x = p->data;
    while (p != NULL)
    {
        if (p->data < x)
            x = p->data;
        p = p->next;
    }
    return x;
}
int main(void)
{
    int q = 0, o = 0, d = 0, x = 0;
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        scanf("%d", &o);
        switch (o)
        {
        case 1:
            scanf("%d", &d);
            push(d);
            break;
        case 2:
            pop();
            break;
        case 3:
            if (!is_empty())
                printf("%d\n", stack_min());
            else
                printf("Empty\n");
            break;
        }
        //display();
    }
    return 0;
}
