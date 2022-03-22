import io, os

input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline


while True:
    V = int(input().decode())
    if V == 0:
        break
    parent = [(-1, 0)] * V
    depth = [0] * V

    for u in range(1, V):
        v, w = map(int, input().decode().split())
        parent[u] = (v, w)
        depth[u] = depth[v] + 1

    q = int(input().decode())
    distances = [0] * q
    for i in range(q):
        orig, dest = map(int, input().decode().split())
        dist = 0

        deepest = orig if depth[orig] >= depth[dest] else dest
        highest = orig if depth[orig] < depth[dest] else dest

        while depth[deepest] > depth[highest]:
            dist += parent[deepest][1]
            deepest = parent[deepest][0]

        orig, dest = deepest, highest

        while orig != dest:
            dist += parent[orig][1] + parent[dest][1]
            orig = parent[orig][0]
            dest = parent[dest][0]

        distances[i] = dist
    print(*distances)
