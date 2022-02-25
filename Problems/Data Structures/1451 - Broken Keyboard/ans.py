from collections import deque

while True:
    try:
        p = 0
        msg = deque()
        string = input()

        for c in string:
            if c == "[":
                p = 0
            elif c == "]":
                p = len(msg)
            else:
                msg.insert(p, c)
                p += 1

        print(str(msg)[7:-2].replace("', '", "")[1:-1])
    except EOFError:
        break
