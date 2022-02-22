s1, x = [int(i) for i in input().split(" ")]
s2, p, f = [int(i) for i in input().split(" ")]
if s1 >= s2:
    print(0)
else:
    (x-p) // s2
    (x // s1) + ((x-p) // s2) * f
    6, 4

# 3 20
# 4 1 2
# 1 4 7 10 13 16 19 22
# 0 4 4 8  12 16 16 20

3