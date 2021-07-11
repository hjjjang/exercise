## 모험가 길드 ##

n = int(input())
score = list(map(int, input().split()))
score.sort(reverse=True)

result = 0
for i in score:
    if i > len(score):
        break
    score = score[i:]
    result+=1

print(result)
