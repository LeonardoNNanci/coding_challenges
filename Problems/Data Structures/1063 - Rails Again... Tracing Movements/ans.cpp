#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const* argv[]) {
  int n;
  char temp;
  stack<char> station;
  queue<char> B, A;

  cin >> n;
  while (n) {
    for (int i = 0; i < n; i++) {
      cin >> temp;
      A.push(temp);
    }

    for (int j = 0; j < n; j++) {
      cin >> temp;
      B.push(temp);
    }

    while (!A.empty() || !station.empty()) {
      if (!A.empty() && A.front() == B.front()) {  // A->B
        cout << "IR";
        A.pop();
        B.pop();
      } else if (!station.empty() && station.top() == B.front()) {  // E->B
        cout << "R";
        station.pop();
        B.pop();
      } else if (!A.empty()) {  // A->E
        cout << "I";
        station.push(A.front());
        A.pop();
      }

      if (A.empty() && !station.empty() &&
          station.top() != B.front()) {  // Impossivel
        cout << " Impossible";
        break;
      }
    }

    while (!A.empty())
      A.pop();
    while (!B.empty())
      B.pop();
    while (!station.empty())
      station.pop();
    cout << endl;
    cin >> n;
  }

  return 0;
}