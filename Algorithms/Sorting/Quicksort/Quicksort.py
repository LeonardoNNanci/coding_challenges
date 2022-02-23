def quicksort(arr, low, high):
    if low >= high:
        return

    left, right, pivot = low, high, arr[(low + high) // 2]
    while left <= right:
        while arr[left] < pivot:
            left += 1
        while arr[right] > pivot:
            right -= 1

        if left <= right:
            arr[left], arr[right] = arr[right], arr[left]
            left += 1
            right -= 1

    quicksort(arr, low, right)
    quicksort(arr, left, high)
