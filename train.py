s = input()
print(1 + len(s[1:]) // 2 if s[1:].count('1') != 0 else len(s) // 2)