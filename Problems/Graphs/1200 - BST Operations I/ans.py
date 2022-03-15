class node:
    def __init__(self, val) -> None:
        self.val = val
        self.left = None
        self.right = None


class BST:
    def __init__(self) -> None:
        self.root = None

    def __print_val(self, p):
        if self.printed > 0:
            print(" ", end="")
        print(p.val, end="")
        self.printed += 1

    def __push(self, val, p):
        if not p:
            p = node(val)
        elif val < p.val:
            p.left = self.__push(val, p.left)
        elif val > p.val:
            p.right = self.__push(val, p.right)
        return p

    def __search(self, val, p):
        if not p:
            return None
        elif val < p.val:
            return self.__search(val, p.left)
        elif val > p.val:
            return self.__search(val, p.right)
        return p

    def __pre(self, p):
        if not p:
            return
        self.__print_val(p)
        self.__pre(p.left)
        self.__pre(p.right)

    def __in(self, p):
        if not p:
            return
        self.__in(p.left)
        self.__print_val(p)
        self.__in(p.right)

    def __post(self, p):
        if not p:
            return
        self.__post(p.left)
        self.__post(p.right)
        self.__print_val(p)

    def postfix(self):
        self.printed = 0
        self.__post(self.root)

    def infix(self):
        self.printed = 0
        self.__in(self.root)

    def prefix(self):
        self.printed = 0
        self.__pre(self.root)

    def push(self, val):
        self.root = self.__push(val, self.root)

    def search(self, val):
        return self.__search(val, self.root)


tree = BST()
while True:
    try:
        data = input().split()
        if len(data) > 1:
            command, val = data
            if command == "I":
                tree.push(val)
            elif command == "P":
                print(val, end="")
                if not tree.search(val):
                    print(" nao", end="")
                print(" existe")
        else:
            if data[0] == "PREFIXA":
                tree.prefix()
                print()
            elif data[0] == "INFIXA":
                tree.infix()
                print()
            else:
                tree.postfix()
                print()

    except EOFError:
        break
