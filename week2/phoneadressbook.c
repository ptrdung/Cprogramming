#include <stdio.h>
#include <string.h>

enum{SUCCESS, FAIL, MAX_ELEMENT = 100};

typedef struct phoneaddress_t
{
    char name[31];
    char tel[13];
    char email[36];
}phoneaddress;

int main() 
{
    FILE *fp;
    phoneaddress phonearr[MAX_ELEMENT];
    int n, irc;
    int reval = SUCCESS;
    printf("How many contacts do you want to enter (< 11)? ");
    scanf("%d", &n);
    getchar();
    for(int i = 0; i < n; i++)
    {
        printf("name: ");
        fgets(phonearr[i].name, 31, stdin);
        phonearr[i].name[strlen(phonearr[i].name) - 1] = '\0';
        printf("tel: ");
        fgets(phonearr[i].tel, 13, stdin);
        phonearr[i].tel[strlen(phonearr[i].tel) - 1] = '\0';
        printf("email: ");
        fgets(phonearr[i].email, 31, stdin);
        phonearr[i].email[strlen(phonearr[i].email) - 1] = '\0';
    }
    if((fp=fopen("phonebook.dat", "w+b")) == NULL)
    {
        printf("Can not open %s.\n", "phonebook.dat");
        reval = FAIL;
    }
    irc = fwrite(phonearr, sizeof(phoneaddress), n, fp);
    printf("fwrite return code = %d\n", irc);
    fclose(fp);
    //read from this file to array again
    if((fp = fopen("phonebook.dat", "rb")) == NULL)
    {
        printf("Can not open %s.\n", "phonebook.dat");
        reval = FAIL;
    }
    irc = fread(phonearr, sizeof(phoneaddress), n, fp);
    printf("fread return code = %d\n", irc);
    for(int i = 0; i < n; i++)
    {
        printf("%s-", phonearr[i].name);
        printf("%s-", phonearr[i].tel);
        printf("%s\n", phonearr[i].email);
    }
    fclose(fp);
    return reval;
}
