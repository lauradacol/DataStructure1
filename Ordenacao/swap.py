def swap(l, i, j):
	aux = l[i]
	l[i] = l[j]
	l[j] = aux
		
def split(l):
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

	return iPivo


def quickSort(l, i, j):
	
	



l = [5,3,2,8,9,1,0,7]
print("L antes:")
print(l)
split(l)
print("L depois:")
print(l)
