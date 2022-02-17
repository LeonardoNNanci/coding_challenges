class SegmentTree:
    neutral = float("inf")  # define according to the problem

    def __init__(self, base):
        self.arr = base
        self.N = len(base)
        self.st = [self.neutral] * (self.N * 4)
        self.build(1, 0, self.N - 1)

    def build(self, i, low, high):
        if low == high:
            self.st[i] = self.arr[low]
            return

        mid = (low + high) // 2
        l, r = self.left(i), self.right(i)
        self.build(l, low, mid)
        self.build(r, mid + 1, high)
        self.st[i] = self.op(self.st[l], self.st[r])

    def left(self, i):
        return i * 2

    def right(self, i):
        return i * 2 + 1

    # define according to the problem
    def op(self, left, right):
        return min(left, right)

    def range_query(self, qlow, qhigh):
        return self.__range_query(1, 0, self.N - 1, qlow, qhigh)

    def __range_query(self, i, low, high, qlow, qhigh):
        if qlow > high or qhigh < low:
            return self.neutral
        if low >= qlow and high <= qhigh:
            return self.st[i]

        mid = (low + high) // 2
        cl = self.__range_query(self.left(i), low, mid, qlow, qhigh)
        cr = self.__range_query(self.right(i), mid + 1, high, qlow, qhigh)
        return self.op(cl, cr)

    def update(self, index, val):
        self.__update(1, index, val, 0, self.N - 1)
        self.arr[index] = val

    def __update(self, i, index, val, low, high):
        if low == high:
            self.st[i] = val
            return

        l, r = self.left(i), self.right(i)
        mid = (low + high) // 2
        if index <= mid:
            self.__update(l, index, val, low, mid)
        else:
            self.__update(r, index, val, mid + 1, high)
        self.st[i] = self.op(self.st[l], self.st[r])
