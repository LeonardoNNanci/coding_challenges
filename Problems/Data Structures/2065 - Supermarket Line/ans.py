from heapq import *

cashiers = []
n, m = map(int, input().split())

times = list(map(int, input().split()))
for id, v in enumerate(times):
    heappush(cashiers, (0, id, v))

times = list(map(int, input().split()))
for c in times:
    timestamp, id, v = heappop(cashiers)
    timestamp += c * v
    heappush(cashiers, (timestamp, id, v))

while cashiers:
    timestamp, id, v = heappop(cashiers)

print(timestamp)
