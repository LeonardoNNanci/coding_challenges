def DFS_aux(adj, vis, u):
    vis[u] = True
    for v, w in adj[u]:
        if not vis[v]:
            DFS_aux(adj, vis, v)


def DFS(adj):
    V = len(adj)

    vis = [False] * V

    for u in range(V):
        if not vis[u]:
            DFS_aux(adj, vis, u)
