while True:
    try:
        text = list(input())
        toUpper = 1
        for i, ch in enumerate(text):
            if toUpper:
                text[i] = text[i].upper()
            else:
                text[i] = text[i].lower()
            if ch != " ":
                toUpper ^= 1
        print("".join(text))

    except EOFError:
        break
