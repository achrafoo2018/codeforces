n = input()
s = 0
for i in n:
    s += int(i)
if s % 3 == 0:
    print(n)
else:
    res = set()
    def solve(ss, nn, idx):
        print(f"ss = {ss}, nn = {nn}")
        if ss % 3 == 0 and nn and nn[0] != '0':
            return nn
        if idx >= len(nn) or nn == "":
            return ""
        return max(solve(ss-int(nn[idx]), nn[0:idx]+nn[idx+1:], idx), solve(ss, nn, idx+1), key=len)
    solve(s, n, 0)
    print(max(res, key=len))
