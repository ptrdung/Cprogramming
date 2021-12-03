#include <stdio.h>
#include <string.h>
// All character are lower case
int main() 
{
	int count;
	char string[100];
	printf("Enter string: ");
	gets(string);
	for(char i = 'a'; i <= 'z'; i++)
	{
		count = 0;
		for(int j = 0; j <= strlen(string); j++)
			if(string[j] == (int)i) ++count;
		if(count > 0) 
			printf("The letter %c appears %d times\n", i, count);
	}
	for(char i = 'A'; i <= 'Z'; i++)
	{
		count = 0;
		for(int j = 0; j <= strlen(string); j++)
			if(string[j] == (int)i) ++count;
		if(count > 0) 
			printf("The letter %c appears %d times\n", i, count);
	}
}

