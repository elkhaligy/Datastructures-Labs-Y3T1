#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *front = NULL, *rear = NULL;

void enqueue(int x)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    if (new == NULL)
        printf("Queue is full");
    else
    {
        new->data = x;
        new->next = NULL;
        if (front == NULL)
        {
            //It's first node
            front = rear = new;
        }
        else
        {
            //Insert a new node normally
            rear->next = new;
            rear = new;
        }
    }
}
int dequeue()
{
    int x = -1;
    struct node *bye;
    if (front == NULL)
    {
    }
    else
    {
        x = front->data;
        bye = front;
        front = front->next;
        free(bye);
    }
    return x;
}
void display()
{
    struct node *p = front;
    while (p != NULL)
    {

        printf("%d,", p->data);
        p = p->next;
    }
}
int main(void)
{

    return 0;
}
