for _ in range(int(input())):
    n = int(input())
    arr = [int(i) for i in input().split(" ")]
    mul, mx, prevm = 1, 1, -1
    ln = -1
    x, y = n, 0
    l = 0
    for i in range(n):
        if arr[i] == 0:
            l = i+1
            ln = -1
            prevmul = -1
            mul = 1
            continue
        mul *= arr[i]
        if ln == -1 and arr[i] < 0:
            ln = i
            prevmul = mul
        if mul > mx:
            x = l
            y = n - i - 1
            mx = mul
        elif mul < 0 and ln != -1 and mul//prevmul > mx:
            x = ln+1
            y = n - i - 1
            mx = mul/prevmul
    print(f"{x} {y}")