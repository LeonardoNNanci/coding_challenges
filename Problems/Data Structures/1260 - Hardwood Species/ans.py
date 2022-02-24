from sys import stdin
from collections import defaultdict

freqs = defaultdict(int)

n = int(stdin.readline())
stdin.readline()
for i in range(n):

    if i > 0:
        print()

    count = 0
    while True:
        try:
            tree = stdin.readline().strip()
            if tree == "":
                break
            freqs[tree] += 1
            count += 1

        except EOFError:
            break

    for tree, freq in sorted(freqs.items()):
        print(f"{tree} {freq/count*100:.4f}")

    freqs.clear()
