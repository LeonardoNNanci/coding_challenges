#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const* argv[]) {
  int n, x;
  cin >> n;

  vector<int> even, odd;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (x % 2 == 0)
      even.push_back(x);
    else
      odd.push_back(x);
  }

  sort(even.begin(), even.end());
  sort(odd.begin(), odd.end(), greater<int>());

  for (int i : even)
    cout << i << endl;
  for (int i : odd)
    cout << i << endl;

  return 0;
}