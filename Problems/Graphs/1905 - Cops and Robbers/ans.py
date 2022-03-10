from collections import deque

R = C = 5
dc = [0, -1, 1, 0]
dr = [-1, 0, 0, 1]


def flood_fill_BFS(r0, c0):
    if grid[r0][c0] == 1:
        return False

    q = deque()
    q.append((r0, c0))

    while q:
        row, col = q.popleft()
        if row < 0 or row >= R or col < 0 or col >= C or grid[row][col] == 1:
            continue
        if row == col == 4:
            return True
        grid[row][col] = 1

        for i, j in zip(dc, dr):
            r = row + j
            c = col + i
            q.append((r, c))

    return False


n = int(input())
for _ in range(n):
    grid = []
    r = 0
    while r < 5:
        line = input()
        if line:
            grid.append(list(map(int, line.split())))
            r += 1

    print("COPS") if flood_fill_BFS(0, 0) else print("ROBBERS")
