#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>

#define EMPTY -1
#define STACK_EMPTY INT_MIN
typedef int elType;

typedef struct node
{
    elType value;
    struct node *next;
} node;

typedef node *stack;

bool isEmpty(stack *mystack)
{
    if (*mystack == NULL)
    {
        return true;
    }

    return false;
}

bool push(stack *mystack, elType value)
{
    node *newnode = malloc(sizeof(node));

    if (newnode == NULL)
    {
        printf("Failed memory !");
        return false;
    }

    newnode->value = value;
    newnode->next = *mystack;
    *mystack = newnode;
    return true;
}

elType pop(stack *mystack)
{
    if (isEmpty(mystack))
        return STACK_EMPTY;

    int result = (*mystack)->value;
    node *tmp = *mystack;
    *mystack = (*mystack)->next;
    free(tmp);
    return result;
}

elType peek(stack *mystack)
{
    if (isEmpty(mystack))
        return STACK_EMPTY;
    int result = (*mystack)->value;
    return result;
}

char infix[255];
char postfix[255] = "";

void enterInfix()
{
    printf("Enter arithmetic expressions :");
    fflush(stdin);
    gets(infix);
    printf("Read successfully !\n");
}

int priority(char x)
{
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    return 0;
}

void toPostfix(char string[], stack *result)
{
    int len = strlen(string);
    int i = 0;
    int i2 = 0;
    char x;
    while (i < len)
    {
        if (isalnum(string[i]))
        {
            printf("%c ", string[i]);
            strncat(postfix, &string[i], 1);
        }
        else if (string[i] == '(')
            push(result, string[i]);
        else if (string[i] == ')')
        {
            while ((x = pop(result)) != '(')
            {
                printf("%c ", x);
                strncat(postfix, &x, 1);
            }
        }
        else
        {
            while (priority(peek(result)) >= priority(string[i]))
            {
                x = pop(result);
                printf("%c ", x);
                strncat(postfix, &x, 1);
            }
            push(result, string[i]);
        }
        i++;
    }
    while (!isEmpty(result))
    {
        x = pop(result);
        printf("%c ", x);
        strncat(postfix, &x, 1);
    }
    printf("\n");
}

void calPostfix(stack *stack2)
{
    int i, len, b, c;
    len = strlen(postfix);
    for (int i = 0; i < len; i++)
    {
        if ((postfix[i] - '0') >= 0 && (postfix[i] - '0') <= 9)
            push(stack2, (postfix[i] - '0'));
        else if (postfix[i] == '+' || postfix[i] == '*' || postfix[i] == '-' || postfix[i] == '/')
        {
            c = pop(stack2);
            b = pop(stack2);
            if (postfix[i] == '+')
                push(stack2, b + c);
            else if (postfix[i] == '*')
                push(stack2, b * c);
            else if (postfix[i] == '/')
                push(stack2, b / c);
            else if (postfix[i] == '-')
                push(stack2, b - c);
        }
    }
    printf("The value of expression is: ");
    while (!isEmpty(stack2))
    {
        printf("%d", pop(stack2));
    }
    printf("\n");
}

int main()
{
    stack s1 = NULL;
    stack s2 = NULL;
    enterInfix();
    toPostfix(infix, &s1);
    calPostfix(&s2);
    return 0;
}