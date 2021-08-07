## 상하좌우 ##

n = int(input())
path = list(input().split())

choice = ['L','R','U','D']
dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]

x, y = 1, 1
for step in path:
    for i in range(4):
        if step==choice[i]:
            if 0<x+dx[i]<=n and 0<y+dy[i]<=n:
                x += dx[i]
                y += dy[i]

print(x, y)
