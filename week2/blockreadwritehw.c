#include <stdio.h>

enum {SUCCESS, FAIL, MAX_LEN = 80};

void BlockReadWrite(FILE * fin, FILE * fout);

int main(int argc, char * argv[])
{
    FILE * fptr1, * fptr2;
    if(argc != 3)
    {
        printf("Wrong number of arguments");
        return 1;
    }
    int reval = SUCCESS;

    if((fptr1 = fopen(argv[2], "w")) == NULL)
    {
        printf("Can not open %s.\n", argv[2]);
        reval = FAIL;
    }
    else if ((fptr2 = fopen(argv[1], "r")) == NULL)
    {
        printf("Can not open %s.\n", argv[1]);
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



