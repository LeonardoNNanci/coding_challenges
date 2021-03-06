typedef pair<int, int> ii;

const int MAX_R = XXX, MAX_C = XXX;

int R, C;  // define in main
int grid[MAX_R][MAX_C];
int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};

void flood_fill_DFS(int row, int col) {
  if (row < 0 || row >= R || col < 0 || col >= C || grid[row][col] == 1)
    return;
  grid[row][col] = 1;

  for (int i = 0; i < 8; i++)
    flood_fill_DFS(row + dr[i], col + dc[i]);
}

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
    for (int i = 0; i < 8; i++) {
      r = row + dr[i];
      c = col + dc[i];
      q.push(make_pair(r, c));
    }
  }
}