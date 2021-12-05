#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void double_space(FILE *ifp, FILE *ofp);

int main(int argc, char *argv[])
{
    FILE *ifp, *ofp;
    if(argc != 3)
    {
        printf("Wrong number of arguments");
        exit(1);
    }
    ifp = fopen(argv[1], "r");
    ofp = fopen(argv[2], "w");
    double_space(ifp, ofp);
    fclose(ifp);
    fclose(ofp);
    return 0;
}

void double_space(FILE *ifp, FILE *ofp)
{
    int c;
    while((c = getc(ifp)) != EOF) 
    {
        putc(c, ofp);
        if(c == '\n')
            putc('\n', ofp);
    }
}
