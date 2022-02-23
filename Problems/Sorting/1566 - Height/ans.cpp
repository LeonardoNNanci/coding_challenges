#include <bits/stdc++.h>

using namespace std;

int main() {
  int NC, cs[240];
  scanf("%d", &NC);

  while (NC--) {
    int n, h, count = 0;
    scanf("%d", &n);
    memset(cs, 0, sizeof(cs));

    for (int i = 0; i < n; i++) {
      scanf("%d", &h);
      cs[h] += 1;
    }

    int i;
    for (i = 0; i <= 230; i++)
      for (int j = 0; j < cs[i]; j++) {
        if (count > 0)
          printf(" %d", i);
        else {
          printf("%d", i);
          count++;
        }
      }
    printf("\n");
  }

  return 0;
}