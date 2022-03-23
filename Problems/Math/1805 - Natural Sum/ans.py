def AP_sum(a, d, n):
    return int(n * (2 * a + (d * n - 1)) / 2)


a, b = map(int, input().split())
print(AP_sum(1, 1, b) - AP_sum(1, 1, a - 1))
