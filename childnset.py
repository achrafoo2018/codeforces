import math
def lowestBit(n):
    s = str(bin(n)[2:])
    pos = s[::-1].index('1')
    return int(s[-pos-1:], 2)
s, lim = map(int, input().split(" "))
odd = math.ceil(lim / 2)
even = sorted(map(lambda y: lowestBit(y), filter(lambda y: not y & 1, range(1, lim+1))))
if sum(even) + odd < s:
    print("NO")
else:
    if s & 1:
        
    else: