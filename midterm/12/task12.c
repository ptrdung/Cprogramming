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

void traversingList() 
{
    node_addr * p;
    for(p = root; p != NULL; p = p -> next)
        displayNode(p);
}



node_addr* sequentialsearch(node_addr *root, char X[]) {
    node_addr *i;
    int k = 0;
    for(i = root; i != NULL; i = i -> next) {
        if(strcmp(i->addr.name, X) == 0) {
            k = 1;
            return(i); 
        }
    }
    if(k =0) {
        return NULL;
    }
}
    
int main() {
    int n = 0;
    char X[20];
    FILE *fptr, *fptr1;
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
    printf("Du lieu ban dau\n");
    traversingList();
    printf("Nhap ten can tim kiem:\n");
    scanf("%s", X);
    node_addr *m = sequentialsearch(root, X);
    if(m == NULL) printf("Khong tim thay");
    else {
        displayNode(m);
        address tmp = m->addr;
        fptr1 = fopen("result12.txt", "w");
        fprintf(fptr1,"%-31s\t%-13s\t%-36s \n", tmp.name, tmp.tel, tmp.email);
        fclose(fptr1);
    }
    fclose(fptr);
    return 0;
}
