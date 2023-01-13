t = int(input())
for _ in range(t):
    n = int(input())
    if n % 2050 != 0:
        print(-1)
    else:
        m = n // 2050
        if m < 10:
            print(m)
        else:
            highestDivisor = 10**len(str(m))
            result = 0
            while m > 0:
                result += m // highestDivisor
                m %= highestDivisor
                highestDivisor //= 10
            print(result)