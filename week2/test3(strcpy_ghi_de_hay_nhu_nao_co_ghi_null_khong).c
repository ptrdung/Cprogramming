#include <stdio.h>
#include <string.h>

int main() 
{
	char str1[50], str2[50];
	scanf("%s", str2);
	strcpy(str1, str2);
	printf("%s",str1);
	printf("\n%d", strlen(str1));
	strcpy(str2, "Phan");
	printf("%s", str2);
	return 0;

}
//strcpy thì cái đích phải đủ chứa cái nguồn 
//All conversion specifiers other than [, c, and n consume and discard all leading whitespace characters (determined as if by calling isspace) before attempting to parse the input. These consumed characters do not count towards the specified maximum field width.