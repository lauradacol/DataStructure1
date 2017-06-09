/* Escreva um procedimento para retornar o elemento do meio de uma lista 
 * duplamente encadeada.
 */

#include<stdio.h>
#include<stdlib.h>

typedef struct lista{
	int id;
	struct lista *prev, *next;
}lista;

typedef struct head{
	lista *first, *last;
}head;

void insert(head * h, int x){
	lista * nodo = malloc(sizeof(lista));
	
	nodo->id = x;
	nodo->next = NULL;
	
	if(h->first == NULL){
		h->first = h->last = nodo;
	}
		
	else{
		h->last->next = nodo;
		nodo->prev = h->last;
		h->last = nodo;
	}
}

void insert_ordenado(head * h, int x){
	lista * nodo = malloc(sizeof(lista));
	lista * aux;
	
	nodo->id = x;
	
	if(h->first == NULL){
		h->first = h->last = nodo;
		nodo->next = nodo->prev = NULL;
	}
		
	else{

		for(aux = h->first; (aux!=NULL && aux->id < x); aux = aux->next){
		}
			
		if(aux == h->first){
			nodo->next = h->first;
			h->first->prev = nodo;
			nodo->prev = NULL;
			h->first = nodo;
		}
				
		else if(aux==NULL){
			h->last->next = nodo;
			nodo->prev = h->last;
			nodo->next = NULL;
			h->last = nodo;	
		}
		
		else{
			aux->prev->next = nodo;
			nodo->prev = aux->prev;
			nodo->next = aux;
			aux->prev = nodo;	
		}	
	
	}
	
}

void search(head * h, int i){
	lista * aux;
	int count = 0;
	
	if(h->first == NULL){
		printf("lista vazia!\n");		
	}
	
	else{
		for(aux=h->first; (aux!=NULL && count != i); aux = aux->next){
			count++;	
		}
		
		if(aux==NULL){
			printf("%d\n", h->last->id);	
		}
		
		else{
			printf("%d\n", aux->id);		
		}			
	}
}

void print(head * h){
	lista *aux;
	
	for(aux = h->first; aux!=NULL; aux = aux->next){
		printf("%d ", aux->id); 
	}
	printf("\n");
	
}

int main(){

	head h;
	h.first = NULL;
	h.last = NULL;
	
	insert_ordenado(&h, 7);
	insert_ordenado(&h, 1);
	insert_ordenado(&h, 4);
	insert(&h, 3);
		
	print(&h);

	search(&h, 0);	
	search(&h, 1);
	search(&h, 2);	
	search(&h, 3);	

	return 0;
}
