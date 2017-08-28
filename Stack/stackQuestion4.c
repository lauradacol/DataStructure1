/*
 * 4. Comparar se duas pilhas são iguais
 */

#include<stdio.h>
#include<stdbool.h>
#define STACKSIZE 4

struct stack {
	int top;
	int itens[STACKSIZE];
};

void printStack(struct stack *s){
	printf("Top: %d\n", s->top);
	printf("Itens: ");
	for(int i=0; i<=s->top; i++){
		printf("%d ", s->itens[i]);
	}
	printf("\n");
}

bool fullFunction(struct stack *s){
	if(((s->top)+1)==STACKSIZE){
		return true;
	}
	else{
		return false;
	}
}

void pushFunction(struct stack *s, int valor){
	if(fullFunction(s)){
		printf("Pilha cheia!\n");
		}
	else{
		s->top++;	
		s->itens[s->top] = valor;
	}
}

bool emptyFunction(struct stack *s){
	if((s->top)<0){
		return true;
	}
	else{
		return false;
	}
}

void popFunction(struct stack *s){
	if(emptyFunction(s)){
		printf("Operação Inválida! Pilha vazia!\n");
		}
	else{
		printf("Valor removido: %d\n", s->itens[s->top]);
		s->top--;		
		}
}

int sizeFunction(struct stack *s){
	return s->top+1;
}

int stacktopFuncion(struct stack *s){
	return s->itens[s->top];
}

void inverteStack(struct stack *s, struct stack *sI){
	for(int i=(s->top); i>=0; i--){
		pushFunction(sI, s->itens[i]);
		}
	printStack(sI);
	
	for(int k=s->top; k>=0; k--){
		popFunction(s);
		}
	
	for(int j=0; j<=(sI->top); j++){
		pushFunction(s, (sI->itens[j]));
		}
	printStack(s);
	}

void topoBase(struct stack *s){
	int aux = s->itens[s->top];
	s->itens[s->top] = s->itens[0];
	s->itens[0] = aux;
	}

bool equalFunction(int tamanho1, int tamanho2, struct stack* s, struct stack* sI){
	if(tamanho1 != tamanho2){
		return false;
		}
	else if(tamanho1 == tamanho2){
		int count = 0;
		for(int i=0; i<tamanho1; i++){
			if(s->itens[i] == sI->itens[i]){
				count++;
				}
			}
		if(count==tamanho1){
			return true;
			}
		else{
			return false;
			}
		}
	}


int main(){

	struct stack s;
	s.top = -1;

	struct stack sI;
	sI.top = -1;

	int escolha = 0;
	
	printf("PILHAS - QUESTÃO 4\n COMPARAR DUAS PILHAS\n");	

	printf("Insira o tamanho da pilha 1: ");
	int tamanho1 = 0;
	scanf("%d", &tamanho1);
	
	printf("Insira os %d elementos da pilha 1: \n", tamanho1);
	int elemento1;
	for(int i=0; i<tamanho1; i++){
		scanf("%d", &elemento1);
		pushFunction(&s, elemento1);
		}
	
	printf("Insira o tamanho da pilha 2: ");
	int tamanho2;
	scanf("%d", &tamanho2);
	
	printf("Insira os %d elementos da pilha 2: \n", tamanho2);
	int elemento2;
	for(int i=0; i<tamanho2; i++){
		scanf("%d", &elemento2);
		pushFunction(&sI, elemento2);
		}	

	if(equalFunction(tamanho1, tamanho2, &s, &sI)){
		printf("É igual\n");
		}
	else{
		printf("não é igual\n");
		}


	return 0;
}
