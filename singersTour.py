for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split(" ")))
    s = sum(arr)
    x = ((n*(n+1)) // 2)
    if s % x != 0:
        print("NO")
        continue
    s //= x
    ans = []
    for i in range(n):
        k = (arr[i-1] - arr[i]) + s
        if k % n != 0 or k <= 0:
            ans = []
            print("NO")
            break
        ans.append(k // n)
    if ans:
        print("YES")
        print(*ans, sep=" ")    
        
