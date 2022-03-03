while True:
    try:
        n = int(input())
        items = [()] * n
        for i in range(n):
            piece, expiry = input().split()
            items[i] = (int(expiry), piece)

        count = 0
        items.sort()
        for item in items:
            if count:
                print(" ", end="")
            count += 1
            print(item[1], end="")
        print()

    except EOFError:
        break
