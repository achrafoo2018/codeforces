n, l, r = map(int, input().split(" "))
if n == 1 or r == 1:
    print(f"{n} {n}")
    exit(0)
min_ = n - l + 1
for i in range(1, l):
    min_ += 2**i
max_ = (2**(r-1))*(n-r+1) + 1
for i in range(1, r-1):
    max_ += 2**i
print(f"{min_} {max_}")
