#include <stdio.h>
#include <string.h>

int main() {
    char dung[3];
    int so;
    fgets(dung,3,stdin);
    scanf("%d", &so);
    printf("%s\n%d", dung, so);
    return 0;
}
