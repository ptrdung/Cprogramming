#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum{SUCCESS, FAIL};

int main()
{
    FILE * fp;
    int *p;
    int i, n, value, sum;
    int reval = SUCCESS;
    printf("Enter a list of number with the first is the size of the list: \n");
    scanf("%d", &n);
    p = (int *)malloc(n * sizeof(int));
    i = 0; 
    sum = 0;
    while(i < n)
    {
        scanf("%d", &value);
        p[i++] = value;
        sum += value;
    }
    if((fp = fopen("out.txt", "w")) == NULL)
    {
        printf("Can not open %s.\n", "out.txt");
        reval = FAIL;
    }
    for(i = n-1; i >= 0; i--)
    {
        fprintf(fp, "%d ", p[i]);
    }
    fprintf(fp, "%d", sum);
    fclose(fp);
    free(p);
    return reval;
}
