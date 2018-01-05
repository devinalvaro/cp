a, b = input().split()
a = int(a)
b = int(b)

x, y, z = input().split()
x = int(x)
y = int(y)
z = int(z)

a -= (2 * x)

a -= y
b -= y

b -= (3 * z)

if a > 0:
    a = 0
if b > 0:
    b = 0

print(-1 * (a + b))
