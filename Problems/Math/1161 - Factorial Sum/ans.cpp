#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const* argv[]) {
  int m, n;
  long long factorial[21];

  factorial[0] = 1;
  for (int i = 1; i < 21; i++)
    factorial[i] = factorial[i - 1] * i;

  while (cin >> m >> n) {
    cout << factorial[m] + factorial[n] << endl;
  }
  return 0;
}