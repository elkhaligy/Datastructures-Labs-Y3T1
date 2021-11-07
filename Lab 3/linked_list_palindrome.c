#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct node
{
    int data;
    struct node *next;
} *first_1 = NULL, *first_2 = NULL;
void display(struct node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
struct node *insert(struct node *head, int d)
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
void palindrome_1(struct node *p)
{
    int count = 0;
    int i = 0;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    int *arr1 = (int *)malloc(count * sizeof(int));
    int *arr2 = (int *)malloc(count * sizeof(int));
    p = first_1;
    while (p != NULL)
    {
        arr1[i++] = p->data;
        p = p->next;
    }
    reverse(first_1);
    p = first_1;
    i = 0;
    while (p != NULL)
    {
        arr2[i++] = p->data;
        p = p->next;
    }
    for (int i = 0; i < count; i++)
    {
        if (arr1[i] != arr2[i])
        {
            printf("NO");
            return;
        }
    }
    printf("YES");
    return;
}
void palindrome_2(struct node *p, struct node *d)
{
    int length = 0;
    while (p != NULL)
    {
        length++;
        p = p->next;
    }
    p = first_1;
    for (int i = 0; i < length; i++)
    {
        if (p->data != d->data)
        {
            printf("NO");
            return;
        }
        p = p->next;
        d = d->next;
    }
    printf("YES");
    return;
}
int main(void)
{
    int num = 0, count = 0;

    scanf("%d", &num);
    //First linkedlist
    while (num != 0)
    {
        int temp = 0;
        temp = num % 10;
        first_1 = insert(first_1, temp);
        num /= 10;
        count++;
    }
    //Second linkedlist
    struct node *p = first_1;
    while (count != 0)
    {
        first_2 = insert(first_2, p->data);
        p = p->next;
        count--;
    }
    display(first_1);
    //display(first_2);
    //palindrome_1(first_1);
    palindrome_2(first_1, first_2);
    return 0;
}
