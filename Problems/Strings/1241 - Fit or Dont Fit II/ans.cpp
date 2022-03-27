#include <bits/stdc++.h>

using namespace std;

int main() {
  int c;
  cin >> c;
  while (c--) {
    string A, B;
    cin >> A >> B;
    int i;
    for (i = 1; i <= B.length() && A[A.length() - i] == B[B.length() - i]; i++)
      ;
    if (i <= B.length())
      cout << "nao encaixa" << endl;
    else
      cout << "encaixa" << endl;
  }
  return 0;
}