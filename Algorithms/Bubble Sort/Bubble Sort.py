def bubble_sort(arr, n):
    count = float("inf")
    for _ in range(n - 1):
        count = 0
        for j in range(n - 1):
            if arr[j] > arr[j + 1]:  # increasing or decreasing order
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                count += 1
        print(count)
        if count <= 0:
            return
