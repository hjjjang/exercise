### BFS 소스코드 ##

from collections import deque

# graph: 각 노드가 연결된 정보
# start: 시작 노드
# v: 현재 노드
# visited: 각 노드가 방문된 정보
def bfs(graph, start, visited):
    queue = deque([start]) # 시작 노드를 큐에 넣기
    visited[start] = True # 현재 노드 방문 처리
    while queue: #큐가 빌 때까지 반복
        v = queue.popleft() # 큐에서 하나의 원소를 뽑아 출력
        print(v, end=' ')
        for i in graph[v]:
            if not visited[i]:
                queue.append(i)
                visited[i]=True
                
graph = [
    [], #index=0은 비워두기
    [2,3,8],
    [1,7],
    [1,4,5],
    [3,5],
    [3,4],
    [7],
    [2,6,8],
    [1,7]
]

visited = [False]*9

bfs(graph, 1, visited)
