s1, s2 = 0, 0
for i in range(101):
    s1 += i**2
    s2 += i
print(f"S1 = {s1}")
print(f"S2 = {s2 ** 2}")
print(f"S1, S2 = {abs(s1 - (s2 ** 2))}")