m = int(input())

while m:
	n = int(input())
	a = 1
	b = 2
	tmp = 0
	if n <= 2:
		print(n)
		m -= 1
		continue
	for i in range(3, n + 1):
		tmp = a * 2 + b + 1
		a = b
		b = tmp
	print(tmp)
	m -= 1