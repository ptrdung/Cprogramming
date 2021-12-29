#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 30 

char stack[MAX];
int num_stack[MAX];
int size = 0, num_size = 0;


char pop(){
   if (size == 0) {
      printf("Ngan xep trong");
      return '\n';
   }
   return stack[--size];
}



void push(char check) {  
   if (size == MAX - 1) {
      printf("Ngan xep da day");
      return;
   }
   stack[size] = check;
   size++;
}



char get_top() { return stack[size - 1]; }


int get_order(char c) {
   if (c == '+' || c == '-')
      return 0;
   else
      return 1;
}



void push_num(int x) {
   if (num_size == MAX - 1) {
      printf("Ngan xep da day ");
      return;
   }
   num_stack[num_size] = x;
   num_size++;
}



int pop_num() {
   if (num_size == 0) {
      printf("Ngan xep trong ");
      return '\n';
   }
   return num_stack[--num_size];
}


int main() {
   printf("Nhap bieu thuc can tinh : ");
   char c = getchar();
   printf("\nBieu thuc da chuyen doi hau to : ");
   int x;
   int ketqua = 0;
   do {
      if ('0' <= c && c <= '9') {
         push_num((int)c - '0');
         putchar(c);
         putchar(' ');
      } else {
         int order = get_order(c);
         while (size > 0 && get_order(get_top()) >= order) {
            char check= pop();
            int tmp = pop_num();
            if (check == '+')
               tmp += pop_num();
            if (check == '-')
               tmp = pop_num() - tmp;
            if (check== '*')
               tmp *= pop_num();
            if (check== '/')
               tmp = pop_num() / tmp;
            push_num(tmp);
            putchar(check);
            putchar(' ');
         }
         push(c);
      }
      c = getchar();
   } while (c != '\n');
   while (size > 0) 
   {
      char check = pop();
      int tmp = pop_num();
      
      if (check== '+') tmp += pop_num();
      
      if (check == '-') tmp = pop_num() - tmp;
      
      if (check == '*') tmp *= pop_num();
      
      if (check == '/') tmp = pop_num() / tmp ;

      push_num(tmp);
      putchar(check);
      putchar(' ');
   }
   ketqua = pop_num();
   printf("\nKet qua  = %d", ketqua);
}
