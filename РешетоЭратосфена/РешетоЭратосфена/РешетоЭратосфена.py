def IsPrime(n):
    if n % 2 == 0:
        return n == 2
    d = 3
    while d * d <= n and n % d != 0:
       d += 2
    return d * d > n

IsPrime = [True] * (n + 1)
IsPrime[0] = False
IsPrime[1] = False
d = 2
while d * d <= n:
    if IsPrime[d]:
        for i in range(d * d, n + 1, d):
            IsPrime[i] = False
    d += 1  