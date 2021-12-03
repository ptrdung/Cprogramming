#include <stdio.h>
#include <string.h>

int main() 
{
	char string[50];
	scanf("%s", string);
//  scanf("%50s", string);	
	scanf("%s", string);
	printf("%d", strlen(string));

	return 0;
}
