#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const* argv[]) {
  int c;
  cin >> c;
  cin.ignore();
  while (c--) {
    string text;
    set<char> letters;

    getline(cin, text);
    for (auto ch : text) {
      char low = tolower(ch);
      if ('a' <= low && low <= 'z')
        letters.insert(low);
    }

    if (letters.size() < 13)
      cout << "frase mal elaborada" << endl;
    else if (letters.size() < 26)
      cout << "frase quase completa" << endl;
    else
      cout << "frase completa" << endl;
  }
  return 0;
}