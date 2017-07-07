#include<stdio.h>
#include<stdlib.h>

typedef struct nodo{
	int key;
	struct nodo * next;	
} nodo;

typedef struct head{
	nodo * first, * last;
} head;

typedef struct hashTable{
	head ** table;
	int size;
} hash;

//inicia a cabeça
head * head_start(){
	head * new = malloc(sizeof(head));
	new->first = new->last = NULL;
	
return new;
}

//insere a chave na lista apontada pela cabeça h
void insert_nodo(head * h, int key){
	nodo * new = malloc(sizeof(nodo));
	
	new->key = key;
	new->next = NULL;
	
	//se h->first não é nulo
	if(h->first){
		h->last->next = new;
	}
	
	else{
		h->first = new;
	}
	
	h->last = new;	
}

//inicia a hash
hash * hash_start(int v){
	hash * new_hash = malloc(sizeof(hash));
	
	new_hash->size = v;
	
	//cria um vetor para ponteiros de cabeça
	new_hash->table = malloc(sizeof(head)*v);
	
	for(int i=0; i<v; i++){
		new_hash->table[i] = head_start();
	}

return new_hash;	
	
}

void insert_hash(hash * h, int key){
	int i = key % h->size;	//posição da chave key na tabela
	insert_nodo(h->table[i], key);
}

nodo * search_list(head * h, int key){
	nodo * aux = h->first;
	
	while(aux){
		if(aux->key == key){
			break;
		}
		aux = aux->next;
	}	
	return aux;	
}

void hash_search(hash * h, int key){
	int i = key % h->size;
	
	nodo * s = search_list(h->table[i], key);
	
	if(s){
		printf("Key: %d\n", key);
	}	
	
	else{
		printf("There's no key %d\n");
	}
}




int main(){
	hash * h = hash_start(47);
	
	insert_hash(h, 10);
	insert_hash(h, 150);
	insert_hash(h, 101);
	insert_hash(h, 15340);
	insert_hash(h, 140);	
	insert_hash(h, 17560);		
	insert_hash(h, 1340);	
	insert_hash(h, 180);

	hash_search(h, 1530);
	hash_search(h, 1510);
	hash_search(h, 180);
	hash_search(h, 150);
	
return 0;
}	
	

