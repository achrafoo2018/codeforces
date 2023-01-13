for _ in range(int(input())):
    n, l = map(int, input().split(" "))
    arr = [str(bin(int(i)))[2:] for i in input().split(" ")]
    for i in range(n):
        arr[i] = ('0' * (l-len(arr[i]))) + arr[i]
    ans = ""
    for i in range(l):
        z, o = 0, 0
        for j in range(n):
            if arr[j][i] == '0':
                z +=1
            else:
                o += 1
        ans += "1" if o > z else "0"
    print(int(ans, 2))
