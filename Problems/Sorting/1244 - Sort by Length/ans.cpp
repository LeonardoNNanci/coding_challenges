#include <bits/stdc++.h>

using namespace std;

bool comp(string left, string right) {
  return left.size() > right.size();
}

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

int main(int argc, char const* argv[]) {
  vector<string> words;
  string str;
  int n;
  cin >> n;
  cin.ignore();

  while (n--) {
    getline(cin, str);
    auto words = split(str);
    stable_sort(words.begin(), words.end(), comp);
    for (int i = 0; i < words.size() - 1; i++) {
      cout << words[i] << ' ';
    }
    cout << words[words.size() - 1] << endl;
  }
  return 0;
}
