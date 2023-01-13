mod = 10**9 + 7
t = int(input())
for _ in range(t):
    n, m = [int(i) for i in input().split(" ")]
    ans = 0
    for i in range(m):
        l, r, x = [int(i) for i in input().split(" ")]
        ans |= x
    print((pow(2, n-1, mod) * ans) % mod)