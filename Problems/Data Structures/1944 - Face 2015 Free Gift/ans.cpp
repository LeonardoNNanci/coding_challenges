#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const* argv[]) {
  int n;
  cin >> n;

  char ch;
  stack<char> panel, temp;
  queue<char> new_letters;

  panel.push('F');
  panel.push('A');
  panel.push('C');
  panel.push('E');

  int count, winners = 0;
  while (n--) {
    count = 0;
    for (int i = 0; i < 4; i++) {
      cin >> ch;
      if (ch == panel.top()) {
        temp.push(ch);
        panel.pop();
        count++;
      }
      new_letters.push(ch);
    }

    if (count == 4) {
      winners++;
      while (!temp.empty())
        temp.pop();
      while (!new_letters.empty())
        new_letters.pop();

    } else {
      while (!temp.empty()) {
        panel.push(temp.top());
        temp.pop();
      }
      while (!new_letters.empty()) {
        panel.push(new_letters.front());
        new_letters.pop();
      }
    }

    if (panel.empty()) {
      panel.push('F');
      panel.push('A');
      panel.push('C');
      panel.push('E');
    }
  }

  cout << winners << endl;

  return 0;
}
