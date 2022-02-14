from queue import Queue


def BFS(adj):
    V = len(adj)

    vis = [False] * V
    q = Queue()
    q.put(0)

    while not q.empty():
        u = q.get()

        if vis[u]:
            continue
        vis[u] = True

        for v, w in adj[u]:
            if not vis[v]:
                q.put(v)
