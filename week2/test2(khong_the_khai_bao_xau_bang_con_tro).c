#include <stdio.h>
#include <string.h>

int main() 
{
	char *str;
	gets(str);	
	printf("%d", strlen(str));
	return 0;	
}
//hạn chế dùng scanf vì nó không xử lý được dấu cách 
//không thể khai báo xâu bằng con trỏ, chỉ có thể gọi xâu bằng con trỏ trong khai báo hàm
