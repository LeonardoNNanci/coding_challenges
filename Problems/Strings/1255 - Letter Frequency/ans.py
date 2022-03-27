C = int(input())
for _ in range(C):
    text = input()

    a = ord("a")
    occurences = [[0, chr(a + i)] for i in range(26)]

    for ch in text:
        if "a" <= ch.lower() <= "z":
            occurences[ord(ch.lower()) - a][0] += 1

    occurences.sort(key=lambda x: (-x[0], x[1]))
    max_occ = occurences[0][0]
    i = 0
    while occurences[i][0] == max_occ:
        print(occurences[i][1], end="")
        i += 1
    print()
