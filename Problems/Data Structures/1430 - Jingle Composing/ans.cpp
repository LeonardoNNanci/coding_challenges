#include <bits/stdc++.h>

using namespace std;

map<char, float> notes{
    {'W', 1.},       {'H', 1. / 2.},  {'Q', 1. / 4.},  {'E', 1. / 8.},
    {'S', 1. / 16.}, {'T', 1. / 32.}, {'X', 1. / 64.},
};

int main() {
  string composition;

  while (true) {
    cin >> composition;
    if (composition == "*")
      break;

    int count = 0;
    float sum = 0;
    for (char ch : composition) {
      if (ch == '/') {
        if (0.999 < sum && sum < 1.001)
          count++;
        sum = 0;

      } else {
        sum += notes[ch];
      }
    }
    cout << count << endl;
  }

  return 0;
}