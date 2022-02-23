#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const* argv[]) {
  int n, temp;
  stack<int> station;
  queue<int> B, A;
  bool possible;

  scanf("%d", &n);
  while (n) {
    scanf("%d", &temp);
    while (temp) {
      B.push(temp);
      for (int j = 1; j < n; j++) {
        scanf("%d", &temp);
        B.push(temp);
      }

      for (int i = 1; i <= n; i++)
        A.push(i);

      possible = true;

      while (!A.empty() || !station.empty()) {
        if (!A.empty() && A.front() == B.front()) {  // A->B
          A.pop();
          B.pop();
        } else if (!station.empty() && station.top() == B.front()) {  // E->B
          station.pop();
          B.pop();
        } else if (!A.empty()) {  // A->E
          station.push(A.front());
          A.pop();
        }

        if (A.empty() && !station.empty() &&
            station.top() != B.front()) {  // Impossivel
          possible = false;
          printf("No\n");
          break;
        }
      }

      while (!B.empty())
        B.pop();
      while (!station.empty())
        station.pop();

      if (possible)
        printf("Yes\n");
      scanf("%d", &temp);
    }

    while (!A.empty())
      A.pop();

    printf("\n");
    scanf("%d", &n);
  }

  return 0;
}