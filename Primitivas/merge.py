def mergesort(l):
    print("Entrei", l)
    if len(l) <= 1:
        return l

    l_temp = []
    for i in range(len(l)//2):
        x = l.pop()
        l_temp.append(x)
        
    l1 = mergesort(l)
    l2 = mergesort(l_temp)

    l3 = []

    print("divididos =>", l1, l2)
    while l1 and l2: # enquanto nenhuma das listas estiver vazia
        if l1[0] < l2[0]:
            x = l1.pop(0)
            l3.append(x)
        else:
            x = l2.pop(0)
            l3.append(x)
    for x in l1:
        l3.append(x)
    for x in l2:
        l3.append(x)
    print("merge =>", l3)

    return l3


test = [4 , 3, 6, 1, 10]
print(test)
print(mergesort(test))
