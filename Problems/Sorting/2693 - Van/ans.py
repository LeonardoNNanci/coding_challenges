while True:
    try:
        n = int(input())
        people = [()] * n

        for i in range(n):
            name, region, dist = input().split()
            people[i] = (int(dist), region, name)

        people.sort()
        for _, _, name in people:
            print(name)

    except EOFError:
        break
