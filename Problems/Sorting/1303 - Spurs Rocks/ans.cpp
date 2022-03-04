#include <bits/stdc++.h>

using namespace std;

struct Team {
  int id = 0, points = 0, scored = 0, received = 0;
  float avg;

  bool operator<(Team other) {
    if (points != other.points)
      return points > other.points;
    if (avg != other.avg)
      return avg > other.avg;
    if (scored != other.scored)
      return scored > other.scored;
    return id < other.id;
  }
};

int main(int argc, char const* argv[]) {
  int n, instance = 0;
  while (true) {
    cin >> n;
    if (n == 0)
      break;

    vector<Team> teams(n);
    for (int i = 0; i < n; i++)
      teams[i].id = i + 1;

    int x, y, z, w;
    for (int i = 0; i < n * (n - 1) / 2; i++) {
      cin >> x >> y >> z >> w;
      x--;
      z--;
      teams[x].scored += y;
      teams[z].scored += w;
      teams[x].received += w;
      teams[z].received += y;
      if (y > w) {
        teams[x].points += 2;
        teams[z].points += 1;
      } else {
        teams[x].points += 1;
        teams[z].points += 2;
      }
    }

    for (auto& team : teams) {
      team.avg = team.received == 0 ? (float)team.scored
                                    : (float)team.scored / (float)team.received;
    }

    sort(teams.begin(), teams.end());

    if (instance)
      cout << endl;
    cout << "Instancia " << ++instance << endl;
    int count = 0;
    for (auto team : teams) {
      if (count++)
        cout << ' ';
      cout << team.id;
    }
    cout << endl;
  }

  return 0;
}
