/*
 * 8. Montar programa que empilhe e calcule conforme segue:
 * - Aceita somente, número, +,-,*,/,m,l,s
 * - se número, empilhar
 * - se +,-,*,/ desempilhar os últimos 2 elementos, calcular e empilhar o resultado
 * - se m, mostrar a pilha
 * - se l, limpar a pilha
 * - se s, sair.
 * - a pilha terá no máximo 50 elementos
 */

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
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

int popFunction(struct stack *s){
	int numero = -1;
	if(emptyFunction(s)){
		printf("Operação Inválida! Pilha vazia!\n");
		}
	else{
		printf("Valor removido: %d\n", s->itens[s->top]);
		int numero = s->itens[s->top];
		s->top--;		
		}
	return numero;
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

int main(){

	struct stack s;
	s.top = -1;

	struct stack sI;
	sI.top = -1;
	
	struct stack even;
	even.top = -1;
	
	struct stack odd;
	odd.top = -1;

	char escolha;
	
	
	printf("PILHAS - QUESTÃO 8\n");	
	
	do{
		printf("\t\t\tNúmero para empilhar\n");
		printf("\t\t\t+, -, * ou /\n");
		printf("\t\t\tm, mostrar a pilha\n");
		printf("\t\t\tl, limpar a pilha\n");
		printf("\t\t\ts, sair\n");
		
		scanf("%c", &escolha);	
		
		if('+' == escolha){	
			if(emptyFunction(&s)){
				printf("Lista vazia");
				}
			else{
				int a = popFunction(&s);
				int b = popFunction(&s);
				if(b<0){
					b = 0;
					}
				printf("Soma: %d\n", a+b);
				pushFunction(&s, (a+b));
				}
			}

		else if('-' == escolha){
			if(emptyFunction(&s)){
				printf("Lista vazia");
				}
			else{
				int a = popFunction(&s);
				int b = popFunction(&s);
				if(b<0){
					b = 0;
					}
				printf("Subtração: %d\n", a-b);
				pushFunction(&s, (a-b));
				}
			}

		else if('*' == escolha){
			if(emptyFunction(&s)){
				printf("Lista vazia");
				}
			else{
				int a = popFunction(&s);
				int b = popFunction(&s);
				if(b<0){
					b = 1;
					}
				printf("Multiplicação: %d\n", a*b);
				pushFunction(&s, (a*b));
				}
			}

		else if('/' == escolha){
			if(emptyFunction(&s)){
				printf("Lista vazia");
				}
			else{
				int a = popFunction(&s);
				int b = popFunction(&s);
				if(b<0){
					b = 1;
					}
				printf("Divisão: %d\n", a/b);
				pushFunction(&s, (a/b));
				}
			}	
		
		else if('m' == escolha){
			printStack(&s);
			}
		
		else if('l' == escolha){
			int sTop = s.top;
			for(int i=0; i<=sTop; i++){
				popFunction(&s);
				} 
			}
		
		else if(escolha >= '0' && escolha <= '9'){
			int valor = atoi(&escolha);
			pushFunction(&s, valor);
			}		
		
		}while(escolha != 's');


	return 0;
}
