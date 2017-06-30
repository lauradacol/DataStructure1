#include<stdio.h>
#include<stdlib.h>

typedef struct list{
	int num;
	struct list *prev,*next;
}list;
typedef struct head{
	struct list *first, *last;
}head;

void swap(head *cabeca, list *maior, list *menor){
	list *aux,*aux2,*aux3,*aux4;
	aux2=maior->next;
	aux=menor->prev;
	if(maior->prev!=NULL && menor->next!=NULL){
		aux4=menor->next;
		aux3=maior->prev;
		if(aux2!=aux){
			if(maior->next!=menor){
				menor->next=aux2;
				aux2->prev=menor;
				maior->prev=aux;
				aux->next=maior;
				maior->next=aux4;
				aux4->prev=maior;
				menor->prev=aux3;
				aux3->next=menor;
			}else{
				maior->next=menor->next;
				menor->prev=maior->prev;
				maior->prev=menor;
				menor->next=maior;
			}
		}else{
			maior->next=menor->next;
			menor->prev=maior->prev;
			menor->next=aux;
			maior->prev=aux;
			aux->prev=menor;
			aux->next=maior;
			aux3->next=menor;
			aux4->prev=maior;
		}
	}else if(maior->prev==NULL && menor->next==NULL){
		if(aux2!=aux){
			if(maior->next!=menor){
				menor->prev=maior->prev;
				maior->prev=aux;
				maior->next=menor->next;
				menor->next=aux2;
				cabeca->first=menor;
				cabeca->last=maior;
				aux2->prev=menor;
				aux->next=maior;
			}else{
				maior->next=menor->next;
				menor->prev=maior->prev;
				maior->prev=menor;
				menor->next=maior;
				cabeca->first=menor;
				cabeca->last=maior;
			}
		}else{
			maior->next=menor->next;
			menor->prev=maior->prev;
			menor->next=aux;
			maior->prev=aux;
			aux->prev=menor;
			aux->next=maior;
			cabeca->first=menor;
			cabeca->last=maior;
		}
	}else if(maior->prev==NULL){
		aux4=menor->next;
		if(aux2!=aux){
			if(maior->next!=menor){
				menor->next=aux2;
				aux2->prev=menor;
				maior->prev=aux;
				aux->next=maior;
				maior->next=aux4;
				aux4->prev=maior;
				cabeca->first=menor;
			}else{
				aux4=menor->next;
				maior->next=menor->next;
				menor->prev=maior->prev;
				maior->prev=menor;
				menor->next=maior;
				aux4->prev=maior;
				cabeca->first=menor;
			}
		}else{
			maior->next=menor->next;
			menor->prev=maior->prev;
			menor->next=aux;
			maior->prev=aux;
			aux->prev=menor;
			aux->next=maior;
			aux4->prev=maior;
			cabeca->first=menor;
		}
	}else if(menor->next==NULL){
		aux3=maior->prev;
		if(aux2!=aux){
			if(maior->next!=menor){
				maior->next=menor->next;
				menor->next=aux2;
				aux2->prev=menor;
				maior->prev=aux;
				aux->next=maior;
				aux3->next=menor;
				menor->prev=aux;
				cabeca->last=maior;
			}else{
				maior->next=menor->next;
				menor->prev=maior->prev;
				maior->prev=menor;
				menor->next=maior;
				aux3->next=menor;
				cabeca->last=maior;
			}
		}else{
			maior->next=menor->next;
			menor->prev=maior->prev;
			menor->next=aux;
			maior->prev=aux;
			aux->prev=menor;
			aux->next=maior;
			aux3->next=menor;
			cabeca->last=maior;
		}
	}
}
void inserir(head *cabeca,int num){

	list *novo=malloc(sizeof(list));
	novo->num=num;
	if(cabeca->first==NULL){
		novo->next=NULL;
		novo->prev=NULL;
		cabeca->first=novo;
		cabeca->last=novo;
	}else{
		cabeca->first->prev=novo;
		novo->next=cabeca->first;
		novo->prev=NULL;
		cabeca->first=novo;
	}
}
void printar(head *cabeca){
	list *aux=cabeca->first;
	for(;aux!=NULL;aux=aux->next)
		printf("\n%d\n", aux->num);
}

void main() {
	head *cabeca=malloc(sizeof(head));
	cabeca->first=NULL;
	cabeca->last=NULL;
	inserir(cabeca,0);
	inserir(cabeca,2);
	inserir(cabeca,1);
	inserir(cabeca,5);
	inserir(cabeca,3);
	inserir(cabeca,4);
	printar(cabeca);
	swap(cabeca,cabeca->last->prev,cabeca->last);
	printf("---------------------------------------------------------" );
	printar(cabeca);

}
