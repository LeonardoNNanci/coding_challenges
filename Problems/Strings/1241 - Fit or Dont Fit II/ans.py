c = int(input())
for _ in range(c):
    A, B = map(lambda x: x[::-1], input().split())
    if len(A) < len(B):
        print("nao encaixa")
        continue

    for a, b in zip(A, B):
        if a != b:
            print("nao ", end="")
            break

    print("encaixa")
