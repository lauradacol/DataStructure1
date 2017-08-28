#include<stdio.h>
#include<stdbool.h>
#define MAXQUEUE 4

struct queue {
	int front, rear;
	int itens[MAXQUEUE];
};

void printStack(struct queue *s){
	printf("Front: %d\n", s->front);
	printf("Rear: %d\n", s->rear);
	printf("Itens: ");
	for(int i=s->front; i<=s->rear; i++){
		printf("%d ", s->itens[i]);
	}
	printf("\n");
}

bool fullFunction(struct queue *s){
	if((s->rear)==(MAXQUEUE-1)){
		return true;
	}
	else{
		return false;
	}
}

void insertFunction(struct queue *s, int valor){
	if(fullFunction(s)){
		printf("Fila cheia\n");
	}
	else{
		s->rear++;	
		s->itens[s->rear] = valor;
	}
}

bool emptyFunction(struct queue *s){
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
	bool valida = emptyFunction(s);

	if (valida==true){
		printf("Operação inválida - lista vazia\n");
	}
	else{
		printf("Valor removido: %d\n", removeFunction(s));
	}
}

int sizeFunction(struct queue *s){
	return (s->rear)-(s->front)+1;
}

int frontFuncion(struct queue *s){
	return s->itens[s->front];
}

int main(){

	struct queue s;
	s.front = 0;
	s.rear=-1;

	int escolha = 0;

	//printf("MAXQUEUE = %d\n", MAXQUEUE);

	do{
		printf("\n\n\t\t\t1- Para imprimir o queue\n");
		printf("\t\t\t2- Para função insert\n");
		printf("\t\t\t3- Para função remove\n");
		printf("\t\t\t4- Para função empty\n");
		printf("\t\t\t5- Para função full\n");
		printf("\t\t\t6- Para função size\n");
		printf("\t\t\t7- Para função front\n");
		printf("\t\t\t8- Para sair\n");

		scanf("%d", &escolha);

		if(escolha==1){
			printStack(&s);
		}
		
		else if(escolha==2){
			printf("Digite o valor a ser inserido: ");
			int valor;
			scanf("%d", &valor);
			insertFunction(&s, valor);
		}

		else if(escolha==3){
			validaRemove(&s);
			arrumaFrontRear(&s);
		}

		else if(escolha==4){
			int truefalse = emptyFunction(&s);

			if (truefalse==true){
				printf("Fila vazia\n");
			}
			else{
				printf("Fila não vazia\n");
			}
		}

		else if(escolha==5){
			bool truefalse = fullFunction(&s);

			if (truefalse==true){
				printf("Fila cheia\n");
			}
			else{
				printf("Fila não cheia\n");
			}
		}

		else if(escolha==6){
			printf("Tamanho da fila: %d\n", sizeFunction(&s));
		}

		else if(escolha==7){
			printf("Último elemento adicionado na lista: %d\n", frontFuncion(&s));
		}

	}while(escolha!=8);

	return 0;
}
