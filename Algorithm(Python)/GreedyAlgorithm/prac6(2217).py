## 로프 ##

n = int(input())
weight = [int(input()) for _ in range(n)]
weight.sort()

max = max(weight)

for i in range(n):
    new =  weight[i]*(n-i)
    if new > max:
        max = new

print(max)
