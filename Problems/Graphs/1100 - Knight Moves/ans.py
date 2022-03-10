from collections import deque

A = ord("a")
R = C = 8
dr = [-2, -2, -1, 1, 2, 2, 1, -1]
dc = [1, -1, -2, -2, -1, 1, 2, 2]


def flood_fill_BFS(r0, c0, rf, cf):
    q = deque()
    q.append((r0, c0, 0))

    while q:
        row, col, moves = q.popleft()

        if row == rf and col == cf:
            return moves

        if row < 0 or row >= R or col < 0 or col >= C or grid[row][col] == 1:
            continue

        grid[row][col] = 1
        for i, j in zip(dc, dr):
            r = row + j
            c = col + i
            q.append((r, c, moves + 1))


while True:
    try:
        grid = [[0] * C for _ in range(R)]
        c0, r0, _, cf, rf = input()
        moves = flood_fill_BFS(int(r0) - 1, ord(c0) - A, int(rf) - 1, ord(cf) - A)
        print(f"To get from {c0+r0} to {cf+rf} takes {moves} knight moves.")

    except EOFError:
        break
