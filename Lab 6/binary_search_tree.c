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


// Start Tree methods
int *pre_order(struct node_tree *root, int *p)
{
    static int i = 0;
    if (root)
    {
        //printf("%d,", root->node_data);
        p[i++] = root->node_data;
        pre_order(root->lchild, p);
        pre_order(root->rchild, p);
    }
    return p;
}
int count(struct node_tree *root)
{
    if (root)
        return count(root->lchild) + count(root->rchild) + 1;
    return 0;
}
// End tree methods

struct node_tree *create_balanced(int n, int *p, int start, int end)
{
    if (start > end)
        return NULL;
    int mid = (start + end) / 2;
    struct node_tree *root;
    root = (struct node_tree *)malloc(sizeof(struct node_tree));
    root->node_data = p[mid];
    root->lchild = create_balanced(n, p, start, mid - 1);
    root->rchild = create_balanced(n, p, mid + 1, end);
    return root;
}
int main(void)
{
    int n;
    int *p;
    int *q;
    scanf("%d", &n);
    p = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &p[i]);
    struct node_tree *root = create_balanced(n, p, 0, n - 1);
    q = (int *)malloc(count(root) * sizeof(int));
    q = pre_order(root, q);
    for (int i = 0; i < count(root); i++)
    {
        if(i!=count(root)-1)
            printf("%d,", q[i]);
        else
            printf("%d",q[i]);
    }
    return 0;
}
