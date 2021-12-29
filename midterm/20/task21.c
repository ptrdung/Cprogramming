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

void enterInfix()
{
    printf("Enter arithmetic expressions :");
    fflush(stdin);
    gets(infix);
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
    char x;
    while (i < len)
    {
        if (isalnum(string[i]))
            printf("%c ", string[i]);
        else if (string[i] == '(')
            push(result, string[i]);
        else if (string[i] == ')')
        {
            while ((x = pop(result)) != '(')
            {
                printf("%c ", x);
            }
        }
        else
        {
            while (priority(peek(result)) >= priority(string[i]))
            {
                printf("%c ", pop(result));
            }
            push(result, string[i]);
        }
        i++;
    }
    while (!isEmpty(result))
        printf("%c ", pop(result));
    printf("\n");
}

int main()
{
    stack s1 = NULL;
    enterInfix();
    toPostfix(infix, &s1);
    return 0;
}