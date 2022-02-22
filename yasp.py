t = int(input())
for _ in range(t):
    n = int(input())
    arr = list(map(int, input().split(" ")))
    arr2 = sorted(arr)
    if arr == arr2:
        print("NO")
        continue
    