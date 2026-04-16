import sys
sys.setrecursionlimit(10**6)

def dfs(x,y):
    visited[x][y] = True
    global cnt

    if graph[x][y] == 'P':
        cnt += 1
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0<=nx<n and 0<=ny<m and not visited[nx][ny]:
            if graph[nx][ny] != "X":
                dfs(nx, ny)
    



n, m = map(int, sys.stdin.readline().split(" "))

dx = [-1, 0, 1, 0] # 위 좌 아래 오
dy = [0, -1, 0, 1] 

cnt = 0
graph = []
visited = [ [False] * m for _ in range(n)]

for _ in range(n):
    graph.append(list(sys.stdin.readline().rstrip()))

for i in range(n):
    for j in range(m):
        if graph[i][j] == "I":
            dfs(i,j)

if cnt==0:
    print("TT")
else:
    print(cnt)