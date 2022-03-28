#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const* argv[]) {
  long long x, y;
  string sum;
  while (true) {
    cin >> x >> y;
    if (!(x || y))
      break;
    sum = to_string(x + y);
    for (auto ch : sum)
      if (ch != '0')
        cout << ch;
    cout << endl;
  }
  return 0;
}