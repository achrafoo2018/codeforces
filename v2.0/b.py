t = int(input())
for _ in range(t):
    A, B = [int(i) for i in input().split(" ")]
    print("NO" if B == 1 else f"YES\n{A*B} {A} {A*B+A}")
