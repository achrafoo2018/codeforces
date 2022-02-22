def isPrime(n):
    for i in range(2, int(n**0.5)+1):
        if n % i == 0:
            return False
    return True
primes = set()
primes.add(4)
for i in range(3, 10**6+1):
    if isPrime(i):
        primes.add(i*i)
    
n = int(input())
arr = [int(i) for i in input().split(" ")]
for i in arr:
    if i in primes:
        print("YES")
    else:
        print("NO")