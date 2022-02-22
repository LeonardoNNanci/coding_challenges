c = int(input())
for i in range(c):
    n = int(input())
    nums = list(map(int, input().split()))

    count = 0
    for before, after in zip(nums, sorted(nums, reverse=True)):
        if before == after:
            count += 1

    print(count)
