t = int(input())
for _ in range(t):
    n, k = [int(i) for i in input().split()]
    res = 0
    i = 1
    n -= 1
    while n > 0:
        res += 1
        n -= i
        if i*2 <= k:
            i *= 2
        else:
            break
    if n > 0:
        if n % i != 0:
    
            res += (n // i)
    print(res)