n = int(input())
k1 = list(map(int, input().split(" ")))
k2 = list(map(int, input().split(" ")))
k1.pop(0)
k2.pop(0)
s = set()
winner, ans = 0, 0
while 1:
    c1 = k1.pop(0)
    c2 = k2.pop(0)
    if c1 > c2:
        k1.append(c2)
        k1.append(c1)
    else:
        k2.append(c1)
        k2.append(c2)
    ans += 1
    if ",".join(map(str, k1+[":"]+k2)) in s:
        ans = -1
        break
    if not k1:
        winner = 2
        break
    if not k2:
        winner = 1
        break
    s.add(",".join(map(str, k1+[":"]+k2)))
if winner:
    print(f"{ans} {winner}")
else:
    print("-1")
