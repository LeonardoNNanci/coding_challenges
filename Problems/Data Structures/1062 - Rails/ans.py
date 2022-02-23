from collections import deque

n = int(input())
while n:
    coaches = list(map(int, input().split()))
    while coaches[0]:
        A, B, station = deque(range(1, n + 1)), deque(coaches), deque()

        possible = True

        while A or station:
            if A and A[0] == B[0]:
                A.popleft()
                B.popleft()
            elif station and station[-1] == B[0]:
                station.pop()
                B.popleft()
            elif A:
                station.append(A.popleft())

            if not A and station and station[-1] != B[0]:
                possible = False
                break

        if possible:
            print("Yes")
        else:
            print("No")

        coaches = list(map(int, input().split()))

    print()
    n = int(input())
