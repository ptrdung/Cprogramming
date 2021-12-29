#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Address
{
    char name[nameLength];
    char phone[phoneLength];
    char email[emailLength];
    struct Address *next;
} ad;

void EnQueue(char *name1, char *phone1, char *email1)
{
    ad *neww;
    neww = (ad *)malloc(sizeof(ad));
    strcpy(neww->name, name1);
    strcpy(neww->phone, phone1);
    strcpy(neww->email, email1);
    neww->next = NULL;
    if (front == NULL && rear == NULL)
    {
        front = neww;
        rear = neww;
    }
    else
    {
        rear->next = neww;
        rear = neww;
    }
}

ad DeQueue(void)
{
    ad tmp = *front;
    if (front == rear)
    {
        front = NULL;
        rear = NULL;
        return tmp;
    }
    else
    {
        front = front->next;
        return tmp;
    }
}

void In(void)
{
    for (ad *k = front; k != rear; k = k->next)

        printf("%s\t%s\t%s\n", k->name, k->email, k->phone);
}
