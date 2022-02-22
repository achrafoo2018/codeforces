for _ in range(int(input())):
    n, k = map(int, input().split(" "))
    arr = sorted(map(int, input().split(" ")))
    ss = sum(arr)
    l, r, ans = 0, 10**18, 10**18
    while l <= r:
        mid = (l+r) // 2
        tmp = ss - mid
        s = mid
        for i in range(n-1, 0, -1):
            if tmp <= k:
                break
            s += 1
            tmp -= arr[i]
            tmp += (arr[0] - mid)
        if tmp > k:
            l = mid + 1
        else:
            ans = min(ans, s)
            r = mid - 1
    print(ans)