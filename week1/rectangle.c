#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    long height, width;
    if(argc != 3) {
        printf("Wrong number of arguments!\n");
        return 1;
    }
    height = strtol(argv[1], NULL, 10);
    width = strtol(argv[2], NULL, 10);
    printf("\nheight = %ld", height);
    printf("\nwidth = %ld", width);
    printf("\nThe rectangle's area is %ld", height * width);
    printf("\nThe rectangle's perimeter is %ld", (height + width) * 2);
    return 0;
   
}
// https://stackoverflow.com/questions/9748393/how-can-i-get-argv-as-int/38669018
