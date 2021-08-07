## 문자열 재정렬 ##

s = list(input())

alpha = []
num = []

for text in s:
    try:
        num.append(int(text))
    except:
        alpha.append(text)

alpha.sort()
num.sort()
alpha.extend(num)

print("".join(str(x) for x in alpha))
