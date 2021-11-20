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
    int n, d, t;
    int *p;
    int *q;
    int cnt1 = 0, cnt2 = 0;
    scanf("%d", &n);
    p = (int *)malloc(n * 2 * sizeof(int));
    q = (int *)malloc(n * 2 * sizeof(int));
    for (int i = 0; i < n * 2; i += 2)
    {
        scanf("%d%d", &d, &t);
        p[i] = t;
        p[i + 1] = d;
        // enqueue(t);
        //enqueue(d);
    }
    for (int i = 0; i < n * 2; i += 2)
    {
        q[i] = 0;
    }
    int min = 2000;
    int min_index;
    int i;
    for(int k=0;k<n;k++)
    {
        for (i = 0; i < n * 2; i += 2)
        {
            if (p[i] < min && q[i]!=1)
            {
                min = p[i];
                min_index = i;
            }
        }
        enqueue(p[min_index]);
        enqueue(p[min_index+1]);
        q[min_index]=1;
        min=2000;
    }
    
    for (int i = 0; i < n * 2; i++)
        printf("%d ", p[i]);
    //display();
    //printf("\n");
    while (front != NULL)
    {
        if (cnt1 == 0)
        {
            dequeue();
            cnt1 += dequeue();
            cnt2 += 1;
            continue;
        }
        int x = dequeue();
        int y = dequeue();
        if (cnt1 + y <= x)
        {
            cnt1 += y;
            cnt2 += 1;
        }
        //display();
        //printf("\n");
    }
    printf("%d", cnt2);
    return 0;
}
