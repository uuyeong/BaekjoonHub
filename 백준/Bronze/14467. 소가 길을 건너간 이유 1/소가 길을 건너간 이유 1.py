import sys

N = int(input())
where = dict()
count = dict()

for i in range(N):
    cow, road = map(int, input().split())
    if cow in count.keys():
        if where[cow] != road :
            count[cow] += 1
            where[cow] = road
        else :
            continue
    else :
        where[cow] = road
        count[cow] = 0
    
sum = 0
for i in count.values():
    sum += i

print(sum)