n = int(input())
s = input()

for i in range(1, n + 1):
    if n % i != 0:
        continue

    s = s[i-1::-1] + s[i:]

print(s)
