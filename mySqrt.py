from math import trunc


def mySqrt(x: int):
    l = 0
    h = x+1
    while l <= h and abs(l-h) > 10**-10:
        mid = (l+h) / 2
        if mid*mid >= x:
            h = mid - 10**-10
        else:
            l = mid + 10**-10
    return int(l+0.001)
    
print(mySqrt(int(input("Enter x : "))))