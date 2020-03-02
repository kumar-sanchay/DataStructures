#include<stdio.h>
#include<stdlib.h>

void print_array(int*, int);
void random_array(int, int, int, int*);
void bubbleSort(int*, int);

void main(){
	
	int n;
	printf("Enter the size of the array : ");
	scanf("%d", &n);
	int array[n];
	random_array(10, 99, n, array);
	printf("Intial Array : ");
	print_array(array, n);
	printf("Sorted Array: ");
	bubbleSort(array, n);
	print_array(array, n);

}

void print_array(int *a, int n){
	int i;
	for(i=0; i<n; i++){
		printf("%d ", a[i]);
	}
	printf("\n");

}

void random_array(int lower, int higher, int count, int* num){
	int i;

	for(i=0; i<count; i++){
		num[i]=(rand()%(higher-lower))+lower;	
	}
}

void bubbleSort(int *a, int n){
	int i, j;
	for(i=0; i<n-1; i++){
		for(j=0; j<n-i-1; j++){
			if(a[j] > a[j+1]){
				a[j] = a[j] + a[j+1];
				a[j+1] = a[j] - a[j+1];
				a[j] = a[j] - a[j+1];
			}

		}
	}
}
