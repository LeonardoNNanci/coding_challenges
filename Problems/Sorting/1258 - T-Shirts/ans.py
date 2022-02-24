from sys import stdin


class shirt:
    def __init__(self, name, size, color):
        self.name = name
        self.size = size
        self.color = color

    def __lt__(self, other):
        if self.color < other.color:
            return True
        if self.color > other.color:
            return False
        if self.size > other.size:
            return True
        if self.size < other.size:
            return False
        if self.name < other.name:
            return True
        return False


count = 0
while True:
    n = int(stdin.readline())
    if n == 0:
        break
    if count > 0:
        print()
    count += 1

    shirts = [shirt("", "", "")] * n

    for i in range(n):
        name = stdin.readline().strip()
        color, size = stdin.readline().split()
        shirts[i] = shirt(name, size, color)

    shirts.sort()

    for s in shirts:
        print(s.color, s.size, s.name)
