from itertools import permutations

n = int(input())
for _ in range(n):
    text = input()
    perms = set(permutations(text))
    for perm in sorted(perms):
        print("".join(perm))
    print()
