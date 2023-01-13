n = int(input())
arr = [int(i) for i in input().split(" ")]
for i in range(n):
    ans = 0
    while arr[i] < 32768:
        arr[i] *= 2
        ans += 1
    arr[i] //= 2
    ans += 32768 - arr[i]
    print(ans, " ")
print()
