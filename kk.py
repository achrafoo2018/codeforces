s = "&'()*56789:CDEFGHIJSTUVWXYZcdefghijstuvwxyz"
for i in range(-254, 255):
	r = ""
	for j in range(len(s)):
		try:
			r += chr(ord(s[j])+i)
		except:
			break
	print(r)	
