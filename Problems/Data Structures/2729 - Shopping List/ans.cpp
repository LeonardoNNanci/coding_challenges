#include <bits/stdc++.h>

using namespace std;

typedef pair<bool, string> p;

vector<string> split(string str, char sep = ' ') {
  vector<string> tokens;
  unsigned int start = 0, end = 0;
  while ((end = str.find(sep, start)) != string::npos) {
    tokens.push_back(str.substr(start, end - start));
    start = end + 1;
  }
  tokens.push_back(str.substr(start));
  return tokens;
}

int main() {
  int n;
  cin >> n;
  cin.ignore();
  while (n--) {
    string str;
    set<string> s;
    getline(cin, str);
    auto words = split(str);

    for (auto word : words)
      s.insert(word);

    int i = 0;
    for (auto word : s) {
      if (i > 0)
        cout << ' ';
      cout << word;
      i++;
    }
    cout << endl;
  }
}