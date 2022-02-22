w, h, n = map(int, input().split(" "))
def good(x):
    return (x // w) * (x // h) >= n
l, r = 0, 1
while not good(r):
    r *= 2
while l <= r:
    mid = (l+r) // 2
    if good(mid):
        r = mid - 1
    else:
        l = mid + 1
print(l)