#include <bits/stdc++.h>

using namespace std;

long long AP_sum(long long a, long long d, long long n) {
  return n * (2 * a + (d * n - 1)) / 2;
}

int main(int argc, char const* argv[]) {
  int a, b;
  cout << INT_MAX << " " << LONG_LONG_MAX << endl;
  cin >> a >> b;
  cout << AP_sum(1, 1, b) - AP_sum(1, 1, a - 1) << endl;
  return 0;
}