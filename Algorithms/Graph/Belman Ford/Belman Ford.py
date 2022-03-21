dist = [float("inf")] * V
dist[s] = 0
for _ in range(V - 1):
    for u in range(V):
        for v, w in adj[u]:
            dist[v] = min(dist[v], dist[u] + w)
