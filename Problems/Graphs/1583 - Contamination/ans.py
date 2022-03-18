from collections import deque

dr = [-1, 0, 0, 1]
dc = [0, -1, 1, 0]


def flood_fill_BFS(r0, c0):
    q = deque()
    q.append((r0, c0))

    while q:
        row, col = q.popleft()
        if (
            row < 0
            or row >= R
            or col < 0
            or col >= C
            or grid[row][col] == "!"
            or grid[row][col] == "X"
        ):
            continue
        grid[row][col] = "!"

        for i, j in zip(dc, dr):
            r = row + j
            c = col + i
            q.append((r, c))


while True:
    R, C = map(int, input().split())
    if not (R or C):
        break

    grid = [list(input()) for _ in range(R)]

    for i, row in enumerate(grid):
        for j, ch in enumerate(row):
            if ch == "T":
                flood_fill_BFS(i, j)

    for row in grid:
        print("".join(row).replace("!", "T"))
    print()
