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


def print_pre(p):
    if not p:
        return
    print(f" {p.val}", end="")
    print_pre(p.left)
    print_pre(p.right)


def print_in(p):
    if not p:
        return
    print_in(p.left)
    print(f" {p.val}", end="")
    print_in(p.right)


def print_post(p):
    if not p:
        return
    print_post(p.left)
    print_post(p.right)
    print(f" {p.val}", end="")


c = int(input())
for i in range(1, c + 1):
    n = int(input())
    root = None
    for val in list(map(int, input().split())):
        root = push(val, root)
    print(f"Case {i}:")
    print("Pre.:", end="")
    print_pre(root)
    print("\nIn..:", end="")
    print_in(root)
    print("\nPost:", end="")
    print_post(root)
    print("\n")
