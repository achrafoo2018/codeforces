n, m = input().split(" ")
n, m = int(n), int(m)
lst = list(map(lambda y: int(y), input().split(" ")))
for _ in range(m):
    i = int(input())
    print(len(set(lst[i-1:])))
