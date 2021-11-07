#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct node *node;
struct node
{
    int data;
    struct node *next;
};
// --- --- ---
// Insertions and creations (Clean)
node insert_at_pos(struct node *head, int d, int n)
{
    // Function takes a head, data, and position
    // Returns a head also but with data inserted

    // Linking node pointer
    struct node *node;
    // Indexing node pointer
    struct node *p;
    node = (struct node *)malloc(sizeof(struct node));
    if (n == 0) // Insert at first
    {
        node->data = d;
        node->next = head;
        head = node;
    }
    else
    {
        p = head;
        // This will make p point on the desired position
        for (int i = 0; i < n - 1 && p; i++)
            p = p->next;
        node->data = d;
        node->next = p->next;
        p->next = node;
    }
    return head;
}
node insert_at_first(struct node *head, int d)
{
    struct node *node;
    node = (struct node *)malloc(sizeof(struct node));
    if (head == NULL)
    {
        node->data = d;
        node->next = NULL;
    }
    else
    {
        node->data = d;
        node->next = head;
    }
    head = node;
    return head;
}
node insert_from_array(node head, int A[], int n)
{
    // Linking node pointer
    struct node *node;
    // Indexing node pointer
    struct node *p;
    if (head == NULL)
    {
        node = (struct node *)malloc(sizeof(struct node));
        node->data = A[0];
        node->next = NULL;
        head = node;
    }
    for (int i = 1; i < n; i++)
    {
        node = (struct node *)malloc(sizeof(struct node));
        node->data = A[i];
        node->next = head;
        head = node;
    }
    return head;
}
// --- --- ---

node concat(node head_1, node head_2)
{
    // Indexing node pointer
    node p;
    p=head_1;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = head_2;
    head_2 = NULL;
    return head_1;
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
        printf("%d", p->data);
        p = p->next;
    }
}
void display_rec(struct node *p)
{
    if (p != NULL)
    {
        //display_rec(p->next);// Here it will print in reverse order
        printf("%d ", p->data);
        display_rec(p->next); // Here it will print in normal order
    }
}
int count(struct node *p)
{
    int count = 0;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}
int count_rec(struct node *p)
{
    if (p == NULL)
    {
        return 0;
    }
    else
        return count_rec(p->next) + 1;
}
int count_rec2(struct node *p)
{
    int x = 0;
    if (p)
    {
        x = count_rec2(p->next);
        return x + 1;
    }
    else
        return x;
}
int sum(struct node *p)
{
    int sum = 0;
    while (p != NULL)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}
int sum_rec(struct node *p)
{
    if (p == NULL)
        return 0;
    else
        return p->data + sum_rec(p->next);
}
int max(struct node *p)
{
    int m = INT_MIN;
    while (p != NULL)
    {
        if (p->data > m)
            m = p->data;
        p = p->next;
    }
    return m;
}
int max_rec(struct node *p)
{
    int x = 0;
    if (p == NULL)
        return INT_MIN;
    else
    {
        x = max_rec(p->next);
        if (x > p->data)
            return x;
        else
            return p->data;
    }
}

int main(void)
{
    struct node *head_1 = NULL;
    struct node *head_2 = NULL;
    head_1 = insert_at_first(head_1, 1);
    head_1 = insert_at_first(head_1, 2);
    head_2 = insert_at_first(head_2, 3);
    head_2 = insert_at_first(head_2, 4);
    //head_1 -> 2 1
    //head_2 -> 4 3
    head_1 = concat(head_1, head_2);
    display(head_1);

    return 0;
}
