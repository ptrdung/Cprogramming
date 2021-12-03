#include <stdio.h>

void sort(int A[], int n)
{	int swap;
	for(int i = 0; i < n; i++)
		for(int j = i; j < n; j++)
		{
			if(A[i] > A[j]) 	
			{
				swap = A[i];
				A[i] = A[j];
				A[j] = swap;
			}
		}
	printf("Array after sorting \n");
	for(int i = 0; i < n; i++) 
		printf("%d \n", A[i]);
}

void finding_median(int A[], int n)
{
	if(n % 2 == 0) 
	{
		if((A[(n-2)/2] + A[n/2]) % 2 == 0)
			printf("The median number is: %d", (A[(n-2)/2] + A[n/2])/2);
		else 
			printf("The median number is: %.1f", (A[(n-2)/2] + A[n/2])/2.0);
	}
	else 
		printf("The median element is: %d", A[(n-1)/2]);
}

int main() 
{
	int A[50];
	int n;
	printf("Enter the number of element in array: \n");
	scanf("%d", &n);
	printf("Enter elements of array: \n");
	for(int i = 0; i < n; i++)
	{
		printf("A[%d] = ", i);
		scanf("%d", &A[i]);
	}
	sort(A, n);
	finding_median(A, n);
	return 0;	
}