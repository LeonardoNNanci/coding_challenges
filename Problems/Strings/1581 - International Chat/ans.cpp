#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const* argv[]) {
  int c;
  cin >> c;

  while (c--) {
    string curr, prev = "";
    int n;
    bool eng = false;
    cin >> n;
    while (n--) {
      cin >> curr;
      if (!(eng || prev.empty() || curr == prev))
        eng = true;
      prev = curr;
    }

    eng ? cout << "ingles" : cout << curr;
    cout << endl;
  }

  return 0;
}