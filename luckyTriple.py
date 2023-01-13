n = int(input())
if n & 1:
    print(*list(range(n)), sep=" ")
    print(*list(range(n)), sep=" ")
    for i in range(0, n, 2):
        print(i, end=" ")
    for i in range(1, n, 2):
        print(i, end=" ")
    print()
else:
    print(-1)
