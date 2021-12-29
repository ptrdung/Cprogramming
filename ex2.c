#include <stdio.h>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    
    int left = low;
    int right = high - 1;
    while(1){
        while(left <= right && arr[left] < pivot) left++; 
        while(right >= left && arr[right] > pivot) right--;
        if (left >= right) break; 
        swap(&arr[left], &arr[right]); 
        left++; 
        right--;
    }
    swap(&arr[left], &arr[high]);
    return left;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
 
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void insertionSort(int arr[], int n)
{
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;
 
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}

int main()
{
    int arr[100], arr1[100], n;
    printf("\nNhap so phan tu mang:");
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        printf("arr[%d] = ", i); 
        scanf("%d",&arr[i]);
        arr1[i] = arr[i];
    }
    
    printf("\nQuickSort\n");
    quickSort(arr, 0, n-1);
    printf("Sorted array: \n");
    printArray(arr, n);
    
    printf("\nInsertionSort\n");
    insertionSort(arr1, n);
    printf("Sorted array: \n");
    printArray(arr1, n);
    return 0;
}
