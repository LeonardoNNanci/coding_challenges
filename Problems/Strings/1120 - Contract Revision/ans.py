while True:
    d, n = input().split()
    if d == "0":
        break

    n = n.replace(d, "")

    print(int(n)) if n else print(0)
