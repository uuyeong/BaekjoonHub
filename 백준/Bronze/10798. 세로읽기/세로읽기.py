import sys

a = list()
res = list()
big_len = -1
for i in range(5):
    text = sys.stdin.readline().rstrip()
    l = len(text)
    if l > big_len:
        big_len = l
    a.append(text)


for k in range(big_len):
    for i in a :
        if len(i) <= k :
            continue
        else :
            res.append(i[k])

print("".join(res))