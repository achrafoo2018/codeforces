for _ in range(int(input())):
    n, a, b = map(int, input().split(" "))
    s = ""
    for i in range(n):
        s += chr(ord('a') + i % b)
    print(s)