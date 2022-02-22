t = int(input())
for _ in range(t):
	n = input()
	if int(n) % 25 == 0:
		print(0)
		continue
	ans = 0
	while n[-1] not in ['0', '5']:
		n = n[:-1]
		ans += 1
	if n == '':
		print(ans)
		continue
	s = set()
	while len(n):
		i = len(n) - 1
		if n[i] == '5':
			if '0' in s:
				ans -= 1
				break
			s.add(n[i])
		elif n[i] == '0':
			if '0' in s:
				ans -= 1
				break
			s.add(n[i])
		elif n[i] in ['7', '2']:
			if '5' in s:
				ans -= 1
				break
			s.add(n[i])
		ans += 1
		n = n[:-1]
	print(ans)
	
