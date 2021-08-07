## 곱하기 혹은 더하기 ##

s = [int(i) for i in input()]

result = 0
for i in s:
    if i <= 1 or result <=1:
        result += i
    else:
        result *= i

print(result)