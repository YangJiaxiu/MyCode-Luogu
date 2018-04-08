def fac(x):
    if x == 0:
        return 1
    else:
        return x * fac(x - 1)

n = int(input())
ans = 0
for i in range(1, n + 1):
    ans = ans + fac(i)
print(ans)