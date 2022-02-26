t = int(input())
for c in range(1, t + 1):
    n, m = map(int, input().split())

    elves = [()] * n
    for i in range(n):
        name, weight, age, height = input().split()
        elves[i] = (-int(weight), int(age), float(height), name)

    elves.sort()
    print(f"CENARIO {{{c}}}")
    for i, (_, _, _, name) in enumerate(elves[:m], start=1):
        print(f"{i} - {name}")
