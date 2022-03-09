def DFS_aux(adj, vis, u):
    global cc_size
    cc_size += 1
    vis[u] = True
    for v in adj[u]:
        if not vis[v]:
            DFS_aux(adj, vis, v)


def DFS(adj, n):
    V = len(adj)

    vis = [False] * V

    DFS_aux(adj, vis, n)


T = int(input())
for _ in range(T):
    n = int(input())
    V, E = map(int, input().split())
    adj = [[] for _ in range(V)]

    cc_size = 0
    for _ in range(E):
        u, v = map(int, input().split())
        adj[u].append(v)
        adj[v].append(u)

    DFS(adj, n)

    print((cc_size - 1) * 2)
