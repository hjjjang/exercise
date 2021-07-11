## ATM ##

n = int(input())
p = list(map(int, input().split()))
p.sort()

result = 0
for idx, time in enumerate(p):
    result += time*(n-idx)

print(result)
