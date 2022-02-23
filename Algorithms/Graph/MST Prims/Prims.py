from heapq import *


def primsMST(adj):
    V = len(adj)

    src = 0
    MSTset = [False] * V
    weights = [float("inf")] * V
    parents = [-1] * V
    pq = []

    weights[src] = 0
    heappush(pq, (weights[src], src))

    while pq:
        w, u = heappop(pq)
        if MSTset[u]:
            continue

        MSTset[u] = True
        for v, w in adj[u]:
            if not MSTset[v] and weights[v] > w:
                heappush(pq, (w, v))
                weights[v] = w
                parents[v] = u
