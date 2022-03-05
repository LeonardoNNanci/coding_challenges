#include <bits/stdc++.h>

using namespace std;

set<string> permutations;

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  string a;

  cin >> n;
  while (n--) {
    cin >> a;
    sort(a.begin(), a.end());

    cout << a << endl;
    while (next_permutation(a.begin(), a.end()))
      cout << a << endl;
    cout << endl;
  }
  return 0;
}