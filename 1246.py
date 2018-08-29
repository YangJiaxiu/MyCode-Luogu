init = list(input().rstrip())
# ans = []
fuck = 0
base = 1
k = init.__len__() - 1
for i in range(init.__len__() - 1, -1, -1):
    fuck += (ord(init[i]) - ord('a') + 1 - k) * base;
    base *= 26
    k -= 1

print(fuck)