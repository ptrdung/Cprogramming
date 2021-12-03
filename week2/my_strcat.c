#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* my_strcat(char *str1, char *str2)
{
	char *result;
	int len1, len2;
	len1 = strlen(str1);
	len2 = strlen(str2);
	result = (char *)malloc((len1 + len2 + 1) * sizeof(char));	
	if(result == NULL)
	{
		printf("Allocation failed! Check memory\n");
		return NULL;
	}
    for(int i = 0; i < len1; i++) 
        *(result+i) = *(str1+i);
    for(int i = 0; i < len2; i++)
        *(result+len1+i) = *(str2+i);
    *(result+len1+len2) = '\0';
    return result;
}

int main() {
    char  str1[1000], str2[1000];
    char * result;
    fgets(str1, 1000, stdin);
    str1[strlen(str1) - 1] = '\0';
    fgets(str2, 1000, stdin);
    str2[strlen(str2) - 1] = '\0';
    result = (char*)malloc((strlen(str1)+strlen(str2)+1)*sizeof(char));
    result = my_strcat(str1, str2);
    printf("%s", result);
    return 0;
}
