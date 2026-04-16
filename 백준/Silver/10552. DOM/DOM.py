import sys

def dfs(start):
    count = 0
    curr = start
    while True :

        if channel[curr] == 0:
            return count
        
        if visited[curr] :
            return -1
        
        visited[curr] = True
        curr = channel[curr]
        count +=1
        
        



N, M, P = map(int, sys.stdin.readline().split())

visited = [False] * (M + 1)
channel = [0] * (M + 1)

for i in range(N):
    favor, hate = map(int, sys.stdin.readline().split())
    if channel[hate] == 0:
        channel[hate] = favor

result = dfs(P)

print(result)