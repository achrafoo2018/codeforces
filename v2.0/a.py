t = int(input())
for _ in range(t):
    n = int(input())
    print(n // 10 if n % 10 != 9 else n // 10 +1)

