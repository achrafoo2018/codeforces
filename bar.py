import math
for _ in range(int(input())):
    n, k, b, s = [int(i) for i in input().split(" ")]
    ans = b * k
    if ans > s:
        print(-1)
        continue
    ans += min(k-1, s-ans)
    r = s - ans
    if n == 1 and r > 0 or n > 1 and math.ceil(r / (n-1)) >= k:
        print(-1)
        continue
    print(ans, end=" ")
    for i in range(n-1):
        print(min(r, k-1), end=" ")
        r = max(r-(k-1), 0)
    print()