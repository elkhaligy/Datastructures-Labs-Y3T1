#include <stdio.h>
#include <stdlib.h>
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
        printf("%X", p->data);
        p = p->next;
    }
}
void to_base_n(int n, int b)
{
    if (n == 0)
        return;
    int q = n % b;
    push(q);
    to_base_n(n / b, b);
    // while (n > 0)
    // {
    //     push(n % b);
    //     n = n / b;
    // }
}
void above_9()
{
    node p = top;
    while (p != NULL)
    {
        if (p->data > 9)
        {
            switch (p->data)
            {
            }
        }
    }
}
int main(void)
{
    int n, b;
    scanf("%d%d", &n, &b);
    to_base_n(n, b);
    display();
    return 0;
}
