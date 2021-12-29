#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct address_t {
    char name[31];
    char tel[13];
    char email[36];
} address;

address addr[100];

void swap(address *a, address *b) {
   address t = *a;
   *a = *b;
   *b = t;
}
int partition(address array[], int low, int high) {
   char pivot[31];
   strcpy(pivot, array[high].name);
   int i = (low - 1);
   for (int j = low; j < high; j++) {
      if (strcmp(array[j].name, pivot) < 0) {
         i++;
         swap(&array[i], &array[j]);
      }
   }

   swap(&array[i + 1], &array[high]);
   return (i + 1);
}

void quickSort(address array[], int low, int high) {
   if (low < high) {
      int pi = partition(array, low, high);
      quickSort(array, low, pi - 1);
      quickSort(array, pi + 1, high);
   }
}




int main() {
    FILE *fptr, *fptr1;
    int n, k = -1;
    if((fptr = fopen("phone.dat","rb")) == NULL)
        printf("Can not open phone.dat");
    else {
        while(fread(&addr[++k], sizeof(address), 1, fptr) == 1)
        {
                    
        }
    }
    n = k;
    fclose(fptr);

    printf("Du lieu ban dau: \n");
    for(int j = 0; j < n; j++)
        printf("%-31s\t%-13s\t%-36s\n", addr[j].name, addr[j].tel, addr[j].email);
    
    quickSort(addr,0, 9);
    
    printf("Du lieu sau khi su dung quicksort\n");
    fptr1 = fopen("quicksort.dat", "rb");
    for(int j = 0; j < n; j++) {
        printf("%-31s\t%-13s\t%-36s\n", addr[j].name, addr[j].tel, addr[j].email);
        fwrite(&addr[j], sizeof(address), 1, fptr1);
        
    }
    fclose(fptr1);
}
