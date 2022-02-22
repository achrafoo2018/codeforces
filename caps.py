s = input()
if (s[0] + s[1:].upper()) == s:
    print(s.capitalize() if s[0] == s[:1].lower() else s.lower())
else:
    print(s)