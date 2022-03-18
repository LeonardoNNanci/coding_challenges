MAX_V = 1000

adj = [[] for _ in range(MAX_V)]


def DFS(u):
    vis[u] = True
    for v, w in adj[u]:
        if not vis[v]:
            DFS(v)


# in main
vis = [False] * V
for u in range(V):
    if not vis[u]:
        DFS(u)
