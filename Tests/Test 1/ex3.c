/* 3. Construa uma função que recebe um ponteiro para uma lista encadeada 
 * (com cabeça) e um ponteiro para um elemento. A função deve excluir o 
 * elemento da lista. Considere as estruturas da questão 2.
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

void delete(list * h, int k){
	node * aux;
	
	if(h->first == NULL){
		printf("Lista vazia!\n");
	}
	
	else{
		for(aux=h->first; (aux!=NULL && aux->key != k); aux = aux->next){}
		
		if(aux == h->first){
			aux->next->prev = NULL;
			h->first = aux->next;
		}
		
		else if(aux == h->last){
			aux->prev->next = NULL;
			h->last = aux->prev;	
		}
		
		else if(aux == NULL){
			printf("Elemento não localizado\n");
		}
		
		else{
			aux->prev->next = aux->next;
			aux->next->prev = aux->prev;
		}
		
		free(aux);
	
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
	
	delete(&h, 5);
	
	insert_ordenado(&h, 8);
	insert_ordenado(&h, 1);	
	insert_ordenado(&h, 7);
	insert_ordenado(&h, -3);
	insert_ordenado(&h, 0);	
	insert_ordenado(&h, 0);
	insert_ordenado(&h, -15);
								
	print(&h);
	
	delete(&h, 100);
	delete(&h, 8);
	print(&h);

	delete(&h, 0);
	print(&h);

	return 0;
}
