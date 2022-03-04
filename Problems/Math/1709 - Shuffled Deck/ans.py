n = int(input())
x, count = 1, 0
while True:
    x <<= 1
    if x > n:
        x = (x - 1) % n
    count += 1

    if x == 1:
        break

print(count)
