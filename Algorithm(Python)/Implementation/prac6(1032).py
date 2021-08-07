## 명령 프롬프트 ##

n = int(input())
names = [input() for _ in range(n)]
name_len = len(names[0])
pattern = ''

for s in range(name_len):
    same = names[0][s]
    new_pattern = same
    for idx in range(1,n):
        if names[idx][s] != same:
            new_pattern="?"
    pattern += new_pattern

print(pattern)
