/*
 * 1. Um problema comum para compiladores é saber se os parênteses de 
 * uma string estão balanceados e corretamente aninhados. Por exemplo, 
 * a sentença ((())())() contém corretamente pares de parênteses, que as 
 * strings )()( e ()) não tem. Dê um algoritmo que retorne true se a 
 * string possui os parênteses balanceados e falso caso contrário.
 */

#include<stdio.h>
#include<stdlib.h>

typedef struct pilha{
	int x;
	struct pilha * next, *prev;
}pilha;

typedef struct head{
	pilha * first, * last;
}head;

void print(head * h){
	pilha * aux;
	
	if(h->first == NULL){
		printf("Lista vazia!\n");
		}
	
	else{
		for(aux = h->first; aux!=NULL; aux = aux->next){
			printf("%d ", aux->x);
			}
		printf("\n");		
		}
	}

void push(head * h, int x){
	pilha * nodo = malloc(sizeof(pilha));
	
	nodo->x = x;
	nodo->next = NULL;
	
	if(h->first == NULL){
		h->first = h->last = nodo;
		nodo->prev = NULL;
		}
		
	if((h->first == h->last) && h->first != NULL){
		h->first->next = nodo;
		h->last = nodo;
		nodo->prev = h->first;
		}
		
	else{
		h->last->next = nodo;
		nodo->prev = h->last;
		h->last = nodo;		
		}
	}

void pop(head * h){
	pilha * aux;
	aux = h->last;
	
	if(h->first == h->last){
		h->first = NULL;
		h->last = NULL;
		}
		
	else{
		h->last = h->last->prev;
		h->last->next = NULL;		
		}
	free(aux);	
	}

int empty(head * h){
	int r;
	if(h->first == NULL){
		r = 0;
		}
	else{
		pop(h);
		r = 1;
		}	
	return r;
	}
	
int parenteses(head * h, char x[5]){
	int r;
		
	for(int i=0; i<5; i++){
		if(x[i] == '('){
			push(h, 1);
			r = 1;
			}
			
		else if(x[i] == ')'){
			r = empty(h);
			if(r==0){
				break;
				}
			}		
		}
		
	return r;	
	}

int main(){

	head h;
	h.first = NULL;
	h.last = NULL;
	
	printf("%d\n", parenteses(&h, "()()("));
	
	
		
	return 0;
}
