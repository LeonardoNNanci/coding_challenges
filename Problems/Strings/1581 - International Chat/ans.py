c = int(input())
for _ in range(c):
    n = int(input())
    prev = ""
    eng = False
    for _ in range(n):
        curr = input()
        if prev and not (eng or curr == prev):
            eng = True
        prev = curr

    print("ingles") if eng else print(curr)
