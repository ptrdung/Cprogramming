#include <stdio.h>

void split(double num, int *int_part, double *frac_part) {
    *int_part = (int)num;
    *frac_part = num - *int_part;
}

int main() {
    double num;
    int int_part;
    double frac_part;
    printf("Nhap so: ");
    scanf("%lf", &num);
    split(num, &int_part, &frac_part);
    printf("Phan nguyen la: %d\n", int_part);
    printf("Phan thap phan la: %lf\n", frac_part);
    return 0;
}
