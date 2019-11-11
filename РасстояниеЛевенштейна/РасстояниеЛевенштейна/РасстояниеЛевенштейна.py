A = input()
B = input()
n = len(A)
m = len(B)
F = [[0] * (m + 1) for i in range(n + 1)]
for i in range(n + 1):
    F[i][0] = i
for j in range(m + 1):
    F[0][j] = j
for i in range(1, n + 1):
    for j in range(1, m + 1):
        #if A[i - 1] == B[j - 1]:
         #   F[i][j] = F[i - 1][j - 1]
        #else:
            F[i][j] = min(F[i - 1][j] + 1, F[i][j - 1] + 1, F[i - 1][j - 1] + int(A[i - 1] != B[j - 1]))
        #F[i][j] = min(F[i][j], F[i - 1][j - 1] + int(A[i - 1] != B[j - 1]))
print(F[n][m])
