res = [0] * 101
for i in range(1, 101):
    res[i] = res[i - 1] + i**2

while True:
    n = int(input())
    if not n:
        break

    print(res[n])
