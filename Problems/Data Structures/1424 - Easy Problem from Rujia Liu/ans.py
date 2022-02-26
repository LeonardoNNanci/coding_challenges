from collections import defaultdict

while True:
    try:
        hash = defaultdict(list)
        n, m = map(int, input().split())
        nums = list(map(int, input().split()))
        for i, num in enumerate(nums, start=1):
            hash[num].append(i)
        for _ in range(m):
            k, v = map(int, input().split())
            positions = hash[v]
            if k <= len(positions):
                print(positions[k - 1])
            else:
                print(0)

    except EOFError:
        break
