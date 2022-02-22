import math
def solve():
    n = int(input())
    arr = []
    while len(arr) < n:
        arr += [int(i) for i in input().split(" ")]
    for i in arr:
        root = math.sqrt(i)
        if root * root != float(i):
            print("YES")
            return
    print("NO")

t = int(input())
for _ in range(t):
    solve()