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
        printf("Empty");
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
    int count = 0;
    while (p != NULL)
    {
        count++;
        p = p->next; //
    }
    // printf("%d", count);
    p = front;
    if(p==NULL)
    {
        printf("Empty\n");
        return;
    }
    while (p != NULL)
    {
        if (count != 1)
        {
            printf("%d,", p->data);
            count--;
        }
        else
        {
            printf("%d", p->data);
        }
        p = p->next;
    }
    //p = p->next;
    //printf("%d", p->data);
    printf("\n");
}
int main(void)
{
    int q = 0, o = 0, d = 0;
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        scanf("%d", &o);
        switch (o)
        {
        case 1:
            scanf("%d", &d);
            enqueue(d);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        }
    }

    return 0;
}
