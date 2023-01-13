import math
m, n = map(int, input().split(" "))
arr = []
for _ in range(n):
    arr.append(list(map(int, input().split(" "))))
l, h = 0, 10**32
while l <= h:
    mid = (l+h) // 2
    s = 0
    for i in range(n):
        t, z, y = arr[i][0], arr[i][1], arr[i][2]
        p = (t * z) + y;
        s +=  ((mid // p) * z + min(z, ((mid % p) // t)));
    if s >= m:
        h = mid - 1
    else:
        l = mid + 1
print(l)
s = 0
for i in range(n):
    t, z, y = arr[i][0], arr[i][1], arr[i][2]
    p = (t * z) + y
    ans = ((l // p) * z + min(z, ((l % p) // t)))
    ans = min(ans, max(0, m-s))
    s += ans
    print(ans, end=" ")
print()
