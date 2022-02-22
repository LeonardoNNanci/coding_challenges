# Binary Search for 1st ocurrence
def binary_search_1st(x, arr):
    low, high = 0, len(arr) - 1
    while low <= high:
        mid = (high + low) // 2
        if arr[mid] > x:
            high = mid - 1
        elif arr[mid] < x:
            low = mid + 1
        elif low != mid:
            high = mid
        else:
            return mid
    return -1


n, q = map(int, input().split())
c = 1
while n or q:
    marbles = [0 for _ in range(n)]
    for i in range(n):
        marbles[i] = int(input())
    marbles.sort()

    print(f"CASE# {c}:")
    for _ in range(q):
        s = int(input())
        index = binary_search_1st(s, marbles)
        if index >= 0:
            print(f"{s} found at {index+1}")
        else:
            print(f"{s} not found")

    n, q = map(int, input().split())
    c += 1
