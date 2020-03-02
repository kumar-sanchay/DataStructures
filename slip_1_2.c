#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *left;
	struct node *right;

} NODE;

NODE * insert_node(NODE* root, int datas){
	NODE* node = (NODE *)malloc(sizeof(NODE));
	node -> data = datas;
	node -> left = NULL;
	node -> right = NULL;
	
	if(root==NULL){
		root = node;
	}else{
		if(datas<root->data){
			root->left = insert_node(root->left, datas);
		}else{
			root->right=insert_node(root->right, datas);
		}
	}
	
	return root;
}

NODE * inorder(NODE* root){
	if(root!=NULL){
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}


NODE * preorder(NODE* root){
	if(root!=NULL){
		printf("%d ", root->data);
		inorder(root->left);
		inorder(root->right);
	}
}

void main(){
	
	int n, i; 
	NODE *node = NULL;
	printf("How many data want to enter : ");
	scanf("%d", &n);
	for(i=0; i<n; i++){
		int data;
		printf("Enter data %d :",i+1);
		scanf("%d",&data);
		node = insert_node(node, data);
	}
	printf("Inorder : ");
	inorder(node);
	printf("\nPreorder : ");
	preorder(node);
}


