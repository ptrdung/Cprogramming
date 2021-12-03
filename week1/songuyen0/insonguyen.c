#include <stdio.h>

int main() 
{
    FILE * fptr;
    int dem = 0, n;
    fptr = fopen("SoNguyen.dat", "rb");
    fseek(fptr, 49 * sizeof(int), SEEK_SET);
    while(fread(&n, sizeof(int), 1, fptr) == 1)
    {
        ++dem;
        printf("%d. %d\n", dem, n);
    }
    return 0;
}
