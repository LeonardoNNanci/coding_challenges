#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const* argv[]) {
  int res[101] = {};
  for (int i = 1; i <= 100; i++)
    res[i] = res[i - 1] + pow(i, 2);

  while (true) {
    int n;
    cin >> n;
    if (!n)
      break;

    cout << res[n] << endl;
  }
  return 0;
}