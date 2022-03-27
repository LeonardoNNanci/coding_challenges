c = int(input())
for _ in range(c):
    text = input()

    if len(text) == 5:
        print(3)

    else:
        count = 0
        for n, o in zip(text, "one"):
            if n != o:
                count += 1

        print(1) if count <= 1 else print(2)
