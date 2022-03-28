count = 0
while True:

    n = int(input())
    if not n:
        break

    if count > 0:
        print()
    count += 1

    texts = [""] * n
    max_len = 0
    for i in range(n):
        texts[i] = input()
        max_len = max(max_len, len(texts[i]))

    for text in texts:
        print(text.rjust(max_len))
