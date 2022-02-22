n = int(input())
for _ in range(n):
    x = int(input())
    s = ""
    mp = {}
    for i in range(10):
        mp[str(i)] = 0
    for i in range(1, x+1):
        s += str(i)
    for i in range(len(s)):
        mp[s[i]] += 1
    for i in range(10):
        print(f"{mp[str(i)]}", end=" ")
    print()