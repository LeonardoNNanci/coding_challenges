from queue import PriorityQueue


def primsMST(adj):
    V = len(adj)

    src = 0
    MSTset = [False] * V
    weights = [float("inf")] * V
    parents = [-1] * V
    pq = PriorityQueue(V)

    weights[src] = 0
    pq.put((weights[src], src))

    while not pq.empty():
        _, u = pq.get()
        if MSTset[u]:
            continue

        MSTset[u] = True
        for v, w in adj[u]:
            if not MSTset[v] and weights[v] > w:
                pq.put((w, v))
                weights[v] = w
                parents[v] = u
