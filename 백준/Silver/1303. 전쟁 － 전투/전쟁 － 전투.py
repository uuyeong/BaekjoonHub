import sys


def find(x, y, n, m):
    r = 0
    if( x-1>=0 and war[x-1][y] == war[x][y] ): # 상
        if not visited[x-1][y]:
            stack.append((x-1, y))
            visited[x-1][y] = True
            r = 1
    if( y+1<=n-1 and war[x][y+1] == war[x][y] ): # 우
        if not visited[x][y+1] :
            stack.append((x, y+1))
            visited[x][y+1] = True
            r = 1
    if( y-1>=0 and war[x][y-1] == war[x][y] ): # 좌
        if not visited[x][y-1]:
            stack.append((x, y-1))
            visited[x][y-1] = True
            r = 1
    if( x+1<=m-1 and war[x+1][y] == war[x][y]): # 하
        if not visited[x+1][y]:
            stack.append((x+1, y))
            visited[x+1][y] = True
            r = 1
    
    return r


n, m = map(int, sys.stdin.readline().split(" "))

# m이 행, n이 열

stack = []
visited = [ [False for _ in range(n)] for _ in range(m)]
war = []

W_count = 0
B_count = 0

for i in range(m):
    input = sys.stdin.readline().rstrip()
    input = list(input)
    war.append(input)

for i in range(m):
    for j in range(n):
        if not visited[i][j]: # 방문하지 않은 군인일 경우
            count = 0

            stack.append((i, j))
            visited[i][j] = True

            while(stack):
                row, col = stack.pop()
                count += 1
                find(row, col, n, m)
                
            if war[row][col] == 'W':
                W_count += count**2
            elif war[row][col] == "B":
                B_count += count**2




print(W_count, B_count)
