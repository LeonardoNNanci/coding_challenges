#include <bits/stdc++.h>

using namespace std;

char lower(char c) {
  char ans = tolower(c);
  return ans;
}

int main() {
  set<string> dict;
  string s;
  while (scanf("%c", &c) != EOF) {
    c = tolower(c);
    if (c >= 'a' && c <= 'z')
      s.push_back(c);

    while ((scanf("%c", &c) != EOF) && (c = lower(c)) >= 'a' && c <= 'z') {
      s.push_back(c);
    }
    if (s.size() > 0)
      dict.insert(s);
    s.clear();
  }

  for (auto word : dict)
    cout << word << '\n';

  return 0;
}