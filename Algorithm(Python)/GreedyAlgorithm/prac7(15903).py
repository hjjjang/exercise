## 카드 합체 놀이 ##

n, m = map(int, input().split())
a = list(map(int, input().split()))

for _ in range(m):
    a.sort()
    a[0] = a[1] = a[0] + a[1]

print(sum(a))
