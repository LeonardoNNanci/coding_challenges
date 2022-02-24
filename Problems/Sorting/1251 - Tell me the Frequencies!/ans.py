def comp(f):
    return (f[1], -f[0])


MINCHAR = 32
c = 0
while True:
    try:

        string = input()
        freqs = [[MINCHAR + i, 0] for i in range(100)]

        for ch in string:
            freqs[ord(ch) - MINCHAR][1] += 1

        freqs.sort(key=comp)

        if c > 0:
            print()
        c += 1
        for code, freq in freqs:
            if freq != 0:
                print(code, freq)

    except EOFError:
        break
