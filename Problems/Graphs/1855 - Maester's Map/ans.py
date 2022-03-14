def direction(ch):
    if ch == ">":
        return (0, 1)
    if ch == "<":
        return (0, -1)
    if ch == "v":
        return (1, 0)
    if ch == "^":
        return (-1, 0)
    return dir


w, h = int(input()), int(input())

grid = [["."] * w for _ in range(h)]
for i in range(h):
    row = input()
    for j, ch in enumerate(row):
        grid[i][j] = ch

x, y = 0, 0
dir = (0, 0)
while True:
    if grid[x][y] == "*":
        print("*")
        break
    dir = direction(grid[x][y])
    grid[x][y] = "1"
    x += dir[0]
    y += dir[1]
    if x < 0 or y < 0 or x >= h or y >= w or grid[x][y] == "1":
        print("!")
        break
