#include <bits/stdc++.h>

using namespace std;

int m, n;

bool comp(int a, int b) {
  int aModM = a % m, bModM = b % m;
  if (aModM < bModM)
    return true;
  if (aModM > bModM)
    return false;
  int aMod2 = abs(a % 2), bMod2 = abs(b % 2);
  if (aMod2 > bMod2)
    return true;
  if (aMod2 < bMod2)
    return false;
  if (aMod2 != 0) {
    if (a > b)
      return true;
    if (a < b)
      return false;
  }
  if (aMod2 == 0) {
    if (a < b)
      return true;
    if (a > b)
      return false;
  }
  return false;
}

int main() {
  cin >> n >> m;
  while (m != 0 && n != 0) {
    vector<int> data(n);

    for (int i = 0; i < n; i++) {
      cin >> data[i];
    }

    sort(data.begin(), data.end(), comp);

    cout << n << ' ' << m << endl;
    for (int x : data) {
      cout << x << endl;
    }

    cin >> n >> m;
  }
  printf("0 0\n");

  return 0;
}