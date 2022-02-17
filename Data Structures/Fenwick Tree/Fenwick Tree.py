class FenwickTree:
    neutral = 0  # define according to the problem

    def __init__(self, N):
        self.ft = [self.neutral] * (N + 1)

    def LSOne(self, i):
        return i & (-i)

    # define according to the problem
    def op(self, x, y):
        return x + y

    # define according to the problem
    def opInv(self, x, y):
        return x - y

    def rangeQuery(self, low, high):
        return self.opInv(
            self.rangeQueryI(high + 1),
            self.neutral if low == 0 else self.rangeQueryI(low),
        )

    def rangeQueryI(self, i):
        acc = self.neutral
        while i > 0:
            acc = self.op(acc, self.ft[i])
            i -= self.LSOne(i)
        return acc

    def update(self, i, val):
        prev = self.rangeQuery(i, i)
        i += 1
        while i < len(self.ft):
            self.ft[i] = self.opInv(self.ft[i], prev)
            self.ft[i] = self.op(self.ft[i], val)
            i += self.LSOne(i)
