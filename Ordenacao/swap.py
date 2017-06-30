def swap(l, i, j):
	aux = l[i]
	l[i] = l[j]
	l[j] = aux
		
def split(l, inicio, fim):
	#Posição do vetor
	iPivo = inicio
	
	#Pivo
	pivo = l[iPivo]

	#Final do vetor
	a = fim
	
	for n in range(iPivo+1, (a+1)):
		
		if(l[n] < pivo):
			iPivo+=1
			swap(l, n, iPivo)

	swap(l, inicio, iPivo)

	return iPivo


def quickSort(l, i, j):
	iPivo = split(l, i, j)

	#if(i != iPivo):	
	#	quickSort(l,i,iPivo)
	
	if(iPivo != j):
		quickSort(l, iPivo, j)
	
	
	print(l)

	

l = [5,3,2,8,9,1,0,7]
quickSort(l, 0,7)
print(l)















