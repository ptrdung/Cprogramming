#include <stdio.h>
#include <ctype.h>

enum {SUCCESS, FAIL};

void CharReadWrite(FILE *fin, FILE* fout)
{
    int c;
    while((c  = fgetc(fin)) != EOF)
    {
        if(islower(c)) c = toupper(c);
        else if(isupper(c)) c = tolower(c);
        fputc(c, fout);
        putchar(c);
    }
}

int main() 
{
    int eval;
    FILE * fptr1; 
    FILE * fptr2;
    char filename1[] = "lab1_converted.txt";
    char filename2[] = "lab1.txt";
    if((fptr1 = fopen(filename1, "w")) == NULL)
    {
        printf("Can not open %s.\n", filename1);
        eval = FAIL; 
    }
    else if((fptr2 = fopen(filename2, "r")) == NULL)
    {
        printf("Can not open %s.\n", filename2);
        eval = FAIL;
    }
    else 
    {
        CharReadWrite(fptr2, fptr1);
        fclose(fptr1);
        fclose(fptr2);
    }
    return eval;
}
