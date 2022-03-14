#include <bits/stdc++.h>

using namespace std;

pair<int, int> dir{0, 0};
pair<int, int> direction(char ch) {
  if (ch == '>')
    return make_pair(0, 1);
  if (ch == '<')
    return make_pair(0, -1);
  if (ch == 'v')
    return make_pair(1, 0);
  if (ch == '^')
    return make_pair(-1, 0);
  return dir;
}

int main(int argc, char const* argv[]) {
  int w, h;
  cin >> w >> h;
  char grid[h][w];

  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++)
      cin >> grid[i][j];

  int x = 0, y = 0;
  do {
    if (grid[x][y] == '*') {
      cout << '*' << endl;
      return 0;
    }
    dir = direction(grid[x][y]);
    grid[x][y] = '1';
    x += dir.first;
    y += dir.second;
  } while (x >= 0 && y >= 0 && x < h && y < w && grid[x][y] != '1');

  cout << '!' << endl;

  return 0;
}