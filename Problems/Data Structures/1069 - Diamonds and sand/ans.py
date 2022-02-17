n = int(input())

for i in range(n):
    string = input()
    stack, complete = 0, 0
    for c in string:
        if c == "<":
            stack += 1
        elif c == ">" and stack:
            stack -= 1
            complete += 1

    print(complete)
