#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const* argv[]) {
  set<char> vowels({'a', 'e', 'i', 'o', 'u'});
  string text;
  cin >> text;

  int i = -1, j = text.length();
  do {
    while (++i < text.length() && vowels.find(text[i]) == vowels.end())
      ;
    while (--j >= 0 && vowels.find(text[j]) == vowels.end())
      ;

    if (i > j) {
      cout << 'S' << endl;
      return 0;
    } else if (text[i] != text[j]) {
      cout << 'N' << endl;
      return 0;
    }
  } while (true);
}