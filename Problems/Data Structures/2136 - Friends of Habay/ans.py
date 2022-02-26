registered = set()
max = -1
while True:
    try:
        name, status = input().split()
        registered.add((status != "YES", name))
        if status == "YES" and len(name) > max:
            max = len(name)
            winner = name
    except ValueError:
        break

for _, name in sorted(registered):
    print(name)
print(f"\nAmigo do Habay:\n{winner}")
