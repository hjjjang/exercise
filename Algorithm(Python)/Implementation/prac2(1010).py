## 다리 놓기 ##

# from itertools import combinations # 시간초과

t = int(input())

def factorial(n):
    a = 1
    for i in range(1,n+1):
        a *= i
    return a
def combination(n,r):
    return factorial(n)//(factorial(r)*factorial(n-r))

for _ in range(t):
    n, m = map(int, input().split())
    result = combination(m,n)
    print(result)
