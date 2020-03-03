#include<stdio.h>
#include<stdlib.h>

typedef struct node{

	int data;
	struct node *next;
} NODE;

typedef struct graph{
	int vertices;
	//array of pointers
	struct node **edges;
} GRAPH;


GRAPH * create_graph(int vertices){
	
	GRAPH *g = (GRAPH *)malloc(sizeof(GRAPH));
	g->vertices = vertices;
	g->edges = malloc(vertices*sizeof(NODE));
	
	int i;
	for(i=0; i<vertices; i++){
		g->edges[i] = NULL;
	}
	return g;
}

NODE * create_node(int value){
	NODE *node = (NODE *)malloc(sizeof(NODE));
	node -> data = value;
	node->next = NULL;
	return node;
}

void create_edge(GRAPH *graph, int src, int dest){
	//Making edge from source to destination
	NODE *node = create_node(dest);
	node->next = graph->edges[src];
	graph->edges[src] = node;
	
	//Making edge from destination to source
	node = create_node(src);
	node->next = graph->edges[dest];
	graph->edges[dest] = node;
}

void print_graph(GRAPH *graph){
	int i;
	for(i=0; i<graph->vertices; i++){
		NODE *temp = graph->edges[i];
		while(temp){
			printf("%d -> ", temp->data);
			temp = temp->next;
		}
		printf("\n");
	}

}

void main(){
	GRAPH *graph = create_graph(4);
	create_edge(graph, 0, 1);
	create_edge(graph, 0, 2);
	create_edge(graph, 2, 1);
	create_edge(graph, 4, 1);

	print_graph(graph);
}
