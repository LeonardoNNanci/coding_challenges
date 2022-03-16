from heapq import *


def dijkstra(src, dest, V):
    global c
    dist, parent = [float("inf")] * V, [-1] * V
    pq = []

    dist[src] = 0
    heappush(pq, (dist[src], src))

    while pq:
        d, u = heappop(pq)

        if u == dest:
            return d
        if d > dist[u]:
            continue

        for v, w in adj[u]:
            if dist[v] > d + w and (u >= c or (u < c and v == u + 1)):
                dist[v], parent[v] = d + w, u
                heappush(pq, (dist[v], v))

    return -1


while True:
    V, E, c, k = map(int, input().split())
    if not (V or E or c or k):
        break

    adj = [[] for _ in range(V)]

    for _ in range(E):
        u, v, w = map(int, input().split())
        adj[u].append((v, w))
        adj[v].append((u, w))

    print(dijkstra(k, c - 1, V))
