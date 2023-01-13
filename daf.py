import math
n = int(input())
s = list(input())
ans = []
for i in range(n):
    if s[i] in ["1", "0"]:
        continue
    if s[i] == '9':
        ans += ["7", "3", "3", "2"]
        continue
    if s[i] == '2' or int(s[i]) & 1:
        ans.append(s[i])
        continue
    if s[i] in ["8", "4"]:
        ans.append(str(int(s[i])-1))
        ans += ["2"] * int(math.log2(int(s[i])))
    elif s[i] == '6':
        ans += ["5", "3"]
print("".join(sorted(ans, reverse=True)))