#include <stdio.h>
#define MAX 100

int compare_arr(int a[], int b[], int m, int n) {
    if(m != n) return 0;
    else
    {
        for(int i = 0; i < m; i++)
            if(a[i] != b[i]) 
                return 0;
        return 1;
    }
}

int main() {
    int m,n;
    int a[MAX], b[MAX];
    printf("Nhap so phan tu mang thu nhat:");
    do {
        scanf("%d", &m);
    } while(m <= 0);
    for(int i = 0; i < m; i++) {
        printf("Phan tu thu %d: ", i+1);
        scanf("%d", &a[i]);
    }
    printf("Nhap so phan tu mang thu hai:");
    do {
        scanf("%d", &n);
    } while(n <= 0);
    for(int i = 0; i < n; i++) {
        printf("Phan tu thu %d: ", i+1);
        scanf("%d", &a[i]);
    }
    printf("%d", compare_arr(a,b,m,n));
    return 0;

}
