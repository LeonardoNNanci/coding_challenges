from collections import defaultdict

dead_list = set()
death_count = defaultdict(int)

while True:
    try:
        killer, killed = input().split()
        dead_list.add(killed)
        death_count[killer] += 1
    except EOFError:
        break

print("HALL OF MURDERERS")
for killer, count in sorted(death_count.items()):
    if killer not in dead_list:
        print(f"{killer} {count}")
