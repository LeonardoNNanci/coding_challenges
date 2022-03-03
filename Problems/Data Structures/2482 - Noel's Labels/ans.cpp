#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const* argv[]) {
  int n, m;
  string label, language, name;
  map<string, string> labels;

  cin >> n;
  while (n--) {
    cin >> language;
    cin.ignore();
    getline(cin, label);
    labels[language] = label;
  }

  cin >> m;
  while (m--) {
    cin.ignore();
    getline(cin, name);
    cin >> language;
    cout << name << endl << labels[language] << endl << endl;
  }

  return 0;
}
