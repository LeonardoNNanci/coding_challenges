def counting_sort(arr, min, max, n):
    r = max - min + 1
    count = [0 for i in range(r)]

    for i in range(n):
        index = arr[i] - min
        count[index] += 1

    acc = 0
    for i, c in enumerate(count):
        for _ in range(c):
            arr[acc] = min + i
            acc += 1
