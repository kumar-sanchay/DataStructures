#include<stdio.h>
#include<stdlib.h>

int quick(int *, int, int);
void quicksort(int *, int, int);
void random_array(int *, int);
void print_array(int *, int);
void swap(int *, int *);

void main(){

	int n;
	printf("Enter the size of the array: ");
	scanf("%d", &n);
	int array[n];
	random_array(array, n);
	printf("Initial array: ");
	print_array(array, n);
	quicksort(array, 0, n-1);
	printf("Sorted array: ");
	print_array(array, n);
}


void random_array(int *arr, int size){
	int i;
	for(i=0; i<size; i++){
		arr[i]=(rand()%(99-10))+10;
	}
}


int quick(int *arr, int l, int r){
	
	int pivot = r;
	int i = (l-1);
	int j = l;
	
	while(j<r){
		if(arr[pivot]>arr[j]){
			i++;
			swap(&arr[i], &arr[j]);
		}
		j++;
	}
	swap(&arr[i+1], &arr[pivot]);
	pivot = i+1;
	
	return pivot;
	
}

void swap(int *a, int *b){
	int t = *a; 
        *a = *b; 
        *b = t; 
}

void quicksort(int *arr, int l, int r){

	if(l<r){
		int pi = quick(arr, l, r);
		quicksort(arr, l, pi-1);
		quicksort(arr, pi+1, r);
	}
}

void print_array(int *arr, int size){
	int i;
	for(i=0; i<size; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
};
