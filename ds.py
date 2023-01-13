for _ in range(int(input())):
    n = int(input())
    arr = []
    s = set()
    for _ in range(n):
        x = input()
        s.add(x)
        arr.append(x)
    for i in range(n):
        found = False
        for j in range(1, len(arr[i])):
            l = arr[i][:j]
            r = arr[i][j:]
            if l in s and r in s:
                found = True
                break
        if found:
            print(1, end="")
        else:
            print(0, end="")
    print()