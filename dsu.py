class DSU:
    def __init__(self, n):
        self.n = n
        self.parent = [i for i in range(n)]
    
    def find(self, x):
        if self.parent[x] == x:
            return x
        else:
            self.parent[x] = self.find(self.parent[x])
            return self.parent[x]
    
    def unite(self, x, y):
        self.parent[self.find(x)] = self.find(y)

        
n, m = [int(i) for i in input().split(" ")]
dsu = DSU(n+1)
ans = []
for i in range(m):
    query, u, v = input().split(" ")
    u, v = int(u), int(v)
    if query == "union":
        dsu.unite(u, v)
    else:
        if dsu.find(u) == dsu.find(v):
            ans.append("YES")
        else:
            ans.append("NO")
print(*ans, sep="\n")