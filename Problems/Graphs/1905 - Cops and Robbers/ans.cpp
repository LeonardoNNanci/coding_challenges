#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int R, C;
int grid[5][5];
int dc[] = {0, -1, 1, 0};
int dr[] = {-1, 0, 0, 1};

bool flood_fill_BFS(int r0, int c0) {
  if (grid[r0][c0] == 1)
    return false;
  queue<ii> q;

  int col, row, r, c;
  q.push(make_pair(r0, c0));

  while (!q.empty()) {
    row = q.front().first;
    col = q.front().second;
    q.pop();

    if (row < 0 || row >= R || col < 0 || col >= C || grid[row][col] == 1)
      continue;

    if (col == 4 && row == 4)
      return true;

    grid[row][col] = 1;
    for (int i = 0; i < 4; i++) {
      r = row + dr[i];
      c = col + dc[i];
      q.push(make_pair(r, c));
    }
  }

  return false;
}

int main(int argc, char const* argv[]) {
  int T;
  cin >> T;
  R = C = 5;
  while (T--) {
    for (int i = 0; i < 5; i++)
      for (int j = 0; j < 5; j++)
        cin >> grid[i][j];

    flood_fill_BFS(0, 0) ? cout << "COPS" : cout << "ROBBERS";
    cout << endl;
  }

  return 0;
}