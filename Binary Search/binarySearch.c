#include<stdio.h>

int main(){

	int n = 1;
	
		scanf("%d", &n);
		
		int f = 1, l = (n/2), mid;
		
		while(f<=l){
			
			mid = f + (l-f)/2;
			
			if(mid*mid==n){
				break;
				}
				
			else if(mid*mid > n){
				l = mid-1;			
				}
			
			else{
				f = mid+1;
				}		
			}						

	printf("Raiz de %d = %d\n", n, mid);
				
	return 0;
		
	}
	

