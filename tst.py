from functools import reduce
t = int(input())
for _ in range(t):
    n = int(input())
    print(reduce(lambda a, b: a&b, [int(i) for i in input().split(" ")]))
