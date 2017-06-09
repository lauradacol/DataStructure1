/* Dê um procedimento que inverta uma lista simpĺesmente encadeada de n 
 * elementos em tempo Θ(n). Em outras palavras, após inverter, os 
 * ponteiros devem apontar para trás.
 */ 

#include<stdio.h>
#include<stdlib.h>

typedef struct lista{
	int key;
	struct lista * next;
}lista;

lista * insert(lista * p, int key){
	lista * nodo = malloc(sizeof(lista));
	
	nodo->key = key;	
	nodo->next = p;
	
	return nodo;
}

lista * invert(lista * p, lista * k){
	if(p == NULL){
		return k;
	}
	
	else{
		k = insert(k, p->key);
		return invert(p->next, k);
	}	
}

void print(lista * p){
	lista * aux;
	
	for(aux = p; aux!=NULL; aux = aux->next){
		printf("%d ", aux->key);	
	}
	printf("\n");
}


int main(){

	lista * p;
	p = NULL;
	
	p = insert(p, 1);
	p = insert(p, 5);		
	p = insert(p, 3);

	print(p);
	
	lista * k = invert(p, NULL);
	print(k);
	
	return 0;
}

