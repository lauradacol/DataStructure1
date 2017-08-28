/*
 * 2. Dada uma pilha p, construir uma função que inverte a ordem dos 
 * elementos dessa pilha. Utilizando-se de uma única fila auxiliar.
 */


#include<stdio.h>
#include<stdbool.h>
#define STACKSIZE 4
#define MAXQUEUE 4

struct stack {
	int top;
	int itens[STACKSIZE];
};

struct queue {
	int front, rear;
	int itens[MAXQUEUE];
};

//FUNÇÕES DE PILHA
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

//FUNÇÕES DE FILA

void printQueue(struct queue *s){
	printf("Front: %d\n", s->front);
	printf("Rear: %d\n", s->rear);
	printf("Itens: ");
	for(int i=s->front; i<=s->rear; i++){
		printf("%d ", s->itens[i]);
	}
	printf("\n");
}

bool fullFunctionFila(struct queue *s){
	if((s->rear)==(MAXQUEUE-1)){
		return true;
	}
	else{
		return false;
	}
}

void insertFunctionFila(struct queue *s, int valor){
	if(fullFunctionFila(s)){
		printf("Fila cheia\n");
	}
	else{
		s->rear++;	
		s->itens[s->rear] = valor;
	}
}

bool emptyFunctionFila(struct queue *s){
	if((s->front)>(s->rear)){
		return true;
	}
	else{
		return false;
	}
}

void arrumaFrontRear(struct queue *s){
	for(int i=(s->front); i<=(s->rear); i++){
		s->itens[i-1] = s->itens[i];
		}
	s->front--;
	s->rear--;
	}

int removeFunction(struct queue *s){
	int valor = s->itens[s->front];
	s->front++;
	return valor;
}

void validaRemove(struct queue * s){
	bool valida = emptyFunctionFila(s);

	if (valida==true){
		printf("Operação inválida - lista vazia\n");
	}
	else{
		printf("Valor removido: %d\n", removeFunction(s));
	}
}

int sizeFunctionFila(struct queue *s){
	return (s->rear)-(s->front)+1;
}

int frontFuncion(struct queue *s){
	return s->itens[s->front];
}

//FUNÇÃO INVERTE
void inverteStack(struct stack* s, struct queue* f){
	for(int i=(s->top); i>=0; i--){
		insertFunctionFila(f, s->itens[i]);
		}
	printQueue(f);
	
	for(int k=s->top; k>=0; k--){
		popFunction(s);
		}
	
	for(int j=0; j<=(f->rear-f->front); j++){
		pushFunction(s, (f->itens[j]));
		}
	printStack(s);
	}

int main(){

	struct stack s;
	s.top = -1;

	struct queue f;
	f.front = 0;
	f.rear=-1;
	
	int escolha = 0;
	
	printf("PILHAS - QUESTÃO 1\n");

	do{
		printf("\t\t\t1- Para imprimir o stack\n");
		printf("\t\t\t2- Para função push\n");
		printf("\t\t\t3- Para função pop\n");
		printf("\t\t\t4- Para função empty\n");
		printf("\t\t\t5- Para função full\n");
		printf("\t\t\t6- Para função size\n");
		printf("\t\t\t7- Para função stack top\n\n");
		printf("\t\t\t8 - PARA INVERTER O STACK\n\n");
		printf("\t\t\t9- Para sair\n");

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
			inverteStack(&s, &f);
			}

	}while(escolha!=9);

	return 0;
}
