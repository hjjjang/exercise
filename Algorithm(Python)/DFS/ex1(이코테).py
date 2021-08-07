### DFS 소스코드 ###

# graph: 각 노드가 연결된 정보
# v: 현재 노드
# visited: 각 노드가 방문된 정보
def dfs(graph, v, visited):
    visited[v] = True
    print(v, end=' ')
    for i in graph[v]: #현재 노드와 연결된 노드 중
        if not visited[i]:
            dfs(graph, i, visited)


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

dfs(graph, 1, visited)
