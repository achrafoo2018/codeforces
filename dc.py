for _ in range(int(input())):
    n = int(input())
    s = input()
    possible = ['aa', 'aba', 'aca', 'abca', 'acba', 'abbacca', 'accabba']
    ans = -1
    for i in possible:
        if i in s:
            ans = len(i)
            break
    print(ans)
    