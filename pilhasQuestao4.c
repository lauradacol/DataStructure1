/*
 * 3. Construir uma função que troca de lugar o elemento que está no topo 
 * da pilha com o que está na base da pilha. Usar apenas uma pilha como 
 * auxiliar.
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


int main(){

	struct stack s;
	s.top = -1;

	struct stack sI;
	sI.top = -1;

	int escolha = 0;
	
	printf("PILHAS - QUESTÃO 4\n COMPARAR DUAS PILHAS");	

	printf("Insira o tamanho da pilha 1: ");
	int tamanho1 = 0;
	scanf("%d", &tamanho);
	
	printf("Insira os %d elementos da pilha 1: \n", tamanho);
	int elemento1;
	for(int i=0; i<tamanho1; i++){
		scanf("%d", &elemento1);
		pushFunction(&s, elemento1);
		}
	
	printf("Insira o tamanho da pilha 2: ");
	int tamanho2;
	scanf("%d", &tamanho2);
	
	printf("Insira os %d elementos da pilha 2: \n", tamanho);
	int elemento;
	for(int i=0; i<tamanho2; i++){
		scanf("%d", &elemento);
		pushFunction(&s, elemento);
		}	


/*
	do{
		printf("\t\t\t1- Para imprimir o stack\n");
		printf("\t\t\t2- Para função push\n");
		printf("\t\t\t3- Para função pop\n");
		printf("\t\t\t4- Para função empty\n");
		printf("\t\t\t5- Para função full\n");
		printf("\t\t\t6- Para função size\n");
		printf("\t\t\t7- Para função stack top\n\n");
		printf("\t\t\t8 - PARA INVERTER O STACK\n\n");
		printf("\t\t\t9 - PARA TROCAR BASE POR TOPO\n\n");
		printf("\t\t\t10- Para sair\n");

		scanf("%d", &escolha);

		if(escolha==1){					
			printStack(&s);
		}
		
		else if(escolha==2){
			printf("Digite o valor a ser inserido: ");
			int valor;
			scanf("%d", &valor);
			pushFunction(&s, valor);
		}

		else if(escolha==3){
			popFunction(&s);
		}

		else if(escolha==4){
			int truefalse = emptyFunction(&s);

			if (truefalse==true){
				printf("Pilha vazia\n");
			}
			else{
				printf("Pilha não vazia\n");
			}
		}

		else if(escolha==5){
			int truefalse = fullFunction(&s);

			if (truefalse==true){
				printf("Pilha cheia\n");
			}
			else{
				printf("Pilha não cheia\n");
			}
		}

		else if(escolha==6){
			printf("Tamanho da pilha: %d\n", sizeFunction(&s));
		}

		else if(escolha==7){
			printf("Último elemento da lista: %d\n", stacktopFuncion(&s));
		}
		
		else if(escolha==8){
			inverteStack(&s, &sI);
			}
			
		else if(escolha==9){
			topoBase(&s);
			}

	}while(escolha!=10);
	*/

	return 0;
}
