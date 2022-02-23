import io, os
from collections import defaultdict

input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

n = int(input().decode())
c = 0
hashmap = defaultdict(int)

while n:
    if c:
        print("")
    c += 1

    total_residents, total_consumption = 0, 0
    for _ in range(n):
        residents, consumption = map(int, input().decode().split())
        total_residents += residents
        total_consumption += consumption
        avg = consumption // residents
        hashmap[avg] += residents

    count = 0
    print(f"Cidade# {c}:")
    for avg, res in sorted(hashmap.items()):
        if count:
            print(" ", end="")
        count += 1
        print(f"{res}-{avg}", end="")

    print(
        f"\nConsumo medio: {(total_consumption / total_residents - 0.004999999999999):.2f} m3.",
    )

    hashmap.clear()
    n = int(input().decode())
