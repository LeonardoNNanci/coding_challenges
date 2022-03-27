c = int(input())
for _ in range(c):
    text = list(input())
    for i, ch in enumerate(text):
        if "a" <= ch <= "z" or "A" <= ch <= "Z":
            text[i] = chr(ord(ch) + 3)

    text.reverse()
    mid = int((len(text)) / 2)
    for i, ch in enumerate(text[mid:], start=mid):
        text[i] = chr(ord(ch) - 1)

    print("".join(text))
