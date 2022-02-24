#include <bits/stdc++.h>
#define MINCHAR 33;
using namespace std;

bool comp(pair<char, int> a, pair<char, int> b) {
  if (a.second < b.second)
    return true;
  if (a.second > b.second)
    return false;
  if (a.first > b.first)
    return true;
  if (a.first < b.first)
    return false;
  return false;
}

int main() {
  vector<pair<char, int>> freqs(100);
  char str[1005];
  int c = 0;
  char a = MINCHAR;

  c = 0;
  while (scanf("%s", str) != EOF) {
    a = MINCHAR;
    for (int i = 0; i < 100; i++) {
      freqs[i].first = a++;
      freqs[i].second = 0;
    }

    for (int i = 0; str[i] != '\0'; i++) {
      int index = str[i] - MINCHAR;
      freqs[index].second++;
    }

    sort(freqs.begin(), freqs.end(), comp);

    if (c++ > 0)
      printf("\n");
    for (auto p : freqs) {
      if (p.second != 0)
        printf("%d %d\n", p.first, p.second);
    }
  }

  return 0;
}