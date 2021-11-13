#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>

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
int pop()
{
    node p;
    int x;
    if (top == NULL)
    {
        printf("Not Valid");
        exit(0);
        return 0;
    }
    else
    {
        p = top;
        top = top->next;
        x = p->data;
        free(p);
    }
    return x;
}

int is_operand(char c)
{
    if (c == '+' || c == '-' || c == '/' || c == '*'||c=='%')
        return 0;
    else
        return 1;
}
int evaluate(char *expression)
{
    // Declaring variables
    int n1, n2, ans;

    // Main loop of the algorithm
    for (int i = 0; i < strlen(expression); i++)
    {
        // If the character is operand push it to the stack implemented by a linkedlist
        if (is_operand(expression[i]))
            push(expression[i] - '0');
        // Else pop two values and perform the operation on them and push the result back to the stack
        else
        {
            n2 = pop();
            n1 = pop();
            switch (expression[i])
            {
            case '+':
                ans = n1 + n2;
                push(ans);
                break;
            case '-':
                ans = n1 - n2;
                push(ans);
                break;
            case '/':
                if (n2 == 0)
                {
                    printf("Not Valid");
                    exit(0);
                }
                ans = n1 / n2;
                push(ans);
                break;
            case '*':
                ans = n1 * n2;
                push(ans);
                break;
            case '%':
                if (n2 == 0)
                {
                    printf("Not Valid");
                    exit(0);
                }
                ans = n1 % n2;
                push(ans);
                break;
            }
        }
    }
    // After the loop ends you should have only one value in the stack which is the answer
    return pop();
}
int validate(char *expression)
{
    int count1 = 0;
    int count2 = 0;
    for (int i = 0; i < strlen(expression); i++)
    {

        if (is_operand(expression[i]))
            count1++;
        else
        {
            count2++;
        }
    }
    if(count2==count1-1)
    {
        return 1;
    }
    else
        return 0;
}
int main(void)
{

    // Read the input postfix expression as a string
    char str[100000];
    scanf("%s", str);

    // Get the answer by passing the postfix expression to the evaluate function
    if (validate(str) == 1)
    {
        int ans = evaluate(str);
        // Printing the answer
        printf("%d", ans);
    }
    else
        printf("Not Valid");

    return 0;
}
