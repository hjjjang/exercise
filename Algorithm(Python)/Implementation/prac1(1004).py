## 어린 왕자 ###

t = int(input())
for _ in range(t):
    x1, y1, x2, y2 = map(int, input().split()) #어린왕자 출발점, 도착점
    n = int(input()) #행성계의 개수
    info = [list(map(int, input().split())) for _ in range(n)]

    cnt = 0
    for i in info:
        if ((i[0]-x1)**2 + (i[1]-y1)**2 < i[2]**2) and ((i[0]-x2)**2 + (i[1]-y2)**2 > i[2]**2):
            cnt+=1
        elif ((i[0]-x1)**2 + (i[1]-y1)**2 > i[2]**2) and ((i[0]-x2)**2 + (i[1]-y2)**2 < i[2]**2):
            cnt+=1
        ## 두 점 모두 원 안에 있으면 X
    print(cnt)
