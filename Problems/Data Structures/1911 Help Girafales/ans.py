while True:
    n = int(input())
    if not n:
        break

    signatures = dict()

    for _ in range(n):
        name, original = input().split()
        signatures[name] = original

    m = int(input())
    count_false = 0
    for _ in range(m):
        name, day = input().split()
        original = signatures[name]

        count_diff = 0
        for o, d in zip(original, day):
            if o != d:
                count_diff += 1
        if count_diff > 1:
            count_false += 1

    print(count_false)
    signatures.clear()
