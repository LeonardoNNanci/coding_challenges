from collections import defaultdict

dict = defaultdict(int)

m, n = map(int, input().split())
for _ in range(m):
    word, cost = input().split()
    dict[word] = int(cost)

for _ in range(n):
    total = 0
    while True:
        line = input()
        if line == ".":
            print(total)
            break

        for word in line.split():
            total += dict[word]
