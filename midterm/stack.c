#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//Để ý ba cái chú ý 
struct StackNode {
    float item;     //chú ý!!!!!!
    StackNode *next;
};
struct Stack {
    StackNode *top;
};

//Khởi tạo ngăn xếp
Stack *StackConstruct() {
    Stack *s;
    s = (Stack *)malloc(sizeof(Stack));
    if(s == NULL) {
        return NULL;
    }
    s->top = NULL;
    return s;
}

//Kiểm tra Stack rỗng
int StackEmpty(const Stack *s) {
    return (s->top == NULL);
}

//Huỷ ngăn xếp
void StackDestroy(Stack *s) {
    while(!StackEmpty(s)) {
        StackPop(s);
    }
    free(s);
}

//Thông báo Stack tràn
int StackFull() {
    printf("\nNo Memory! Stack is Full");
    return 1;
}

//Đưa ra các phần tử của ngăn xếp
void disp(Stack *s) {
    StackNode *node;
    int ct = 0;
    float m;
    printf("\nDanh sach phan tu cua Stack");
    if(StackEmpty(s)) {
        printf("\nEmpty Stack");
    }
    else {
        node = s->top;
        do {
            m = node->item;
            printf("%8.3f\n", m);
            node = node->next;
        } while((!node == NULL));
        printf("\n");
    }
}

//Bổ sung (Nạp vào) - Push
int StackPush(Stack *s, float item)
{
    StackNode *node;
    node = (StackNode *)malloc(sizeof(StackNode));
    if(node == NULL) {
        StackFull();
        return 1;
    }
    node->item = item;
    node->next = s->top;
    s->top = node;
    return 0;
}

//Cài đặt Pop trên C
float StackPop(Stack *s) {      //chú ý !!!!!!!!!!!!
    float item;                 //chú ý !!!!!!!!!!!!
    StackNode *node;
    if(StackEmpty(s)) {
        return NULL;
    }
    node = s->top;
    item = node->item;
    s->top = node->next;
    free(node);
    return item;
}
