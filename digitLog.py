for _ in range(int(input())):
    n = int(input())
    a = [int(i) for i in input().split(" ")]
    b = [int(i) for i in input().split(" ")]
    mp1 = dict()
    mp2 = dict()
    for i in a:
        if i in mp1:
            mp1[i] += 1
        else:
            mp1[i] = 1
    for i in b:
        if i in mp1:
            mp1[i] += 1
        else:
            mp1[i] = 1
    print(mp1)