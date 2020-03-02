#include<stdio.h>
#include<stdlib.h>


void random_array(int, int, int, int*);
void insertion_sort(int*, int);
void print_array(int*, int);

void main(){

	int n;
	printf("Enter n : ");
	scanf("%d", &n);
	int array[n];
	random_array(10, 99, n, array);
	printf("Intial array: ");
	print_array(array, n);
	insertion_sort(array, n);
	printf("Sorted array: ");
	print_array(array, n);
}


void random_array(int lower, int upper, int n, int* array){
	int i;
	for(i=0; i<n; i++){
		array[i] = (rand()%(upper-lower)) + lower;
	}
}

void insertion_sort(int *array, int n){
	int i, j;
	for(i=1; i<n; i++){
		for(j=i; j>0; j--){
			if(array[j]<array[j-1]){
				array[j] = array[j]+array[j-1];
				array[j-1] = array[j]-array[j-1];
				array[j] = array[j]-array[j-1];
			}
		}
	}
}

void print_array(int *array, int n){
	int i;
	for(i=0; i<n; i++){
		printf("%d ", array[i]);
	}
	printf("\n");
}
