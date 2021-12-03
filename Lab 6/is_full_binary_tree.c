#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

typedef struct node *Node;
struct node
{
    struct node *data;
    struct node *next;

    int node_data;
    struct node *rchild;
    struct node *lchild;
};

void enqueue(struct node **front, struct node **rear, struct node *x)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    if (new == NULL)
        printf("Queue is full");
    else
    {
        new->data = x;
        new->next = NULL;
        if (*front == NULL)
        {
            //It's first node
            *front = *rear = new;
        }
        else
        {
            //Insert a new node normally
            (*rear)->next = new;
            *rear = new;
        }
    }
}
struct node *dequeue(struct node **front)
{
    struct node *x = NULL;
    struct node *bye;
    if (front == NULL)
    {
        return x;
    }
    else
    {
        x = (*front)->data;
        bye = *front;
        *front = (*front)->next;
        free(bye);
    }
    return x;
}
int is_empty_queue(struct node *front)
{
    if (front == NULL)
        return 1;
    return 0;
}

struct node *create(int n)
{
    n--;
    struct node *front = NULL;
    struct node *rear = NULL;

    struct node *p;
    struct node *t;
    struct node *root;
    int x;
    //printf("Enter root value: ");
    scanf("%d", &x);
    root = (struct node *)malloc(sizeof(struct node));
    root->node_data = x;
    root->lchild = root->rchild = 0;
    enqueue(&front, &rear, root);
    while (n != 0)
    {
        p = dequeue(&front);
        //printf("Enter left child of %d: ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct node *)malloc(sizeof(struct node));
            t->node_data = x;
            t->lchild = t->rchild = 0;
            p->lchild = t;
            enqueue(&front, &rear, t);
        }
        //printf("Enter right child of %d: ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct node *)malloc(sizeof(struct node));
            t->node_data = x;
            t->lchild = t->rchild = 0;
            p->rchild = t;
            enqueue(&front, &rear, t);
        }
        n -= 2;
    }
    return root;
}
void pre_order(struct node *root)
{
    if (root)
    {
        printf("%d ", root->node_data);
        pre_order(root->lchild);
        pre_order(root->rchild);
    }
}
void in_order(struct node *root)
{
    if (root)
    {
        in_order(root->lchild);
        printf("%d ", root->node_data);
        in_order(root->rchild);
    }
}
void post_order(struct node *root)
{
    if (root)
    {
        post_order(root->lchild);
        post_order(root->rchild);
        printf("%d ", root->node_data);
    }
}
int height(struct node *root)
{
    int x = 0, y = 0;
    if (root == 0)
        return 0;
    x = height(root->lchild);
    y = height(root->rchild);
    if (x > y)
        return x + 1;
    else
        return y + 1;
}
int count(struct node *root)
{
    if (root)
        return count(root->lchild) + count(root->rchild) + 1;
    return 0;
}
bool is_full_tree(struct node *root)
{
    if (root == NULL)
        return true;
    if (root->lchild == NULL && root->rchild == NULL)
        return true;
    if ((root->lchild) && (root->rchild))
        return (is_full_tree(root->lchild) && is_full_tree(root->rchild));

    return false;
}
int main(void)
{
    int n;
    scanf("%d", &n);
    if (n == 0 || (n % 2 != 1 && n != 1))
    {
        printf("NO");
        return 0;
    }
    struct node *root = create(n);
    // int tree_height = height(root);
    // tree_height--;
    //printf("%d \n",count(root));
    //printf("%f \n", pow((double)2, (double)(tree_height + 1)) - 1);
    // if ((pow((double)2, (double)(tree_height + 1)) - 1) == count(root))
    //     printf("YES");
    // else
    //     printf("NO");
    if (is_full_tree(root))
        printf("YES");
    else
        printf("NO");
    return 0;
}
