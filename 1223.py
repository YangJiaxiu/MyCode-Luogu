class People(object):
    def __init__(setf, num, timePeo):
        setf.num = num
        setf.timePeo = timePeo

def not_empty(s):
    return s and s.strip(" ") 

n = int(input())

people = list(filter(not_empty, input().split(" "))) 
people = list(map(People, range(1, n + 1), list(map(int, people) )))

people.sort(key = lambda x: x.timePeo)

for i in people:
    print(i.num, end = " ")

print(end = "\n")

ans = 0
ite = 0
while ite < n:
    ans += people[ite].timePeo * (n - ite - 1)
    ite += 1

print("{:.2f}".format(ans / n))