c = int(input())
for _ in range(c):
    text = input()
    letters = set()
    for ch in text:
        ch = ch.lower()
        if "a" <= ch <= "z":
            letters.add(ch)

    if len(letters) < 13:
        print("frase mal elaborada")
    elif len(letters) < 26:
        print("frase quase completa")
    else:
        print("frase completa")
