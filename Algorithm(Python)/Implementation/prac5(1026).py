## 보물 ##

n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
a.sort(reverse=True)
b.sort()

mul = [a[i]*b[i] for i in range(n)]
print(sum(mul))

