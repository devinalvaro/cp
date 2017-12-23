candidate_letters = set("abcdefghijklmnopqrstuvwxyz")

is_unambiguous = False
avoidable_shock = 0

n = int(input())

for i in range(n):
    if i == n - 1:
        break

    mark, word = input().split()

    if is_unambiguous and mark != '.':
        avoidable_shock += 1

    if mark == '!':
        candidate_letters = candidate_letters & set(word)
    if mark == '.' or mark == '?':
        candidate_letters = candidate_letters - set(word)

    if len(candidate_letters) == 1:
        is_unambiguous = True

print(avoidable_shock)
