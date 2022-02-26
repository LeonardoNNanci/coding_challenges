#include <bits/stdc++.h>

using namespace std;

typedef pair<int, pair<int, int>> iii;

#define ARRIVAL 1
#define EXIT 0

int main(int argc, char const* argv[]) {
  int n, k, c, s;
  while (true) {
    cin >> n >> k;
    if (!n and !n)
      break;

    stack<int> lot;
    vector<iii> times(2 * n);

    for (int i = 0; i < 2 * n; i += 2) {
      cin >> c >> s;
      times[i] = iii(c, {ARRIVAL, i});
      times[i + 1] = iii(s, {EXIT, i});
    }

    sort(times.begin(), times.end());

    bool possible = true;
    for (int i = 0; i < 2 * n; i++) {
      int time = times[i].first;
      int behav = times[i].second.first;
      int car = times[i].second.second;

      if (behav == ARRIVAL && lot.size() < k)
        lot.push(car);
      else if (behav == EXIT && lot.size() > 0 && lot.top() == car)
        lot.pop();
      else {
        cout << "Nao" << endl;
        possible = false;
        break;
      }
    }

    if (possible)
      cout << "Sim" << endl;

    while (!lot.empty())
      lot.pop();
  }
  return 0;
}