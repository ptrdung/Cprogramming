#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, n, *p;
    printf("How many number do you want to enter?\n");
    scanf("%d", &n);

    p = (int*)malloc(n*sizeof(int));
    if(p == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    printf("Please enter the numbers now:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &p[i]);
    printf("The numbers in reverse order are:\n");
    for(i = n-1; i >= 0; i--)
        printf("%d\n", p[i]);
    free(p);
    return 0;
}
