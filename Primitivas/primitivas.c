#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int x;
	struct node * next, * prev;
}node;

typedef struct head{
	node * first, * last;
}head;

/** Purpose: initializes the node with the value and set prev and next 
 * to null
 * @param int x. The value to be inserted in the node
 * @return node new. The newly created node with initialized values.
 * Worst-case Performance: O(1).
 */
node * initNode(int x){
	node * new = malloc(sizeof(node));
	new->x = x;
	new->next = NULL;
	new->prev = NULL;
	
return new;
}

/** Purpose: check is the list is empty.
 * @param head h. The list's head.
 * @return int bool. 1 if is empty, 0 if isn't.
 * Worst-case Performance: O(1).
 */
int isEmpty(head * h){
	int bool = 0;
	
	if(h->first == h->last && h->last == NULL){
		bool = 1;
	}
return bool;
}

/** Purpose: find the list's size;
 * @param head h. The list's head.
 * @return int size. The list's size.
 * Worst-case Performance: O(n).
 */
int size(head * h){
	node * aux;
	int size = 0;	
	for(aux=h->first; aux!=NULL; aux=aux->next){
		size++;
	}

return size;
}

/** Purpose: check if there is just one element in the list.
 * @param head h. The list's head.
 * @return int bool. 1 if there's one element, 0 if there's more than one.
 * Worst-case Performance: O(1).
 */
int oneElement(head * h){
	int bool = 0;
	if((h->first == h->last) && (isEmpty(h) == 0)){
		bool = 1;
	}

return bool;
}

/************************PRINT FUNCTIONS*******************************/
/** Purpose: print all list.
 * @param head. The list's head.
 * Worst-case Performance: O(n). 
 */
void printList(head * h){
	node * aux;
	for(aux = h->first; aux!=NULL; aux = aux->next){
		printf("%d\n", aux->x);
	}
}

/** Purpose: print a single node.
 * @param node n. The node to be printed.
 * Worst-case Performance: O(1).
 */
void printNode(node * n){
	if(n==NULL){
		printf("Node not found\n");
	}
	else{
		printf("%d\n", n->x);	
	}
}

/************************INSERT FUNCTIONS******************************/
/** Purpose: insert a node in the list's begin.
 * @param head h, int x. The list's head and the node's value.
 * Worst-case Performance: O(1).
 */
void insertBegin(head * h, int x){
	node * new = initNode(x);		
	
	if(isEmpty(h) == 1){
		h->first = h->last = new;
	}
	
	else{
		new->next = h->first;
		h->first->prev = new;
		h->first = new;	
	}
}

/** Purpose: insert a node in the list's end.
 * @param head h, int x. The list's head and the node's value.
 * Worst-case Performance: O(1).
 */
void insertEnd(head * h, int x){
	node * new = initNode(x);
	
	if(isEmpty(h) == 1){
		h->first = h->last = new;
	}
	
	else{
		new->prev = h->last;
		h->last->next = new;
		h->last = new;
	}
}

/** Purpose: insert a node in the list's middle, after a recieved node.
 * @param head h, int x. The list's head and the node's value.
 * Worst-case Performance: O(1).
 */
void insertMiddle(head * h, node * next, int x){
	node * new = initNode(x);
	new->next = next;
	new->prev = next->prev;
	next->prev->next = new;
	next->prev = new;
}

// Worst-case Performance: O(n)
void insertOrdered(head * h, int x){
	node * new = initNode(x);		
	node * aux;
		
	if(isEmpty(h) == 1){
		h->first = h->last = new;
	}	
	else{
		for(aux = h->first; aux!=NULL && aux->x < x; aux = aux->next){}
		
		if(aux == h->first){
			insertBegin(h, x);
		}
		
		else if(aux == NULL){
			insertEnd(h, x);
		}
		
		else{
			insertMiddle(h,aux,x);
		}		
	}
}

/*************************FIND FUNCTIONS*******************************/
/** Purpose: find a nodo by it's value
 * @param int x. Value to be found.
 * @return aux. The nodo, if it exists or NULL if it doesn't exist.
 * Worst-case Performance: O(n).
 */
node * findNode(head * h, int x){
	node * aux;
	
	for(aux = h->first; aux!=NULL; aux = aux->next){
		if(aux->x == x){
			break;
		}
	}	
return aux;
}

/************************REMOVE FUNCTIONS******************************/
/** Purpose: remove the first element in the list
 * @param head h. The list's head
 * @return int i. The removed node's value.
 * Worst-case Performance: O(1).
 */
int removeBegin(head * h){
	node * aux = h->first;
	int i = h->first->x;
	
	if(oneElement(h)==0){
		h->first->prev = NULL;
		h->first = aux->next;	
	}
	else{
		h->first = NULL;
		h->last = NULL;
	}
		
return i;	
}

/** Purpose: remove the last element in the list
 * @param head h. The list's head
 * @return int i. The removed node's value.
 * Worst-case Performance: O(1).
 */
int removeEnd(head * h){
	node * aux = h->last;
	int i = h->last->x;
	
	if(oneElement(h)==0){
		h->last->prev->next = NULL;
		h->last = aux->prev;	
	}
	else{
		h->first = NULL;
		h->last = NULL;
	}	
	free(aux);
return i;
}

