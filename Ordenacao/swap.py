def swap(l, i, j):
	aux = l[i]
	l[i] = l[j]
	l[j] = aux
		
def quickSort(l):
	#Posição do vetor
	iPivo = 0
	
	#Pivo
	pivo = l[iPivo]

	#Final do vetor
	a = len(l)-1
	
	for n in range(1, a):
		
		if(l[n] < pivo):
			iPivo+=1
			swap(l, n, iPivo)

	swap(l, 0, iPivo)


l = [5,3,2,8,9,1,0,7]
print("L antes:")
print(l)
quickSort(l)
print("L depois:")
print(l)
