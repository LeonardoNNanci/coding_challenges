from collections import deque

n = int(input())

while n:
    deck = deque(range(1, n + 1))

    discarded = []

    for _ in range(n - 1):
        discarded.append(deck.popleft())
        deck.append(deck.popleft())

    print("Discarded cards:", str(discarded)[1:-1])
    print(f"Remaining card: {deck.popleft()}")

    n = int(input())
