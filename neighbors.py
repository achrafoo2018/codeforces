n, m = map(int, input().split(" "))
mp = {x : [] for x in range(1, n+1)}
for i in range(m):
    x, y = map(int, input().split(" "))
    mp[x].append(y)
    mp[y].append(x)
ans = "YES"
q = 0
for i in mp.keys():
    x =  mp[i]
    if len(x) < 2:
        q += 1
    if len(x) > 2:
        print("NO")
        exit(0)
    pp = x
    for y in x:
        pp += mp[y]
    if len(pp) != len(set(pp)):
        print("NO")
        exit(0)
if x < 2:
    print("NO")
else:
    print("YES")
