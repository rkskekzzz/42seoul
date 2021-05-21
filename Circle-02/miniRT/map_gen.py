from random import random

def num(n1, n2):
	return str(round(n1 + random() * (n2 - n1), 2))

def vec(n1, n2):
	return num(n1, n2) + "," + '1' + "," + num(n1, n2)


def col(n1, n2):
	return num(n1, n2) + "," + num(n1, n2) + "," + num(n1, n2)

def pp(arr):
	for a in arr:
		print(a, end=" ")
	print()

pos1 = -3
pos2 = 3

def l():
	n = num(pos1 * 2, pos2 * 2) + "," + '1' + "," + num(pos1 * 2, pos2 * 2)
	r = num(0.01, 0.1)
	color = col(0, 255)
	pp(["l", n, r, color])

def sp():
	c = vec(pos1, pos2)
	r = num(0.3, 0.6)
	color = col(0, 255)
	pp(["sp", c, r, color])

def cy():
	c = vec(pos1, pos2)
	n = col(-1, 1)
	r = 0.2
	h = 0.2
	color = col(0, 255)
	pp(["cy", c, n, r, h, color])


def sq():
	c = vec(pos1, pos2)
	n = col(-1, 1)
	r = num(0.2, 0.4)
	color = col(0, 255)
	pp(["sq", c, n, r, color])

f = [sp, cy, sq]
for _ in range(40):
	f[int(random() * len(f))]()
