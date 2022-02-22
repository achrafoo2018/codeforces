i = 1
while True:
    N = int(input())
    if(N == 0):
        break
    arr = input().split(" ")
    print(f'Case {i}: {len(arr)-2*arr.count("0")}')
    i += 1
