x, y = [int(i) for i in input().split(" ")]
ans = "NO"
if x == y:
    print("YES")
    exit(0)
bin_x, bin_y = str(bin(x))[2:], str(bin(y))[2:]
try:
    i1 = bin_y.index(bin_x+'1')
    re = set(bin_y[:i1]+bin_y[i1+len(bin_x)+1:])
    if len(re) == 0 or (len(re) == 1 and '1' in re):
        ans = "YES"
except:
    pass
try:
    i2 = bin_y.index((bin_x+'1')[::-1])
    re = set(bin_y[:i2]+bin_y[i2+len(bin_x)+1:])
    if len(re) == 0 or (len(re) == 1 and '1' in re):
        ans = "YES"
except:
    pass
bin_x = bin_x.strip('0')
try:
    i3 = bin_y.index(bin_x)
    re = set(bin_y[:i3]+bin_y[i3+len(bin_x):])
    if len(re) == 0 or (len(re) == 1 and '1' in re):
        ans = "YES"
except:
    pass
try:
    i4 = bin_y.index(bin_x[::-1])
    re = set(bin_y[:i4]+bin_y[i4+len(bin_x):])
    if len(re) == 0 or (len(re) == 1 and '1' in re):
        ans = "YES"
except:
    pass
print(ans)

