n = input()
dp = [dict() for _ in range(len(n))]
def solve(s, idx):
    if idx >= len(n):
        return -1