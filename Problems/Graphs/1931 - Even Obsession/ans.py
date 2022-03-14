from heapq import *


def dijkstra(adj, src, dest, V):
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

        for v1, w1 in adj[u]:
            for v2, w2 in adj[v1]:
                if dist[v2] > d + w1 + w2:
                    dist[v2], parent[v2] = d + w1 + w2, u
                    heappush(pq, (dist[v2], v2))

    return -1


V, E = map(int, input().split())
adj = [[] for _ in range(V)]
for _ in range(E):
    u, v, w = map(int, input().split())
    u -= 1
    v -= 1
    adj[u].append((v, w))
    adj[v].append((u, w))
cost = dijkstra(adj, 0, V - 1, V)
print(cost) if cost != float("inf") else print(-1)
