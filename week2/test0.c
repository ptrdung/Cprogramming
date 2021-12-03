#include <stdio.h>
#include <string.h>

int main() 
{
	char string[45];
	fgets(string, 45, stdin);
	printf("%d", strlen(string));
	printf("\n%s",string);
	return 0;
}
//đếm cả enter khi nhập xâu.
//strlen không đếm ký tự \0
//hạn chế dùng scanf vì nó không xử lý được dấu cách
//xâu chỉ thực hiện được phép gán khi khởi tạo, còn sau khởi tạo ko thực hiện được pháp gán
 
