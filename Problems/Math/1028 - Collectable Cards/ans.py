from math import gcd


c = int(input())
for _ in range(c):
    f1, f2 = map(int, input().split())
    print(gcd(f1, f2))
