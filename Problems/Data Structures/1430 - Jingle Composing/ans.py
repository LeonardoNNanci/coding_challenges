notes = {
    "W": 1,
    "H": 1 / 2,
    "Q": 1 / 4,
    "E": 1 / 8,
    "S": 1 / 16,
    "T": 1 / 32,
    "X": 1 / 64,
}

while True:
    composition = input()
    if composition == "*":
        break

    measures = list(map(str, composition[1:-1].split("/")))
    count = 0
    for measure in measures:
        s = 0
        for nota in measure:
            s += notes[nota]
        if s == 1:
            count += 1
    print(count)
