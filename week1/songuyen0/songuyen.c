#include <stdio.h>

int main() {
    int n;
    FILE * fptr;
    fptr = fopen("SoNguyen.dat", "wb");
    for(int i = 0; i < 100; i++) 
    {
        n = 2 * i + 1;
        fwrite(&n, sizeof(int), 1, fptr);
        printf("%d. %d\n", i + 1, n);
    }
    fclose(fptr);
    return 0;
}
