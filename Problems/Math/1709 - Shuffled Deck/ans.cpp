#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, x = 1, count = 0;
  cin >> n;
  do {
    x <<= 1;
    if (x > n)
      x = (x - 1) % n;
    count++;
  } while (x != 1);

  cout << count << endl;

  return 0;
}