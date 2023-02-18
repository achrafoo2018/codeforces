for _ in range(int(input())):
    n = int(input())
    s = input()
    pref = [[0, 0] for i in range(n+1)]
    ans = 0
    mp = dict()
    mp[0] = 1
    for i in range(n):
        pref[i+1] = pref[i]
        if i % 2:
            pref[i+1][0] += int(s[i])
        else:
            pref[i+1][1] += int(s[i])
        diff = (pref[i+1][0] - pref[i+1][1]) % 11
        if diff not in mp:
            mp[diff] = 0
        ans += mp[diff]
        mp[diff] += 1

    print(ans)