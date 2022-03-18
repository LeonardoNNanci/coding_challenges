#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int R, C;  // define in main
char grid[50][50];
int dc[] = {0, -1, 1, 0};
int dr[] = {-1, 0, 0, 1};

void flood_fill_BFS(int r0, int c0) {
  queue<ii> q;

  int col, row, r, c;
  q.push(make_pair(r0, c0));

  while (!q.empty()) {
    row = q.front().first;
    col = q.front().second;
    q.pop();

    if (row < 0 || row >= R || col < 0 || col >= C || grid[row][col] == '!' ||
        grid[row][col] == 'X')
      continue;

    grid[row][col] = '!';
    for (int i = 0; i < 4; i++) {
      r = row + dr[i];
      c = col + dc[i];
      q.push(make_pair(r, c));
    }
  }
}

int main(int argc, char const* argv[]) {
  while (true) {
    cin >> R >> C;
    if (!(R || C))
      break;
    for (int i = 0; i < R; i++)
      for (int j = 0; j < C; j++)
        cin >> grid[i][j];

    for (int i = 0; i < R; i++)
      for (int j = 0; j < C; j++)
        if (grid[i][j] == 'T')
          flood_fill_BFS(i, j);

    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++)
        if (grid[i][j] == '!')
          cout << 'T';
        else
          cout << grid[i][j];
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}