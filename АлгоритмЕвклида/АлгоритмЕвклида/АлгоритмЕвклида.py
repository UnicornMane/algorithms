def gcd(a, b): 
    while b:
            a = a % b
            a, b = b, a
        
    return max(a, b)