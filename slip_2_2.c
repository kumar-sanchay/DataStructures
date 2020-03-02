#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
} NODE;


NODE * insert_values(NODE *root, int datas){
	
	NODE *node = (NODE *)malloc(sizeof(NODE));
	node->data = datas;
	node->next = NULL;
	if(root==NULL){
		root = node;
	}else{
		root->next = insert_values(root->next, datas);

	}
	
	return root;
}

int serach(NODE *root, int value){
	int position = 0;
	if(root==NULL){
		return -1;
	}
	else{
		while(root!=NULL){
			position++;
			if(root->data==value){
				return position;
			}else{
				root = root->next;
			}			
		}
	}
}

void sort(NODE *root){
	if(root==NULL || root->next==NULL){
		return;
	}else{
		NODE *node = (NODE *)malloc(sizeof(NODE));
		node = root->next;	
		while(node!=NULL){
			if(node->data<root->data){
				root->data = root->data + node->data;
				node->data = root->data - node->data;
				root->data = root->data - node->data;
			}
			root = root->next;
			node = node->next;
		}
		
	}

}

void print_values(NODE *root){
	
	while(root!=NULL){
		printf("%d ",root->data);
		root = root->next;
	}
}

void main(){
	// Remaining presentaion should be done by yourself in main method.
	NODE *node = NULL;
	int n;
	scanf();
	node = insert_values(node, 1);
	node = insert_values(node, 4);
	node = insert_values(node, 3);
	//print_values(node);
	sort(node);
	print_values(node);
	int val=serach(node, 3);
}
