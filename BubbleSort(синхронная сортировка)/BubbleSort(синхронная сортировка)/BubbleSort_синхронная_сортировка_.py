def BubbleSort(A, B):
     for j in range(len(A) - 1, 0, -1):
        for i in range(0, j):
            if A[i] > A[i + 1]:
                A[i], A[i + 1] = A[i + 1], A[i]
                B[i], B[i + 1] = B[i + 1], B[i]
A = [4, 2, 5, 1]
B = ['Liza', 'Ivan', 'Andrey','Kolya']
BubbleSort(A, B)


def BubbleSort(A):
     for j in range(len(A) - 1, 0, -1):
        for i in range(0, j):
            if A[i][0] > A[i + 1][0]: #сравниваем не кортежи целиком, а только ключи
                A[i], A[i + 1] = A[i + 1], A[i]
A = [(4,'Liza'), (2,'Ivan'), (5,'Andrey'), (1,'Kolya')]
BubbleSort(A)


N = int(input())
A = []
for k in range(N):
    name, phone = input().split()
    A.append((name, int(phone)))
for j in range(len(A)-1, 0, -1):
    for i in range(j):
        if A[i][0] > A[i+1][0] \
          or A[i][0] == A[i+1][0] and A[i][1] > A[i+1][1]:
            A[i], A[i+1] = A[i+1], A[i]
for k in range(N):
    name, phone = A[k]
    print(name, phone)