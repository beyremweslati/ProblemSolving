
def merge(A,B):
    C = []
    ia = 0
    ib = 0
    while(ia < len(A) and ib < len(B)):
        if (A[ia] > B[ib]):
            C.append(B[ib])
            ib += 1
        else:
            C.append(A[ia])
            ia += 1
    for i in range(ia,len(A)):
        C.append(A[i])
    for i in range(ib,len(B)):
        C.append(B[i])
    return C
    
def MergeSort(A):
    if len(A) == 1:
        return A
    arrayOne = A[:len(A)//2]
    arrayTwo = A[len(A)//2:]

    arrayOne = MergeSort(arrayOne)
    arrayTwo = MergeSort(arrayTwo)

    return merge(arrayOne,arrayTwo)



T = [3,9,4,6,3,1,2,7,9,12,64,97,21,21,20,11,12,1,0,4,9,120,45,26,35,94,75]
T = MergeSort(T)
print(T)