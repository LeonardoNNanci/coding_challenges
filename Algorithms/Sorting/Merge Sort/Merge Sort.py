def merge(arr, low, mid, high):
    aux = [0] * (high - low + 1)
    left, right, i = low, mid + 1, 0

    while left <= mid and right <= high:
        if arr[left] <= arr[right]:
            aux[i] = arr[left]
            left += 1
            i += 1
        if arr[left] >= arr[right]:
            aux[i] = arr[right]
            right += 1
            i += 1

    while left <= mid:
        aux[i] = arr[left]
        left += 1
        i += 1
    while right <= high:
        aux[i] = arr[right]
        right += 1
        i += 1

    arr[low : high + 1] = aux


def merge_sort(arr, low, high):
    if low >= high:
        return

    mid = (high + low) // 2
    merge_sort(arr, low, mid)
    merge_sort(arr, mid + 1, high)

    merge(arr, low, mid, high)
