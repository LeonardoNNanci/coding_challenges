from collections import deque


def BFS(adj):
    V = len(adj)

    vis = [False] * V
    q = deque()
    q.append(0)
    while q:
        u = q.popleft()

        if vis[u]:
            continue
        vis[u] = True

        for v, w in adj[u]:
            if not vis[v]:
                q.append(v)
