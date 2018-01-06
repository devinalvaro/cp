vowels = {'a', 'e', 'i', 'o', 'u'}
odds = {'1', '3', '5', '7', '9'}

s = input()
flip = 0

for c in s:
    if c in vowels or c in odds:
        flip += 1

print(flip)
