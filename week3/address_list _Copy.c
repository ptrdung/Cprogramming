#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct address_t {
    char name[50];
    char tel[13];
    char email[30];
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
    fgets(tmp.name,50,stdin);
    tmp.name[strlen(tmp.name)-1] = '\0';
    fgets(tmp.tel, 13, stdin);
    tmp.tel[strlen(tmp.tel)-1] = '\0';
    fgets(tmp.email, 30, stdin);
    tmp.email[strlen(tmp.email)-1] = '\0';
    return tmp;
}

void displayNode(node_addr* p) {
    if (p == NULL) {
        printf("Loi con tro NULL\n");
        return;
    }
    address tmp = p->addr;
    printf("%-50s\t%-13s\t-30s %p\n", tmp.name, tmp.tel, tmp.email, p->next);
}

void insertAtHead(address addr) {
    node_addr* new = makeNewNode(addr);
    new->next = root;
    root = new;
    cur = root;
}

void insertAfterCurrent(address addr) {
    new = makeNewNode(addr);
    if(root == NULL) {
    //if there is no element
    root = new;
    cur = root
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
            while(i -> next != cur && cur != NULL)
                i = i -> next;
            i->next = new;
            cur = new;
        }
    }
}
//slide 21 cua thay dung

int main() {
    address tmp = readNote();
    root = makeNewNode(tmp);
    displayNode(root);
    return 0;
}
