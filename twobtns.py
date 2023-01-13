n, m = [int(i) for i in input().split(' ')]
if n >= m:
    print(n-m)
else:
    count = 0
    while m > n:
        if m % 2 == 0:
            m //= 2
            count += 1
        else:
            m += 1
            count += 1
    print(count + (n-m))
