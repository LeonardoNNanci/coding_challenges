from collections import deque

# R, C = XXX, XXX  # define in main
# define grid in main
dc = [-1, 0, 1, -1, 1, -1, 0, 1]
dr = [-1, -1, -1, 0, 0, 1, 1, 1]


def flood_fill_DFS(row, col):
    if row < 0 or row >= R or col < 0 or col >= C or grid[row][col] == 1:
        return
    grid[row][col] = 1

    for c, r in zip(dc, dr):
        flood_fill_DFS(row + r, col + c)


def flood_fill_BFS(r0, c0):
    q = deque()
    q.append((r0, c0))

    while q:
        row, col = q.popleft()
        if row < 0 or row >= R or col < 0 or col >= C or grid[row][col] == 1:
            continue
        grid[row][col] = 1

        for i, j in zip(dc, dr):
            r = row + j
            c = col + i
            q.append((r, c))
