#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const* argv[]) {
  int c;
  cin >> c;
  while (c--) {
    float total;
    cin >> total;
    cout << ceil(log2(total)) << " dias" << endl;
  }
  return 0;
}