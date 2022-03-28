while True:
    x, y = map(int, input().split())
    if not (x or y):
        break
    sum = [x for x in str(x + y) if x != "0"]
    print("".join(sum))
