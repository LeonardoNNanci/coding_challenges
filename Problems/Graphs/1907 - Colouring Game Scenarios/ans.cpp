#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;

int R, C;  // define in main
int grid[1024][1024];
int dr[] = {-1, 0, 0, 1};
int dc[] = {0, -1, 1, 0};

void flood_fill_BFS(int r0, int c0) {
  queue<ii> q;

  int col, row, r, c;
  q.push(make_pair(r0, c0));

  while (!q.empty()) {
    row = q.front().first;
    col = q.front().second;
    q.pop();

    if (row < 0 || row >= R || col < 0 || col >= C || grid[row][col] == 1)
      continue;

    grid[row][col] = 1;
    for (int i = 0; i < 4; i++) {
      r = row + dr[i];
      c = col + dc[i];
      q.push(make_pair(r, c));
    }
  }
}

int main(int argc, char const* argv[]) {
  cin >> R >> C;
  char cell;
  for (int i = 0; i < R; i++)
    for (int j = 0; j < C; j++) {
      cin >> cell;
      grid[i][j] = (cell == 'o');
    }

  int colors = 0;
  for (int i = 0; i < R; i++)
    for (int j = 0; j < C; j++)
      if (grid[i][j] == 0) {
        colors++;
        flood_fill_BFS(i, j);
      }

  cout << colors << endl;

  return 0;
}