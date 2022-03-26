from itertools import zip_longest

while True:
    X, Y = map(lambda x: [int(i) for i in reversed(x)], input().split())

    if X[-1] == 0 and Y[-1] == 0:
        break

    count = carry = 0
    for x, y in zip_longest(X, Y, fillvalue=0):
        if x + y + carry >= 10:
            carry = 1
            count += 1
        else:
            carry = 0

    if not count:
        print("No carry operation.")
    elif count == 1:
        print("1 carry operation.")
    else:
        print(f"{count} carry operations.")
