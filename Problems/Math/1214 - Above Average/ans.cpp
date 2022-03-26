#include <bits/stdc++.h>

using namespace std;

int main() {
  int c;
  cin >> c;
  while (c--) {
    int n;
    cin >> n;
    int grades[n], avg = 0, count = 0;

    for (int i = 0; i < n; i++) {
      cin >> grades[i];
      avg += grades[i];
    }
    avg /= n;

    for (int i = 0; i < n; i++)
      count += (grades[i] > avg);

    cout.setf(ios::fixed);
    cout << setprecision(3) << (float)(count * 100) / (float)n << '%' << endl;
  }

  return 0;
}