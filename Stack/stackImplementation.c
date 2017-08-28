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

bool emptyFunction(struct stack *s){
	if((s->top)<0){
		return true;
	}
	else{
		return false;
	}
}

bool fullFunction(struct stack *s){
	if((s->top)==(STACKSIZE-1)){
		return true;
	}
	else{
		return false;
	}
}

void pushFunction(struct stack *s, int valor){
	if (fullFunction(s)){
		printf("Pilha cheia!\n");
		}
	
	else{
		s->top++;	
		s->itens[s->top] = valor;		
		}
}

int popFunction(struct stack *s){
	int valor = s->itens[s->top];
	s->top--;

	return valor;
}

int sizeFunction(struct stack *s){
	return s->top;
}

int stacktopFuncion(struct stack *s){
	return s->itens[s->top];
}


int main(){

	struct stack s;
	s.top = -1;

	int escolha = 0;

	do{
		printf("\t\t\t1- Para imprimir o stack\n");
		printf("\t\t\t2- Para função push\n");
		printf("\t\t\t3- Para função pop\n");
		printf("\t\t\t4- Para função empty\n");
		printf("\t\t\t5- Para função full\n");
		printf("\t\t\t6- Para função size\n");
		printf("\t\t\t7- Para função stack top\n");
		printf("\t\t\t8- Para sair\n");

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
			printf("Último valor: %d (removido\n)", popFunction(&s));
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

	}while(escolha!=8);

	return 0;
}
