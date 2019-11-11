def merge(A, B):
    Res = []
    i = 0
    j = 0
    while i < len(A) and j < len(B):
        if A[i] <= B[j]:
            Res.append(A[i]) 
            i += 1 
        else:
            Res.append(B[j]) 
            j += 1 
    Res += A[i:] + B[j:] 
    return Res

def MergeSort(A): 
    if len(A) <= 1: 
        return A 
    else:
        L = A[:len(A) // 2] 
        R = A[len(A) // 2:] 
    return merge(MergeSort(L), MergeSort(R))
