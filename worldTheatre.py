def nCr(n, r):
    return (fact(n) // (fact(r)
                * fact(n - r)))
def fact(n):
    res = 1
    for i in range(2, n+1):
        res = res * i
         
    return res

n, m, t = map(int, input().split(" "))
ans = 0
for i in range(4, t):
    ans += nCr(n, i) * nCr(m, t-i)
print(ans)