/** Purpose: remove a given node
 * @param head h, node n. The list's head and a node to be removed.
 * @return int i. The removed node's value.
 * Worst-case Performance: O(1).
 */
int removeMiddle(head * h, node * n){
	node * aux;
	int i = n->x;
		
	if(h->first == n){
		return removeBegin(h);		
	}
	
	else if(h->last == n){
		return removeEnd(h);		
	}
	
	else{ 
		if(oneElement(h)==0){
			n->prev->next = n->next;
			n->next->prev = n->prev;
			free(n);
			return i;
			}
		else{
			h->first = NULL;
			h->last = NULL;			
		}
	}
}
/**********************************************************************/

/************************MIN AND MAX FUNCTIONS*************************/
/** Purpose: find the minimun value of the list by givin a frist node
 * @param node firstNode
 * @return node min
 * Worst-case Performance: O(n).
 */
node * min(node * firstNode){
	node * min = firstNode;
	node * aux = firstNode;
	
	while(aux != NULL){
		if(aux->x < min->x){
			min = aux;
		}
		aux = aux->next;
	}
return min;
}

/** Purpose: find the maximum value of the list by givin a frist node
 * @param node firstNode
 * @return node max
 * Worst-case Performance: O(n).
 */
node * max(node * firstNode){
	node * max = firstNode;
	node * aux = firstNode;
	
	while(aux != NULL){
		if(aux->x > max->x){
			max = aux;
		}
		aux = aux->next;
	}
return max;
}
/**********************************************************************/

/*************************FUNÇÃO SWAP**********************************/
/** Purpose: exchange the values of two nodes with each other.
 * @param head h, node a, node b whose values shall be exchanged.
 * Worst-case Performance: O(n).
 */
void swapCheat(head * h, node * a, node * b){
	int valA = a->x;
	int valB = b->x;
	
	b->x = valA;
	a->x = valB;		
}
/**********************************************************************/

/*************************INSERTION SORT*******************************/
/** Purpose: remove from a list and ordered insert in another.
 * @param head h.
 * COMPLEXIDADE NO PIOR CASO: O(n^2)
 */
void insertionSort(head * h){
	head h2;
	h2.first = NULL;
	h2.last = NULL;
	
	//n vezes
	while(isEmpty(h) == 0){
		//n vezes no pior caso
		insertOrdered(&h2,removeBegin(h));
	}
	
	h->first = h2.first;
	h->last = h2.last;
	
	
}
/**********************************************************************/

/**********************FUNÇÃO SELECTION SORT***************************/
/** Purpose: ordenate the list by finding the selection sorte method.
 * @param head h.
 * COMPLEXIDADE NO PIOR CASO: O(n^2)
 */
void selectionSort(head * h){
	node * aux = h->first;
	
	//n vezes
	while(aux!=NULL){
		//n vezes no pior caso
		swapCheat(h, aux, min(aux));
		aux = aux->next;
	}
}
/**********************************************************************/

/*************************FUNÇÃO MERGE SORT****************************/
/** Purpose: exchange the values of two nodes with each other.
 * @param head h, node a, node b whose values shall be exchanged.
 */

head * merge(head * h){
	/*Se está vazia, retornar o próprio h*/
	if(isEmpty(h)==1){
		return h;
	}
	
	/*Se tem apenas um elemento, retornar o próprio h*/
	if(oneElement(h)==1){
		return h;
	}
	
	else{
		/*Declara h2 que será a primeira metade da minha lista. h será 
		 * a segunda metade*/
		head * h2 = malloc(sizeof(head));
		int middle = size(h)/2;
		
		/*Até a metade da lista, retiro de h e insiro em h2 para dividir*/
		for(int i=0; i<middle; i++){
			insertBegin(h2, removeBegin(h));		
		}
		
		
		head * h3 = merge(h2);
		head * h4 = merge(h);
		
		head * hResult;
		
		/*Até que uma das listas esteja vazia, remover o menor primeiro 
		 * elemento e adicionar no final da hResult*/ 
		while(isEmpty(h3)==0 && isEmpty(h4)==0){			
			if(h3->first->x < h4->first->x){
				insertEnd(hResult, (removeBegin(h3)));
			}
			
			else if(h3->first->x > h4->first->x){
				insertEnd(hResult, (removeBegin(h4)));
			}
		
		/*A lista que sobrou, adicionar inteira no final do hResult
		 * Um dos for não vai entrar, pois uma das listas vai sair do
		 * while vazia*/
		for(node * aux3 = h3->first; aux3!=NULL; aux3 = aux3->next){
			insertEnd(hResult, (removeBegin(h3)));
		}
		
		for(node * aux4 = h4->first; aux4!=NULL; aux4 = aux4->next){
			insertEnd(hResult, (removeBegin(h4)));
		}
		
		return hResult;			
		}				 
	}
}




/**********************************************************************/


int main(){
	head h;
	h.first = NULL;
	h.last = NULL;
	
	printf("vazio: %d\n", isEmpty(&h));	
	insertBegin(&h, 1);
	insertBegin(&h, 8);				
	insertBegin(&h, 5);	
	insertBegin(&h, 4);		
	insertBegin(&h, 2);	
	insertBegin(&h, 7);		
	printList(&h);

	head * h3 = merge(&h);
	printf("\n");
	printList(h3);	
	
	
return 0;
}
