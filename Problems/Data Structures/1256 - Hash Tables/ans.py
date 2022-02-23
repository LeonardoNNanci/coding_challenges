hash = [list() for _ in range(105)]

c = int(input())
for t in range(c):

    n, x = map(int, input().split())
    temp = list(map(int, input().split()))
    for data in temp:
        hash[data % n].append(data)

    for i in range(n):
        print(f"{i} -> ", end="")
        for data in hash[i]:
            print(f"{data} -> ", end="")
        print("\\")

    if t < c - 1:
        print()
        for i in range(n):
            hash[i].clear()
