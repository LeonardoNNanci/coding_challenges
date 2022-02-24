#include <bits/stdc++.h>

using namespace std;

struct shirt {
  string name, color;
  char size;

  bool operator<(shirt other) {
    if (color < other.color)
      return true;
    if (color > other.color)
      return false;
    if (size > other.size)
      return true;
    if (size < other.size)
      return false;
    if (name < other.name)
      return true;
    return false;
  }
};

int main() {
  int n;
  int count = 0;
  scanf("%d", &n);
  while (n) {
    shirt shirts[65];

    if (count++ != 0)
      printf("\n");
    cin.ignore();
    for (int i = 0; i < n; i++) {
      getline(cin, shirts[i].name);
      cin >> shirts[i].color >> shirts[i].size;
      cin.ignore();
    }

    sort(shirts, shirts + n);

    for (int i = 0; i < n; i++) {
      cout << shirts[i].color << ' ' << shirts[i].size << ' ' << shirts[i].name
           << endl;
    }

    scanf("%d", &n);
  }

  return 0;
}