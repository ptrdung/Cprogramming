#include <stdio.h>
#include <string.h>

int main() {
    char ten[50];
    gets(ten);
    printf("%d", strlen(ten));
    return 0;
}
