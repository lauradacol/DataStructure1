#include<stdio.h>
#include<stdlib.h>

//estrutura do nodo da lista
typedef struct list{
	int id;
	struct list * next, * prev;
}list;

//estrutura da cabeça
typedef struct head{
	list * first, * last;
}head;

//insere no ultimo da lista
void insert_lista(head * h, int x){
	list * nodo = malloc(sizeof(list));
	
	nodo->id = x;
	nodo->next = NULL;
	
	if(h->first == NULL){
		h->first = nodo;
		}
		
	else{
		h->last->next = nodo;
		}
		
	nodo->prev = h->last;
	h->last = nodo;
		
	}

//Printa a lista
void print_lista(head * h){
	list * aux;
	
	for(aux = h->first; aux != NULL; aux = aux->next){
		printf("%d\n", aux->id);
		}		
	}

void printNodo(head * h, int x){
	list * aux;
		
	for(aux = h->first; aux!=NULL; aux = aux->next){
		if(aux->id = x){
			break;
		}
	}
	printf("%d\n", aux->id);	
}

/*
void swap(head * h, list * a, list * b){
	list *b_prev, *b_next, *a_prev, *a_next;
	list *b_prev_next, *b_next_prev, *a_prev_next, *a_next_prev;
	
	a->prev = a_prev;
	a->next = a_next;
	b->prev = b_prev;
	b->next = b_next;
	
	b->prev->next = b_prev_next;
	b->next->prev = b_next_prev;
	a->prev->next = a_prev_next;
	a->next->prev = a_next_prev;
	

	//b sendo o último
	if(b->next == NULL){
		a->next = NULL;		

		a->prev = b_prev;
		b->prev = a_prev;
		b->next = a_next;

		}
	
	//a sendo o primeiro
	if(a->prev == NULL){
		b->prev = NULL;

		a->prev = b_prev;
		a->next = b_next;
		b->next = a_next;		
		
		}
	
	//a antecedendo b
	if(a->next == b){
		a->next = b_next;
		b->prev = a_prev;
		
		a->prev = b_prev;
		b->next = a_next;
				
		}
	
	//caso normal
	else{
		a->prev = b_prev;
		a->next = b_next;
		b->prev = a_prev;
		b->next = a_next;		
		}	
			
	}*/

list * findList(head * h, int x){
	list * aux;
	
	
	for(aux = h->first; aux!=NULL; aux = aux->next){
		if(aux->id == x){
			break;
		}
	}	
	return aux;
}

void swap(list * a, list * b){
	int id_a, id_b;
	
	id_a = a->id;
	id_b = b->id;

	b->id = id_a;
	a->id = id_b;
	
	}

/*
void insertion_sort(head * h){
	list *i, *j;
	
	for(i = h->first; i != NULL; i = i->next){
		j = i->next;
		
		while((j!= NULL) && (j->id < j->prev->id)){
			swap(h, j, j->prev);
			j = j->next;	
			}
		}
	}*/
	


int main(){
	
	head h;
	h.first = NULL;
	h.last = NULL;
	
	insert_lista(&h, 5);
	insert_lista(&h,1);
	insert_lista(&h,3);
	insert_lista(&h,2);	
	print_lista(&h);
	printf("\n");
	
	list *a = findList(&h, 5);
	list *b = findList(&h, 2);
	swap(a, b);
	print_lista(&h);
	
	return 0;
	}
	
	
