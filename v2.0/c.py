t = int(input())
for _ in range(t):
    n = int(input())
    if n < 10:
        print(n)
    else:
        res = 9
        i = 10
        while (n // i) >= 10:
            res += 9
            i *= 10
        for j in range(n - n%10, n+1):
            if len(set(list(str(j)))) == 1:
                res += 1
        res += (n // i) - 1
        
        print(res)  
         