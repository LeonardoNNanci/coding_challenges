#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, int> iii;

int R, C;
int grid[8][8];
int dr[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int dc[] = {1, -1, -2, -2, -1, 1, 2, 2};

int flood_fill_BFS(int r0, int c0, int rf, int cf) {
  queue<iii> q;

  int col, row, r, c, moves;
  q.push(iii(r0, c0, 0));

  while (!q.empty()) {
    tie(row, col, moves) = q.front();
    q.pop();

    if (col == cf && row == rf)
      return moves;

    if (row < 0 || row >= R || col < 0 || col >= C || grid[row][col] == 1)
      continue;

    grid[row][col] = 1;
    for (int i = 0; i < 8; i++) {
      r = row + dr[i];
      c = col + dc[i];
      q.push(iii(r, c, moves + 1));
    }
  }

  return -1;
}

int main(int argc, char const* argv[]) {
  R = C = 8;

  int r0, rf, moves;
  char c0, cf;
  while (scanf("%c%d %c%d\n", &c0, &r0, &cf, &rf) != EOF) {
    for (int i = 0; i < R; i++)
      fill(grid[i], grid[i] + 8, 0);

    moves = flood_fill_BFS(r0 - 1, c0 - 'a', rf - 1, cf - 'a');
    cout << "To get from " << c0 << r0 << " to " << cf << rf << " takes "
         << moves << " knight moves." << endl;
  }
  return 0;
}