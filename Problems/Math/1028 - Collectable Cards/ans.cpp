#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const* argv[]) {
  int c;
  cin >> c;
  while (c--) {
    int f1, f2;
    cin >> f1 >> f2;
    cout << gcd<int, int>(f1, f2) << endl;
  }
  return 0;
}