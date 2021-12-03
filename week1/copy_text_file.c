#include <stdio.h>

int main()
{
    char in_name[25], out_name[25];
    FILE * in_file;
    FILE * out_file;
    int c;
    printf("File to be copied:\n");
    scanf("%24s", in_name);
    printf("Output filename:\n");
    scanf("%24s", out_name);
    in_file = fopen(in_name, "r");
    if(in_file == NULL)
        printf("Can not open %s for reading.\n", in_name);
    else {
        out_file = fopen(out_name, "w");
        if(out_file == NULL)
            printf("Can not open %s for reading.\n", out_name);
        else {
            while((c=fgetc(in_file)) != EOF)
                fputc(c, out_file);
            printf("File has been copied.\n");
            fclose(out_file);
        }
        fclose(in_file);
    }

}
