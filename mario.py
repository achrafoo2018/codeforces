def blocks(n):
	if n == 0:
		return
	print("#"*n)
	blocks(n-1)

blocks(4)
