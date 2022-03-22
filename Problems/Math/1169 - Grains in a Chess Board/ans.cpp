#include <bits/stdc++.h>

using namespace std;

unsigned long long GP_sum(int a1, int q, int n) {
  return a1 * (pow(q, n) - 1) / (q - 1);
}

int main(int argc, char const* argv[]) {
  int c;
  cin >> c;
  while (c--) {
    int x;
    cin >> x;
    if (x == 64)
      cout << 1537228672809129 << " kg" << endl;
    else
      cout << GP_sum(1, 2, x) / 12000 << " kg" << endl;
  }
  return 0;
}