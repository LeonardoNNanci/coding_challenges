from collections import deque


EXIT = 0
ARRIVAL = 1

while True:
    try:
        n, k = map(int, input().split())
        if n == 0 and k == 0:
            break

        lot = deque()
        times = [(0, 0, 0) for _ in range(2 * n)]

        for i in range(0, 2 * n, 2):
            a, e = map(int, input().split())
            times[i] = (a, ARRIVAL, i)
            times[i + 1] = (e, EXIT, i)

        times.sort()
        possible = True
        for time, behav, car in times:
            if behav == ARRIVAL and len(lot) < k:
                lot.append(car)
            elif behav == EXIT and len(lot) > 0 and lot[-1] == car:
                lot.pop()
            else:
                print("Nao")
                possible = False
                break

        if possible:
            print("Sim")

    except EOFError:
        break
