#include <stdio.h>

int main() {
    char str[100];
    fgets(str,3,stdin);
    printf("%s", str);
    return 0;
}
