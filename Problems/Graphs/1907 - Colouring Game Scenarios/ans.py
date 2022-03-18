from collections import deque

dc = [0, -1, 1, 0]
dr = [-1, 0, 0, 1]


def flood_fill_BFS(r0, c0):
    q = deque()
    q.append((r0, c0))

    while q:
        row, col = q.popleft()
        if row < 0 or row >= R or col < 0 or col >= C or grid[row][col] == "o":
            continue
        grid[row][col] = "o"

        for i, j in zip(dc, dr):
            r = row + j
            c = col + i
            q.append((r, c))


R, C = map(int, input().split())
grid = [list(input()) for _ in range(R)]

colors = 0
for i in range(R):
    for j in range(C):
        if grid[i][j] == ".":
            colors += 1
            flood_fill_BFS(i, j)

print(colors)
