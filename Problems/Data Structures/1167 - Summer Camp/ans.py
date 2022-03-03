from collections import deque

def circular_move(i, offset):
    global circle
    n = len(circle)
    ans = i + offset
    ans = ans - (int(ans / n) * n)
    if ans >= 0:
        return ans
    return n + ans


global circle
while True:
    n = int(input())
    if not n:
        break

    circle = deque()

    for _ in range(n):
        name, token = input().split()
        circle.append((name, int(token)))

    child = 0
    token = circle[child][1]

    while len(circle) > 1:
        if token % 2:
            child = circular_move(child, token)
        else:
            child = circular_move(child, -token)

        out = child
        token = circle[child][1]
        del circle[out]
        if token % 2:
            child = circular_move(child, -1)
        child = circular_move(child, 0)

    print(f"Vencedor(a): {circle[0][0]}")
