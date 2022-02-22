def nbDiv(n):
    ans = 1
    for i in range(1, (n // 2) + 1):
        if n % i == 0:
            ans += 1
    return ans
a, b, c = [int(i) for i in input().split(" ")]
ans = 0
s = {}
for i in range(1, a+1):
    for j in range(1, b+1):
        for k in range(1, c+1):
            d = i*j*k
            if d in s:
                ans += s[d]
            else:
                d_ = nbDiv(d)
                ans += d_
                s[d] = d_
print(ans)