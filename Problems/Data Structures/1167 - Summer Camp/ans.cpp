#include <bits/stdc++.h>

using namespace std;

typedef pair<int, string> pis;

list<pis> circle;

list<pis>::iterator circular_next(list<pis>::iterator it) {
  list<pis>::iterator n = next(it);
  if (n == circle.end()) {
    return circle.begin();
  }
  return n;
}

list<pis>::iterator circular_prev(list<pis>::iterator it) {
  list<pis>::iterator n = prev(it);
  if (n == circle.end()) {
    return --circle.end();
  }
  return n;
}

int main(int argc, char const* argv[]) {
  int n;
  while (true) {
    cin >> n;
    if (!n)
      break;

    int token;
    string name;
    while (n--) {
      cin >> name >> token;
      circle.push_back(pis(token, name));
    }

    auto child = circle.begin();
    token = child->first;

    while (circle.size() > 1) {
      auto direction = circular_prev;
      if (token % 2)
        direction = circular_next;

      while (token--) {
        child = direction(child);
      }

      auto out = child;
      token = out->first;
      child = circular_next(child);
      circle.erase(out);

      if (token % 2)
        child = circular_prev(child);
    }

    cout << "Vencedor(a): " << child->second << endl;
    circle.clear();
  }
  return 0;
}
