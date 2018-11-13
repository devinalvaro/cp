t = int(input())

while t > 0:
    fac = [1 for i in range(100 + 1)]
    for i in range(1, 100 + 1):
        fac[i] = i * fac[i - 1]

    n = int(input())
    print(fac[n])

    t -= 1
