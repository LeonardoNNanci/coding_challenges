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
