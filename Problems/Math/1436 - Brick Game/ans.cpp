#include <bits/stdc++.h>

using namespace std;

int main() {
  int C;
  cin >> C;
  for (int c = 1; c <= C; c++) {
    int n;
    cin >> n;
    vector<int> ages(n);
    for (int i = 0; i < n; i++)
      cin >> ages[i];

    sort(ages.begin(), ages.end());

    cout << "Case " << c << ": " << ages[n / 2] << endl;
  }

  return 0;
}