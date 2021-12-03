#include <stdio.h>

int main() {
    FILE* file = fopen("songuyen.dat", "wb");
    int i, n;
    for(i = 0; i < 100; i++) {
        n = 2 * i + 1;
        fwrite(&n, sizeof(int), 1, file);
    }
    fclose(file);
    int m = 0; 
    file = fopen("songuyen.dat", "rb");
    fseek(file, 49 * sizeof(int), SEEK_SET);
    while(!feof(file)) {
        fread(&m, sizeof(int), 1 ,file);
        printf("\t%d", m);
    }
    return 0;
}
