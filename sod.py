n = list(map(int, list(input())))
ans = 0
while len(n) > 1:
    n = list(map(int, str(sum(n))))
    ans += 1
print(ans)