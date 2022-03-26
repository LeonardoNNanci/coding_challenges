C = int(input())
for c in range(1, C + 1):
    n, *ages = map(int, input().split())
    ages.sort()
    print(f"Case {c}: {ages[n//2]}")
