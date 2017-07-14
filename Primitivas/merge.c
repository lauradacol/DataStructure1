/*
 * Implemente a função de merge para dois vetores. Considere que as 
 * chaves  de ambos os vetores estão ordenadas. No final do algoritmo, 
 * as chaves de ambos os vetores devem estar ordenadas em um array 
 * auxiliar.
 */

#include<stdio.h>
#include<stdlib.h>

void merge(int v1[], int v2[], int v3[]){
	int i=0, j=0, c=0;
	
	while(c<10){
		if(v1[i] < v2[j]){
			v3[c] = v1[i];
			i++;
			c++;	
		}
		if(v2[j] < v1[i]){
			v3[c] = v2[j];
			j++;
			c++;	
		}
	}
}

void swap(int v[], int i, int j){
	int aux = v[i];
	v[i] = v[j];
	v[j] = aux;
}

int split(int v[], int begin, int end){
	int pivo = v[begin];
	int i = 1;
	
	for(int j=begin+1; j<end; j++){
		if(v[j] < pivo){
			swap(v, i, j);
			i++;
		}
	}
	swap(v, begin, (i-1));

return i;	
}

void quickSort(int v[], int begin, int end){
	while(begin!=end){
		int i = split(v, begin, end);
		quickSort(v, 0, (i-1));
		quickSort(v, i+1, end);  	
	}
}

int main(){
	int v1[6] = {2,4,-7,-3,7,-2};

	quickSort(v1, 0, 6);

	for(int i=0; i<6; i++){
		printf("%d\n", v1[i]);
	}
	
}













