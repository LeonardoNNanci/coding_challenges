#include <bits/stdc++.h>

using namespace std;

int main() {
  int c;
  scanf("%d", &c);
  while (c--) {
    char text[1000];
    scanf("\n%[^\n]s", text);

    int i = 0;
    while (text[i] != '\0') {
      if (text[i] >= 'a' && text[i] <= 'z' || text[i] <= 'Z' && text[i] >= 'A')
        text[i] += 3;
      i++;
    }

    for (int j = 0; j < (i + 1) / 2; j++) {
      swap(text[j], text[i - 1 - j]);
      text[i - 1 - j] -= 1;
    }

    printf("%s\n", text);
  }

  return 0;
}