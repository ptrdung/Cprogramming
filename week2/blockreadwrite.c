#include <stdio.h>

enum {SUCCESS, FAIL, MAX_LEN = 80};

void BlockReadWrite(FILE * fin, FILE * fout);

int main() 
{
    FILE * fptr1, * fptr2;
    char filename1[] = "lab1a.txt";
    char filename2[] = "lab1.txt";
    int reval = SUCCESS;

    if((fptr1 = fopen(filename1, "w")) == NULL)
    {
        printf("Can not open %s.\n", filename1);
        reval = FAIL;
    }
    else if ((fptr2 = fopen(filename2, "r")) == NULL)
    {
        printf("Can not open %s.\n", filename2);
        reval = FAIL;
    }
    else {
        BlockReadWrite(fptr2, fptr1);
        fclose(fptr1);
        fclose(fptr2);
    }
    return reval;
}

void BlockReadWrite(FILE * fin, FILE * fout) 
{
    int num;
    char buff[MAX_LEN + 1];
    while((num = fread(buff, sizeof(char), MAX_LEN, fin)) > 0)
    {
        buff[num] = '\0';
        printf("%s", buff);
        fwrite(buff, sizeof(char), num, fout);
    }
}



