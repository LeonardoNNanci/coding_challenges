from heapq import *


global adj


def dijkstra(src, dest, V):
    global adj
    dist = [float("inf")] * V
    pq = []

    dist[src] = 0
    heappush(pq, (dist[src], src))

    while pq:
        d, u = heappop(pq)

        if u == dest:
            return d
        if d > dist[u]:
            continue

        for v, w in enumerate(adj[u]):
            if w != -1 and dist[v] > d + w:
                dist[v] = d + w
                heappush(pq, (dist[v], v))

    return -1


while True:
    n, e = map(int, input().split())
    if not (n or e):
        break

    adj = [[-1] * n for _ in range(n)]
    for _ in range(e):
        x, y, h = map(int, input().split())
        x -= 1
        y -= 1
        if adj[y][x] != -1:
            adj[x][y] = 0
            adj[y][x] = 0
        else:
            adj[x][y] = h

    k = int(input())
    for _ in range(k):
        o, d = map(int, input().split())
        o -= 1
        d -= 1
        cost = dijkstra(o, d, n)
        if cost == -1:
            print("Nao e possivel entregar a carta")
        else:
            print(cost)
    print()
