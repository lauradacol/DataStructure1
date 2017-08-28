/* 2. Implemente uma função para inserir um novo nodo em uma lista 
 * duplamente encadeada ordenada. A chave de ordenação é o código (key). 
 * A função deve receber como parâmetro um ponteiro para a lista e um 
 * ponteiro para a chave a ser incluída. Note que a lista sempre estará 
 * ordenada em ordem crescente, inclusive após a inserção do novo nodo.
 */ 

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int key;
	struct node * next, * prev;
}node;

typedef struct list{
	node * first, * last;
}list;

void insert_ordenado(list * h, int key){
	node * nodo = malloc(sizeof(node));
	nodo->key = key;
		
	node * aux;	
	
	if(h->first == NULL){
		h->first = h->last = nodo;
	}
	
	else{
		for(aux = h->first; (aux!=NULL & aux->key < key); aux = aux->next){}
		
		if(aux == h->first){
			nodo->next = aux;
			nodo->prev = NULL;
			aux->prev = nodo;
			h->first = nodo;			
		}
		
		else if(aux==NULL){
			h->last->next = nodo;
			nodo->prev = h->last;
			h->last = nodo;			
		}
			
		else{
			aux->prev->next = nodo;
			nodo->prev = aux->prev;
			aux->prev = nodo;
			nodo->next = aux;			
		}		
	}		
}

void print(list * h){
	node * aux;
	
	for(aux = h->first; aux!=NULL; aux = aux->next){
		printf("%d ", aux->key);
	}
	printf("\n");
}

int main(){

	list h;
	h.first = NULL;
	h.last = NULL;
	
	insert_ordenado(&h, 8);
	insert_ordenado(&h, 1);	
	insert_ordenado(&h, 7);
	insert_ordenado(&h, -3);
	insert_ordenado(&h, 0);	
	insert_ordenado(&h, 0);
	insert_ordenado(&h, -15);
								
	print(&h);

	return 0;
}
