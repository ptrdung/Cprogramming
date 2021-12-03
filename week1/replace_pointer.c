#include <stdio.h>
#include <string.h>

void replace(char* string, char p, char q) {
    for(int i = 0; i < strlen(string); i++)
        if(*(string+i) == p)
            *(string+i) = q;
}

int main() {
    char string[100];
    char p, q;
    printf("Nhap xau: ");
    fgets(string, 100, stdin);
    printf("Nhap ky tu can duoc thay the: ");
    scanf("%c", &p);
    printf("Nhap ky tu thay the vao: ");
    scanf(" %c", &q);
    replace(string, p, q);
    printf("%s", string);
    return 0;
}
