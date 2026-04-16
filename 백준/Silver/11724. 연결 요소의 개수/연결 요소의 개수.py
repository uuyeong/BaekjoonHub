import sys

def dfs(start):
    visited[start] = True
    stack = [start]

    while stack:
        curr = stack.pop()
        for i in graph[curr]:
            if not visited[i]:
                visited[i] = True
                stack.append(i)

N, M = map(int, sys.stdin.readline().split(" "))
 
graph = [ [] for i in range(N+1)]
visited = [False] * (N + 1)

for i in range(M):
    u, v = map(int, sys.stdin.readline().split(" "))
    graph[u].append(v)
    graph[v].append(u)
    
count = 0

for i in range(1, N+1):
    if not visited[i]:
        dfs(i)
        count += 1

print(count)