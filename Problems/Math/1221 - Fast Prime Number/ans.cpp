#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const* argv[]) {
  int c;
  cin >> c;
  while (c--) {
    long long x;
    cin >> x;

    if (x < 2)
      cout << "Not Prime" << endl;

    else if (x == 2)
      cout << "Prime" << endl;

    else {
      bool prime = true;
      long long bound = sqrt(x);
      for (long long i = 3; prime && i <= bound; i += 2)
        prime = (x % i != 0);
      prime ? cout << "Prime" : cout << "Not Prime";
      cout << endl;
    }
  }
  return 0;
}