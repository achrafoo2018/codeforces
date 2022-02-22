import math
t = int(input())
for _ in range(t):
    n = int(input())
    a = [int(i) for i in input().split(" ")]
    b = sorted(range(len(a)), key=lambda k: a[k], reverse=True)
    res = [0] * (n+1)
    r, ans, tmp, tmp2 = [1, 0, 1, 1]
    for i in range(len(a)):
        res[b[i]+1] = tmp * r
        r *= -1
        ans += 2 * abs(tmp) * a[b[i]]
        if tmp2 % 2 == 0:
            tmp += 1
        tmp2 += 1
    print(ans)
    print(*res, sep=" ")

