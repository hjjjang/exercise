### 신입 사원 ###
# 숫자가 작을수록 성적이 높음

import sys

t = int(input())

for _ in range(t):
    n = int(input())
    score = [list(map(int,sys.stdin.readline().split())) for _ in range(n)]
    score.sort(key=lambda x: x[0])

    result=1
    min = score[0][1]
    for i in range(1,n):
        if score[i][1] < min:
            min = score[i][1]
            result +=1

    print(result)
