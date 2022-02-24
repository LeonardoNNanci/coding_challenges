def comp(a):
    global m

    modM = a - (int(a / m) * m)
    mod2 = abs(a % 2)

    if mod2:
        return (modM, -mod2, -a)
    else:
        return (modM, -mod2, a)

global n, m
while True:
    n, m = map(int, input().split())
    print(n, m)
    if n == 0 and m == 0:
        break

    data = [int(input()) for _ in range(n)]

    data.sort(key=comp)
    for num in data:
        print(num)
        