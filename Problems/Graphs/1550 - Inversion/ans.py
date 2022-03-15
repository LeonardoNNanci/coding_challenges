def invert(x):
    inv = 0
    while x > 0:
        last_digit = x % 10
        inv = (inv * 10) + last_digit
        x //= 10
    return inv


from collections import deque


def BFS():
    vis = set()
    q = deque()
    q.append((A, 0))
    while q:
        u, dist = q.popleft()

        if u in vis:
            continue
        if u == B:
            return dist
        vis.add(u)

        inv = invert(u)
        if inv not in vis:
            q.append((inv, dist + 1))
        if u + 1 not in vis:
            q.append((u + 1, dist + 1))

    return -1


T = int(input())
for _ in range(T):
    A, B = map(int, input().split())
    print(BFS())
