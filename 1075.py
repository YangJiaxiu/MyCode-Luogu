import math

def isprime(x):
    if x == 1:
        return False
    if x == 2:
        return True
    for i in range(3, int(math.sqrt(x))):
        if x % i == 0:
            return False
    return True

n = int(input())
for i in range(1, n + 1):
    if isprime(i) & (n % i == 0):
        print(n // i)
        exit()