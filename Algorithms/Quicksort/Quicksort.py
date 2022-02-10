def quicksort(arr, n):
    if n <= 1:
        return

    left, right, pivot = 0, n - 1, arr[n // 2]
    while left <= right:
        while arr[left] < pivot:
            left += 1
        while arr[right] > pivot:
            right -= 1

        arr[left], arr[right] = arr[right], arr[left]
        left += 1
        right -= 1

    quicksort(arr[: right + 1], right + 1)
    quicksort(arr[left:], n - left)
