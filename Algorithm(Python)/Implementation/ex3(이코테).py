## 왕실의 나이트 ##

pos = input()

x, y = pos[0], int(pos[1])

xlist = ['a','b','c','d','e','f','g','h']
ylist = list(range(1,9))
for i in range(len(xlist)):
    if x==xlist[i]:
        x=i+1

dx = [2,2,-2,-2,1,-1,1,-1]
dy = [1,-1,1,-1,2,2,-2,-2]

cnt = 0
for i in range(8):
    if 0<x+dx[i]<=8 and 0<y+dy[i]<=8:
        cnt+=1

print(cnt)
