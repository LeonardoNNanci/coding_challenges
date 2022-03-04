class Team:
    def __init__(self, id) -> None:
        self.id = id
        self.points = 0
        self.scored = 0
        self.received = 0
        self.avg = 0

    def __lt__(self, other):
        if self.points != other.points:
            return self.points > other.points
        if self.avg != other.avg:
            return self.avg > other.avg
        if self.points != other.points:
            return self.points > other.points
        return self.id < other.id


c = 0
while True:
    n = int(input())
    if not n:
        break

    teams = [Team(i + 1) for i in range(n)]
    for _ in range(n * (n - 1) // 2):
        x, y, z, w = map(int, input().split())
        x -= 1
        z -= 1
        teams[x].scored += y
        teams[z].scored += w
        teams[x].received += w
        teams[z].received += y

        if y > w:
            teams[x].points += 2
            teams[z].points += 1
        else:
            teams[z].points += 2
            teams[x].points += 1

    for team in teams:
        team.avg = team.scored if team.received == 0 else team.scored / team.received

    teams.sort()

    if c:
        print()
    c += 1
    print(f"Instancia {c}")
    count = 0
    for team in teams:
        if count:
            print(" ", end="")
        count += 1
        print(team.id, end="")
    print()
