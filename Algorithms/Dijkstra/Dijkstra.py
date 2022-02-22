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

        for v, w in adj[u]:
            if dist[v] > d + w:
                dist[v], parent[v] = d + w, u
                heappush(pq, (dist[v], v))

    return -1
