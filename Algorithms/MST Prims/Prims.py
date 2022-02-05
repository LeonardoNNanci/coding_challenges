from queue import PriorityQueue


class UVW:
    def __init__(self, u, v, w) -> None:
        self.u = u
        self.v = v
        self.w = w

    def __gt__(self, other):
        return self.w > other.w


def prims_MST(graph, V):
    u, n = 0, 1
    viz = [False for _ in range(V)]
    pq = PriorityQueue()

    while n < V:
        if not viz[u]:
            viz[u] = True
            for edge in graph[u]:
                if not viz[edge[0]]:
                    pq.put(UVW(u, edge[0], edge[1]))

        p = pq.get()

        if not viz[p.v]:
            # adds edge (p.u---p.v) to solution
            u = p.v
            n += 1
