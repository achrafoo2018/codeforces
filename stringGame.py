t = input()
p = input()
arr = [int(i)-1 for i in input().split(" ")]
def isSubSequence(str1, str2):
    m = len(str1)
    n = len(str2)
    j = 0  
    i = 0 
    while j < m and i < n:
        if str1[j] == str2[i]:
            j = j+1
        i = i + 1
    return j == m

def check(x):
    ss = ""
    r2 = set(arr[:x])
    for i in range(len(t)):
        if i in r2:
            continue
        ss += t[i]
    return isSubSequence(p, ss)

l, h = 0, len(arr)-1
while l < h:
    mid = (l+h+1) // 2
    if check(mid):
        l = mid
    else:
        h = mid - 1
print(l)