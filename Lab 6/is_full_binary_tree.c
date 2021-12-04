#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

struct node_tree
{
    /**
     * Summary: This is the tree node which has an integer data and two pointers
     *          rchild pointer holds a node_tree address and same for lchild
     */
    int node_data;
    struct node_tree *rchild;
    struct node_tree *lchild;
};
struct node_queue
{
    /**
     * Summary: This is the queue node, which has a data of datatype node_tree pointer
     *          and a pointer next  which holds an address of node_queue for the next node in queue
     */
    struct node_tree *data;
    struct node_queue *next;
};

// Start Queue operations
void enqueue(struct node_queue **front, struct node_queue **rear, struct node_tree *x)
{
    /**
     * Queue eqnueue function, takes input front and rear pointers passed by reference
     * The data stored in this queue is of type struct node_tree pointer
     */
    struct node_queue *new = (struct node_queue *)malloc(sizeof(struct node_queue));
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

struct node_tree *dequeue(struct node_queue **front)
{
    /**
     * This function dequeue an element from the front of the queue
     * The argument passed is front pointer of the queue and it is passed by reference
     * The function returns variable of type struct node_tree * to be used later in the tree creation
     */
    struct node_tree *x = NULL;
    struct node_queue *bye;
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

int is_empty_queue(struct node_queue *front)
{
    /**
     * This function checks if the queue in empty or not
     * 
     */
    if (front == NULL)
        return 1;
    return 0;
}
// End Queue operations

// Start Tree creation
struct node_tree *create(int n)
{
    /**
     * This function creates a binary tree
     * the argument passed in integer n which is the number of nodes in the tree
     * The function retuns struct node_tree * type variable which is later we call it root
     */
    struct node_queue *front = NULL;
    struct node_queue *rear = NULL;
    struct node_tree *p;
    struct node_tree *t;
    struct node_tree *root;
    int x;
    //printf("Enter root value: ");
    scanf("%d", &x);
    root = (struct node_tree *)malloc(sizeof(struct node_tree));
    root->node_data = x;
    root->lchild = root->rchild = 0;
    n--;
    // Main idea here is using a queue and eqnueue the pointer of each node to it
    // and then dequeue it and fill it's left child and right child
    // repeating this step and by queue nature we will successfully fill a binary tree
    // from left to right as usual
    enqueue(&front, &rear, root);
    while (n != 0)
    {
        p = dequeue(&front);
        //printf("Enter left child of %d: ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct node_tree *)malloc(sizeof(struct node_tree));
            t->node_data = x;
            t->lchild = t->rchild = 0;
            p->lchild = t;
            enqueue(&front, &rear, t);
        }
        //printf("Enter right child of %d: ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct node_tree *)malloc(sizeof(struct node_tree));
            t->node_data = x;
            t->lchild = t->rchild = 0;
            p->rchild = t;
            enqueue(&front, &rear, t);
        }
        n -= 2;
    }
    return root;
}
// End Tree creation

// Start Tree operations
bool is_full_tree(struct node_tree *root)
{
    /**
     * The main idea of a full binary tree that it is a tree which it's root node = null
     * Or it is a tree which it's left child and right child = null
     * Or it is a tree with left child and right child BUT
     * The left child must be a full binary tree too AND the right child must be full binary tree
     * We do these checks recursevly until we reach the bottom left of a tree and then the right child
     * at the end the return is like (false) and (true) which gives a non-complete binary tree
     * or (true) and (true) which gives a complete binary tree
     */
    if (root == NULL)
        return true;
    if (root->lchild == NULL && root->rchild == NULL)
        return true;
    if ((root->lchild) && (root->rchild))
        return (is_full_tree(root->lchild) && is_full_tree(root->rchild));
    return false;
}
// End Tree operations

int main(void)
{
    int n;
    scanf("%d", &n);
    // If n is zero or n is even this means NO
    if (n == 0 || n % 2 == 0)
    {
        printf("NO");
        return 0;
    }
    struct node_tree *root = create(n);
    if (is_full_tree(root))
        printf("YES");
    else
        printf("NO");
    return 0;
}
