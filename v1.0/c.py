t = int(input())
for _ in range(t):
    n = int(input())
    c = 10
    res = []
    while n > 0:
        if n % 10 != 0:
            x = n % 10
            res.append(x * (c//10))
        c *= 10
        n //= 10
    print(len(res))
    print(*res)
    