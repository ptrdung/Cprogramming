//read data from file phone.dat
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct address_t {
    char name[31];
    char tel[13];
    char email[36];
} address;

struct list_el {
    address addr;
    struct list_el *next;
};
typedef struct list_el node_addr;

node_addr *root, *cur;

// in case you use prev 
node_addr *prev;

node_addr* makeNewNode(address addr) {
    node_addr* new = (node_addr*)malloc(sizeof(node_addr));
    new->addr = addr;
    new->next = NULL;
    return new;
}

address readNode() {
    address tmp;
    fgets(tmp.name,31,stdin);
    tmp.name[strlen(tmp.name)-1] = '\0';
    fgets(tmp.tel, 13, stdin);
    tmp.tel[strlen(tmp.tel)-1] = '\0';
    fgets(tmp.email, 36, stdin);
    tmp.email[strlen(tmp.email)-1] = '\0';
    return tmp;
}

int displayNode(node_addr* p) {
    if (p == NULL) {
        printf("Loi con tro NULL\n");
        return 1;
    }
    address tmp = p->addr;
    printf("%-31s\t%-13s\t%-36s %p\n", tmp.name, tmp.tel, tmp.email, p->next);
    return 0;
}

void insertAtHead(address addr) {
    node_addr* new = makeNewNode(addr);
    new->next = root;
    root = new;
    cur = root;
}

void insertAfterCurrent(address addr) {
    node_addr *new;
    new = makeNewNode(addr);
    if(root == NULL) {
    //if there is no element
    root = new;
    cur = root;
    }
    else {
        new->next = cur->next;
        cur->next = new;
        cur = cur->next;
    }
}

void insertBeforeCurrent(address e) {
    node_addr* i;
    node_addr* new = makeNewNode(e);
    if(root == NULL) {
        root = new;
        cur = root;
        //prev = NULL;
    }
    else {
        new->next=cur;
        //if cur pointed to first element
        if(cur == root) {
            root = new;
        }
        else {
            i = root;
            while(i-> next != cur && cur != NULL)
                i = i-> next;
            prev = i;
            prev->next = new;
            cur = new;
        }
    }
}
//slide 21 cua thay dung

void traversingList() 
{
    node_addr * p;
    for(p = root; p != NULL; p = p -> next)
        displayNode(p);
}

void deleteFirstElement()
{
    node_addr *del = root;
    root = del -> next;
    free(del);
    cur = root;
}

void deleteCurrentElement()
{
    node_addr *i;
    if(cur == NULL) return;
    if(cur == root) deleteFirstElement();
    else {
        i = root;
        while(i -> next != cur && cur != NULL)
            i = i -> next;
        prev = i;
        prev -> next = cur -> next;
        free(cur);
        cur = prev -> next;
    }
}

void freeList()
{
    node_addr *to_free = root;
    while(to_free != NULL)
    {
        root = root -> next;
        free(to_free);
        to_free = root;
    }
}

node_addr *list_reverse(node_addr **roott)
{
    node_addr *curr, *prevv;
    curr = NULL;
    prevv = NULL;
    while(*roott != NULL)
    {
        curr = *roott;
        *roott = (*roott)->next;
        curr -> next = prevv;
        prevv = curr;
    }
    return prevv;
}

int main() {
    int n = 0;
    FILE *fptr;
    address add;
    root = NULL;
    cur = NULL;
    if((fptr = fopen("phone.dat","rb")) == NULL)
        printf("Can not open phone.dat");
    else {
        while(fread(&add, sizeof(address), 1, fptr) == 1)
        {
            insertAfterCurrent(add);
        }
    }
    traversingList();
    fclose(fptr);
    return 0;
}
