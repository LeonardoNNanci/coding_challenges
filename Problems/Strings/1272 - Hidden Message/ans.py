C = int(input())
for _ in range(C):
    text = input()
    afterSpace = True
    for ch in text:
        if ch == " ":
            afterSpace = True
        elif afterSpace:
            print(ch, end="")
            afterSpace = False
    print()
