def counting_sort(arr, min, max, n):
    count = [0 for _ in range(max - min + 1)]

    for i in range(n):
        index = arr[i] - min
        count[index] += 1

    acc = 0
    for i, c in enumerate(count):
        for _ in range(c):
            arr[acc] = min + i
            acc += 1
