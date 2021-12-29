//read data from file phone.dat
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct address_t {
    char name[31];
    char tel[13];
    char email[36];
} address;

address addr[100];

int BinarySearch(address addr[], int n, char X[])
{
    int Low, Mid, High;
    Low = 0;
    High = n - 1;
    while (Low <= High)
    {
        Mid = (Low + High) / 2;
        if (strcmp(addr[Mid].name, X) < 0)
            Low = Mid + 1;
        else if (strcmp(addr[Mid].name, X) > 0)
            High = Mid - 1;
        else
            return Mid; /* Found */
    }
    return -1;          /* Not Found */
}

int main() {
    int n = 0; //số người 
    FILE *fptr, *fptr1;
    int k;
    int i = -1;
    char X[10];
    address add;
    if((fptr = fopen("phone.dat","rb")) == NULL)
        printf("Can not open phone.dat");
    else {
        while(fread(&addr[++i], sizeof(address), 1, fptr) == 1)
        {
                    
        }
    }
    n = i;
    printf("Du lieu ban dau: \n");
    for(int j = 0; j < n; j++)
        printf("%-31s\t%-13s\t%-36s\n", addr[j].name, addr[j].tel, addr[j].email);
    
    printf("Nhap ten can tim kiem: \n");
    scanf("%s", X);
    if((k = BinarySearch(addr, n, X)) == -1)
        printf("Khong tim thay\n");
    else {
        printf("%-31s\t%-13s\t%-36s\n", addr[k].name, addr[k].tel, addr[k].email);
        if((fptr1 = fopen("result11.txt","w")) == NULL)
            printf("Can not open result11.txt");
        else {
            fprintf(fptr1,"%-31s\t%-13s\t%-36s\n", addr[k].name, addr[k].tel, addr[k].email);
            fclose(fptr1);
        }
    }
    fclose(fptr);
    return 0;
}
