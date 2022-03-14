def kruskals_MST(edges, V, E):
    uf = UnionFind(V)
    edges.sort()

    mst_cost = 0
    for w, u, v in edges:
        if not uf.is_same_set(u, v):
            mst_cost += w
            uf.union_set(u, v)

    return mst_cost


class UnionFind:
    def __init__(self, N):
        self.rank = [0] * N
        self.parent = [i for i in range(N)]

    def find_set(self, i):
        if self.parent[i] == i:
            return i
        self.parent[i] = self.find_set(self.parent[i])
        return self.parent[i]

    def is_same_set(self, i, j):
        return self.find_set(i) == self.find_set(j)

    def union_set(self, i, j):
        if self.is_same_set(i, j):
            return

        x, y = self.find_set(i), self.find_set(j)
        if self.rank[x] > self.rank[y]:
            self.parent[y] = x
        else:
            self.parent[x] = y
            if self.rank[x] == self.rank[y]:
                self.rank[y] += 1


while True:
    V, E = map(int, input().split())
    if not (V or E):
        break
    edges = [()] * E
    for i in range(E):
        u, v, w = map(int, input().split())
        edges[i] = (w, u, v)

    print(kruskals_MST(edges, V, E))
