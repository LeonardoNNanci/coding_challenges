from math import sqrt, pow


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


def kruskals_MST(edges, V, E):
    uf = UnionFind(V)
    edges.sort()

    mst_cost = 0
    for w, u, v in edges:
        if not uf.is_same_set(u, v):
            mst_cost += w
            uf.union_set(u, v)

    return mst_cost


C = int(input())
for _ in range(C):
    V = int(input())
    E = (V + 1) * V // 2
    print(E)
    pos = [(0, 0) for _ in range(V)]
    edges = [(0, 0, 0) for _ in range(E)]

    for i in range(V):
        x, y = map(int, input().split())
        pos[i] = (x, y)

    count = 0
    for i in range(V):
        for j in range(i, V):
            dist = sqrt(pow(pos[i][0] - pos[j][0], 2) + pow(pos[i][1] - pos[j][1], 2))
            edges[count] = (dist, i, j)
            count += 1

    cost = kruskals_MST(edges, V, E) / 100
    print(f"{cost:0.2f}")
