import sys

T = int(input())
for _ in range(T):
    text = sys.stdin.readline().rstrip()
    count = dict()

    for i in text :
        if i == " " :
            continue
        elif i not in count.keys() :
            count[i] = 1
        else :
            count[i] += 1        
        
    result = list(count.values())
    result.sort(reverse = True)
    result.append(-1)
    if result[0] == result[1] :
        print("?")
    else :
        for i in count.keys():
            if count[i] == result[0]:
                print(i)

