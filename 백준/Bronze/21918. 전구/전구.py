import sys

N, M = map(int, input().split())

stat = sys.stdin.readline().rstrip().split(" ")
for i in range(N):
    stat[i] = int(stat[i])

for i in range(M):
    text = sys.stdin.readline().rstrip().split(" ")
    a = int(text[0])
    b = int(text[1])
    c = int(text[2])
    if a == 1:
        stat[b-1] = c
    elif a == 2:
        for i in range(b-1, c):
            if stat[i]==0 : stat[i]=1
            else : stat[i]=0
    elif a == 3:
        for i in range(b-1, c):
            stat[i] = 0
    elif a == 4:
        for i in range(b-1, c):
            stat[i] = 1

print(" ".join(map(str, stat)))