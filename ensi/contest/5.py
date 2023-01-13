n = int(input())
arr = []
vis = [False] * 1000
i = 2
s = n
for i in range(1, n+1):
    if i > s or s-i==i or vis[i] or vis[s-i]:
        continue
    arr.append(str(i))
    s -= i
    vis[i] = True
print(len(arr))
print(" ".join(arr))