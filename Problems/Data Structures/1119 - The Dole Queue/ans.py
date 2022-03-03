class node:
    def __init__(self, val, prev=None, next=None) -> None:
        self.val = val
        if not prev:
            self.prev = self
        else:
            self.prev = prev
        if not next:
            self.next = self
        else:
            self.next = next


class circular_doubly_linked_list:
    def __init__(self, n) -> None:
        self.n = n
        self.front = node(1)
        self.back = self.front
        prev = self.front

        for i in range(2, n + 1):
            new_node = node(i, prev, self.back)
            prev.next = new_node
            prev = new_node

        self.back = prev
        self.front.prev = self.back

    def erase(self, i: node):
        i.prev.next = i.next
        i.next.prev = i.prev
        self.n -= 1

    def empty(self) -> bool:
        return self.n == 0


while True:
    n, k, m = map(int, input().split())

    if not (n or k or m):
        break

    circle = circular_doubly_linked_list(n)

    cw, cc = circle.back, circle.front
    while not circle.empty():

        for _ in range(k):
            cw = cw.next
        for _ in range(m):
            cc = cc.prev

        prev_cw, next_cc = cw.prev, cc.next
        if cw == next_cc:
            next_cc = next_cc.next
        if cc == prev_cw:
            prev_cw = prev_cw.prev

        print(f"{cw.val:3d}", end="")
        circle.erase(cw)
        if cw != cc:
            print(f"{cc.val:3d}", end="")
            circle.erase(cc)

        cw, cc = prev_cw, next_cc

        if not circle.empty():
            print(",", end="")

    print()
