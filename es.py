for _ in range(int(input())):
    n = int(input())
    ans = list(range(3, n+1))
    ans.append(1)
    for i in range(n-1):
        for j in range(n-1):
            if i == j:
                print(2, end=" ")
            print(ans[j], end=" ")
        print()
    ans.append(2)
    print(*ans, sep=" ")