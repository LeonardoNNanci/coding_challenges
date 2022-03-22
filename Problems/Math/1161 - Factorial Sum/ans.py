factorial = [0] * 21
factorial[0] = 1
for i in range(1, 21):
    factorial[i] = factorial[i - 1] * i

while True:
    try:
        m, n = map(int, input().split())
        print(factorial[m] + factorial[n])

    except EOFError:
        break
