def GP_sum(a1, q, n):
    return a1 * (q**n - 1) / (q - 1)


c = int(input())
for _ in range(c):
    x = int(input())
    print(int(GP_sum(1, 2, x) / 12000), "kg")
