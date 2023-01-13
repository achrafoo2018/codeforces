def dicho(x, t):
    l = 0
    h = len(t) - 1
    while l <= h:
        mid = (l+h) // 2
        if t[mid] == x:
            return mid
        elif t[mid] > x:
            h = mid - 1
        else:
            l = mid + 1
    return mid

print(dicho(1, [2, 5, 6, 7]))