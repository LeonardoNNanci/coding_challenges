#include <bits/stdc++.h>

using namespace std;

int GCD(int a, int b) {
  return b == 0 ? a : GCD(b, a % b);
}

int main(int argc, char const* argv[]) {
  int n;
  cin >> n;

  while (n--) {
    char op;
    int n1, d1, n2, d2, nr, dr, div;

    scanf("%d / %d %c %d / %d", &n1, &d1, &op, &n2, &d2);

    switch (op) {
      case '+':
        nr = n1 * d2 + n2 * d1;
        dr = d1 * d2;
        break;

      case '-':
        nr = n1 * d2 - n2 * d1;
        dr = d1 * d2;
        break;

      case '*':
        nr = n1 * n2;
        dr = d1 * d2;
        break;

      case '/':
        nr = n1 * d2;
        dr = n2 * d1;
        break;
    }

    div = mdc(nr, dr);

    printf("%d/%d = %d/%d\n", nr, dr, nr / div, dr / div);
  }
  return 0;
}
