n = int(input())
for _ in range(n):
    s = set()
    words = input().split()
    for word in words:
        s.add(word)

    i = 0
    for word in sorted(s):
        if i > 0:
            print(" ", end="")
        print(f"{word}", end="")
        i += 1
    print()
