import io
import os

from sys import stdout


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


def get_signal(x):
    if x > 0:
        return 1
    if x < 0:
        return -1
    return 0


input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline
while True:
    try:
        n, k = map(int, input().decode().split())

        arr = list(map(int, input().decode().split()))
        st = SegmentTree(1, arr)

        for _ in range(k):
            command, i, j = input().decode().split()
            i, j = int(i), int(j)
            if command == "C":
                st.modify(i - 1, get_signal(j))
            else:
                ans = st.query(i - 1, j)
                signal = "0"
                if ans > 0:
                    signal = "+"
                elif ans < 0:
                    signal = "-"
                stdout.write(signal)
        stdout.write("\n")

    except EOFError:
        break
