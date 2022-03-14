from collections import deque


class node:
    def __init__(self, val) -> None:
        self.val = val
        self.left = None
        self.right = None


def push(val, p):
    if not p:
        p = node(val)
    elif val < p.val:
        p.left = push(val, p.left)
    elif val > p.val:
        p.right = push(val, p.right)
    return p


c = int(input())
for i in range(1, c + 1):
    root = None
    n = int(input())
    nums = map(int, input().split())
    for x in nums:
        root = push(x, root)

    print(f"Case {i}:")
    count = 0
    q = deque([root])
    res = [0] * n
    while q:
        curr = q.popleft()
        if curr.left:
            q.append(curr.left)
        if curr.right:
            q.append(curr.right)
        res[count] = curr.val
        count += 1
    print(*res, end="\n\n")
