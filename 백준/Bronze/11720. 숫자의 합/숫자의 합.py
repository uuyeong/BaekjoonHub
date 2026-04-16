import sys


n = int(input())
list = list(input())
sum = 0

for i in range(n) :
    sum += int(list[i])

print(sum)