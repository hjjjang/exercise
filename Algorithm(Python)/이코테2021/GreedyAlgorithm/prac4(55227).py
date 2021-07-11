## 동전 0 ##

n, k = map(int, input().split())
value = [int(input()) for _ in range(n)]
value.sort(reverse=True)

result = 0
for coin in value:
    result += k//coin
    k = k%coin

print(result)
