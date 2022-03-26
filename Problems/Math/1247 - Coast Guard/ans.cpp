#include <bits/stdc++.h>

using namespace std;

int main() {
  float tg, tf, d, vf, vg;
  while (cin >> d >> vf >> vg) {
    tg = sqrt(pow(d, 2) + pow(12, 2)) / vg;
    tf = 12 / vf;
    tg > tf ? cout << 'N' : cout << 'S';
    cout << endl;
  }

  return 0;
}