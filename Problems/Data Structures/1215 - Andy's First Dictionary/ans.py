dict = set()

while True:
    try:
        words = input().split()
        for word in words:
            token = ""
            for ch in word:
                if "a" <= ch.lower() <= "z":
                    token += ch.lower()
                elif token:
                    dict.add(token)
                    token = ""
            if token:
                dict.add(token)

    except EOFError:
        break

for word in sorted(dict):
    print(word)
