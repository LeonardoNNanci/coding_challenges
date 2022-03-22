from math import ceil, log2


c = int(input())
for _ in range(c):
    total = float(input())
    print(ceil(log2(total)), "dias")
