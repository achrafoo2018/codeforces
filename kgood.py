arr = list(range(2, 10))
def solve():
    s = 0
    se = set()
    for m in arr:
        s += m
        se.add(m)
        if s >= n:
            break
        ans = (n-s) % (len(se)+1)
        cond = True
        s2 = set()
        s2.add(ans)
        for p in se:
            pp = p % (len(se)+1)
            if pp in s2:
                cond = False
            s2.add(pp)
        if cond:
            print(len(se) + 1)
            return True
    return False

for _ in range(int(input())):
    n = int(input())
    if n & 1:
        print(2)
    else:
        if not solve():
            print(-1)

