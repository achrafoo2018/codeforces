a, b = input(), input()
if str(eval(a+"+"+b)).replace("0", "") == str(eval(a.replace("0", "")+"+"+b.replace("0", ""))):
    print("YES")
else:
    print("NO")
