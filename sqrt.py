n = int(input())
l, r = 0, n
ans = 0
while r-l > 10**-5:
    mid = (l+r) / 2
    if mid*mid == n:
        print(mid)
        exit()
    elif mid*mid < n:
        l = mid + 10**-5
        ans = mid
    else:
        r = mid - 10**-5
print(round(ans, 8))