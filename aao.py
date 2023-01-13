t = int(input())
for _ in range(t):
    n, k = [int(i) for i in input().split(" ")]
    arr = sorted([int(i) for i in input().split(" ")])
    ans = 0
    l, h = n-k-1, n-1
    while k:
        ans += arr[l] // arr[h]
        l -= 1
        h -= 1
        k -= 1
    for i in range(l+1):
        ans += arr[i]
    print(ans)