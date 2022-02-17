n = int(input())

while n:
    monte = [i for i in range(1, n + 1)]
    print("Discarded cards:", end="")
    if n > 1:
        for i in range(0, n - 2):
            print(" %d," % (monte.pop(0)), end="")
            monte.append(monte.pop(0))
        print(" %d" % (monte.pop(0)), end="")
        monte.append(monte.pop(0))
    print("\nRemaining card: %d" % (monte[0]))

    monte.clear()
    n = int(input())
