#include <bits/stdc++.h>

using namespace std;

bool comp(pair<int, char> a, pair<int, char> b) {
  if (a.first != b.first)
    return a.first > b.first;
  return a.second < b.second;
}

int main(int argc, char const* argv[]) {
  int C;
  cin >> C;
  cin.ignore();
  while (C--) {
    vector<pair<int, char>> occurences(26);
    string text;
    getline(cin, text);

    for (int i = 0; i < 26; i++) {
      occurences[i].second = 'a' + i;
      occurences[i].first = 0;
    }

    for (char ch : text) {
      int code = tolower(ch) - 'a';
      if (0 <= code && code <= 26)
        occurences[code].first++;
    }

    sort(occurences.begin(), occurences.end(), comp);

    int max_occ = occurences[0].first;
    for (int i = 0; i < 26 && occurences[i].first == max_occ; i++)
      cout << occurences[i].second;
    cout << endl;
  }
  return 0;
}