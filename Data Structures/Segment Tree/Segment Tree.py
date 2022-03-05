class SegmentTree:
    def __init__(self, neutral, arr=None, n=None):
        self.neutral = neutral
        self.n = n if n else len(arr)
        self.t = [self.neutral] * (self.n * 2)
        if arr:
            for i in range(self.n):
                self.t[self.n + i] = arr[i]
            self.build()

    # the main operation of the tree
    def operation(self, l, r):
        return l * r

    def build(self):
        i = self.n - 1
        while i > 0:
            self.t[i] = self.operation(self.t[i << 1], self.t[i << 1 | 1])
            i -= 1

    # set value at position i
    def modify(self, i, value):
        i += self.n
        self.t[i] = value
        i >>= 1
        while i > 0:
            self.t[i] = self.operation(self.t[i << 1], self.t[i << 1 | 1])
            i >>= 1

    # query on interval [l, r)
    def query(self, l, r):
        resl, resr = self.neutral, self.neutral
        l += self.n
        r += self.n
        while l < r:
            if l & 1:
                resl = self.operation(resl, self.t[l])
                l += 1
            if r & 1:
                r -= 1
                resr = self.operation(self.t[r], resr)
            l >>= 1
            r >>= 1
        return self.operation(resl, resr)
