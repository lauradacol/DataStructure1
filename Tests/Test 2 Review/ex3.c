/*
 * 3. Dê um procedimento que inverta uma lista simplesmente ligada de n 
 * elementos em tempo Θ(n). Em outras palavras, após inverter, os 
 * ponteiros devem apontar para trás.
 */

#include<stdio.h>
#include<stdlib.h>

typedef struct lista{
	int id;
	struct lista * next;	
}lista;

void print(lista * p){
	lista * aux = p;
	
	for(aux; aux!=NULL; aux = aux->next){
		printf("%d ", aux->id);		
	}
	printf("\n");
}

lista * insert(lista * p, int id){
	lista * nodo = malloc(sizeof(lista));
	lista * aux;

	nodo->id = id;
	nodo->next = p;

	return nodo;

}

//com for
lista * invert(lista * p){
	lista * aux = p;
	lista *j = NULL;
	
	
	for(aux; aux!=NULL; aux = aux->next){
		j = insert(j, aux->id);
	}
		
	return j;
	
}

//recursiva
lista * invert2(lista * p, lista * j){
	if(p == NULL){
		return j;
	}
		
	else{
		j = insert(j, p->id);
		return invert2(p->next,j);	
	}
	
}

	
int main(){

	lista * p;
	
	p = NULL;
	
	p = insert(p, 1);
	p = insert(p, 2);
	p = insert(p, 3);
	
	print(p);
	
	lista * j = invert(p);
	print(j);
	
	lista * k = invert2(p, NULL);
	print(k);
	
	return 0;
}
