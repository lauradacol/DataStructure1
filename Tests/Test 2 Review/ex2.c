/*
 * 2. Implemente as operações de dicionário Insert, Delete e Search, 
 * usando listas circulares e forneça seus tempos de execução.
 */

#include<stdio.h>
#include<stdlib.h>

typedef struct lista{
	int x;
	struct lista * next, *prev;
}lista;

typedef struct head{
	lista * first, * last;
}head;

void print(head * h){
	lista * aux = h->first;
	
	if(h->first == NULL){
		printf("Lista vazia!\n");
		}
	
	else{
		printf("%d ", aux->x);
		
		for(aux = h->first; aux->next!=h->first; aux = aux->next){
			printf("%d ", aux->next->x);
			}
		printf("\n");		
		}
	}

void insert(head * h, int x){
	lista * nodo = malloc(sizeof(lista));
	
	nodo->x = x;
	nodo->next = NULL;
	nodo->prev = NULL;
	
	if(h->first == NULL){
		h->first = h->last = nodo;
		}
		
	if((h->first == h->last) && h->first != NULL){
		h->first->next = nodo;
		h->first->prev = nodo;
		nodo->prev = h->first;
		nodo->next = h->first;
		h->last = nodo;
		}
		
	else{
		h->first->prev = nodo;
		nodo->next = h->first;
		h->last->next = nodo;
		nodo->prev = h->last;
		h->last = nodo;
		}
	}

void delete(head * h){
	lista * aux;
	aux = h->last;
	
	if(h->first == h->last){
		h->first = NULL;
		h->last = NULL;
		}
		
	else{
		h->last = h->last->prev;
		h->last->next = h->first;
		h->first->prev = h->last;		
		}
	free(aux);	
	}

int empty(head * h){
	int r;
	if(h->first == NULL){
		r = 0;
		}
	else{
		delete(h);
		r = 1;
		}	
	return r;
	}
	
int search(head * h, int x){
	lista * aux;

	if(h->first->x==x){
		printf("Posição na lista: %d\n", 0);
		}
	else{
		int count = 1;
		for(aux = h->first; aux->next!=h->first; aux = aux->next){
			if ((aux->next->x)==x){
				printf("Posição na lista: %d\n", count);
				}
			}		
		}	
	}
	
int main(){

	head h;
	h.first = NULL;
	h.last = NULL;
	
	insert(&h,1);
	insert(&h,2);
	insert(&h,3);
	
	print(&h);
	search(&h, 2);
	
	empty(&h);	
	print(&h);		
		
	return 0;
}
