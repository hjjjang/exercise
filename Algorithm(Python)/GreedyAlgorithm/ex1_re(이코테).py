## 1이 될 때까지 ##

n, k = map(int, input().split())

result = 0
while True: #break 전까지
    target = (n // k) * k
    result += (n-target)
    n = target
    if n < k:
        break
    result +=1
    n //= k

result += (n-1)
print(result)



