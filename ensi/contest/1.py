import math
n, m, k = [float(i) for i in input().split(" ")]
if math.isclose(n*m, k):
    print("Equal")
elif n*m < k:
    print("Mounir")
else:
    print("!Mounir")