n, t = [int(i) for i in input().split(" ")]
arr = [int(i) for i in input().split(" ")]
def check(mid):
    res = 0
    for i in range(n):
        res += mid // arr[i]
    return res >= t
l, r = 1, 10**16+7
ans = t
while l <= r:
    mid = (l+r) // 2
    if check(mid):
        ans = mid
        r = mid-1
    else:
        l = mid+1
print(ans)