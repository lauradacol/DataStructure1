#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//estrutura do nodo da lista
typedef struct lista{
	int id;
	char nome[30];	
	struct lista * next, * prev;
}lista;

//estrutura da cabeça
typedef struct head{
	lista * first, * last;
}head;
	
int empty(head * h){
	if(h->first == NULL){
		return 0;
	}
	
	else{
		return 1;
	}
}

//insere 'x' ordenado pelo id na lista'
void insert_ordenado(head * h, int idade, char nome[30]){
	lista * nodo = malloc(sizeof(lista));
	lista * aux;
	
    //inicia os valores do nodo
	nodo->id = idade;
	strcpy(nodo->nome, nome);
	
	if(empty(h)==0){
		h->first = h->last = nodo;
		nodo->next = nodo->prev = NULL;
	}
		
	else{

		for(aux = h->first; (aux!=NULL && aux->id < idade); aux = aux->next){
		}
			
		if(aux == h->first){
			nodo->next = h->first;
			h->first->prev = nodo;
			nodo->prev = NULL;
			h->first = nodo;
		}
				
		else if(aux==NULL){
			h->last->next = nodo;
			nodo->prev = h->last;
			nodo->next = NULL;
			h->last = nodo;	
		}
		
		else{
			aux->prev->next = nodo;
			nodo->prev = aux->prev;
			nodo->next = aux;
			aux->prev = nodo;	
		}		
	}	
}

/*
//insere 'x' ordenado pelo nome na lista'
void insert_ordenado(head * h, int idade, char nome[30]){
	lista * nodo = malloc(sizeof(lista));
	lista * aux;
	
    //inicia os valores do nodo
	nodo->id = idade;
	strcpy(nodo->nome, nome);
	
	if(empty(h)==0){
		h->first = h->last = nodo;
		nodo->next = nodo->prev = NULL;
	}
		
	else{

		for(aux = h->first; (aux!=NULL && aux->nome[0]<=nome[0]); aux = aux->next){
		}
			
		if(aux == h->first){
			nodo->next = h->first;
			h->first->prev = nodo;
			nodo->prev = NULL;
			h->first = nodo;
		}
				
		else if(aux==NULL){
			h->last->next = nodo;
			nodo->prev = h->last;
			nodo->next = NULL;
			h->last = nodo;	
		}
		
		else{
			aux->prev->next = nodo;
			nodo->prev = aux->prev;
			nodo->next = aux;
			aux->prev = nodo;	
		}		
	}	
}
*/
void delete_list(head * h, int idade, char nome[30]){
	lista * aux;
	
	//caso em que a lista está vazia
	if(empty(h)==0){
		printf("Lista vazia\nOperação Inválida\n");
		}
	
	else{
		for(aux = h->first; (aux!=NULL && aux->id != idade && ((strcmp(aux->nome, nome))!=0)); aux = aux->next){
		}	
				
		//caso o elemento não seja localizado
		if(aux==NULL){
			printf("Cadastro não localizado\n");
		}
		
		else if(aux==h->first){
			//caso em que só tem um elemento na lista
			if(aux == h->last){
				h->first == NULL;				
			}
				
			//caso em que o elemento a ser excluido seja o primeiro	
			else{
				aux->next->prev = NULL;
				h->first = aux;
			}
		}
		
		//caso o elemento a ser excluído seja o último
		else if(aux==h->last && aux!=h->first){
			aux->prev->next = NULL;
			h->last = aux->prev;			
		}
		
		//caso o elemento a ser excluído esteja no meio da lista
		else{
			aux->next->prev = aux->prev;
			aux->prev->next = aux->next;
		}
		
		free(aux);		
	}	
}

lista * min_list(head * h){
	return h->first;
}

lista * sucessor(head * h, int idade){
	lista * aux;
	
	for(aux=h->first; aux->id!=idade; aux = aux->next){
	}
	
	return aux->prev;
}

void print_lista(head * h){
	lista * aux;
		
	for(aux = h->first; aux != NULL; aux = aux->next){
		printf("Nome: %s\n", aux->nome);
		printf("Idade: %d\n\n", aux->id);
		}		
	}

void print(lista * nodo){
	printf("Nome: %s\n", nodo->nome);
	printf("Idade: %d\n", nodo->id); 
}

int size(head * h){
	int size = 0;
	lista * aux;
	
	for(aux = h->first; aux != NULL; aux = aux->next){
		size++;
	}
	
	return size;
}
	
void print_ordenado(head * h){
	lista * aux, * aux2;
	
	char letra = 'a';
	int count = 0;
	
//	for(aux = h->first; aux!= NULL; aux = aux->next){
	while(count < size(h)){
		for(aux = h->first; aux != NULL; aux = aux->next){
			if(aux->nome[0] == letra){
				print(aux);
				count++;
			}
		}		
		letra++;
	}
		
}

int main(){
	
	head h;
	h.first = NULL;
	h.last = NULL;

	insert_ordenado(&h, 30, "José");
	insert_ordenado(&h, 25, "Cleonice");
	insert_ordenado(&h, 50, "Marcelo");
	insert_ordenado(&h, 45, "Bruna");
	insert_ordenado(&h, 45, "Matilda");

	printf("Imprimindo a lista que foi inserida\n");
	print_ordenado(&h);	
	printf("\n");

	printf("Deletando Matilda da lista!\n");
	delete_list(&h, 45, "Matilda");
	print_ordenado(&h);
	printf("\n");
	
	printf("Mínimo da lista:\n");
	print(min_list(&h));
	printf("\n");
		
	printf("Sucessor de Marcelo (50 anos)\n");
	print(sucessor(&h, 50));
	printf("\n");

	
	return 0;
	}
	
	
	
	
	
	
	
	
	
	
	
