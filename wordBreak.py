def wordBreak(s, dictio):
    n = len(s)
    dp = [[0 for i in range(n+1)] for j in range(n+1)]
    dc = set(dictio)
    for i in range(n+1):
        for j in range(n+1):
            if(i == j):
                dp[i][j] = 0
            print("{},{}:{}".format(i, j, 1 if s[i:j] in dc else 0), end=" ")
            if i == 0 or j == 0:
                dp[i][j] = (s[i:j] in dc)
            elif s[i:j] in dc:
                dp[i][j] = dp[i-1][i] or dp[i-1][j]
            else:
                dp[i][j] = dp[i-1][j]
    print()
    # for i in dp:
    #     print(*i, sep=" ")
    return dp[n-1][n]
dic =  ["iajxlo", "h", "q"]
s = "hhqhq"
wordBreak(s, dic)