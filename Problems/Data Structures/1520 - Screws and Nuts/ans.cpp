#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const* argv[]) {
  int arr[105];
  int n, low, high, num;
  while (scanf("%d", &n) != EOF) {
    fill(arr, arr + 105, 0);
    while (n--) {
      cin >> low >> high;
      for (int i = low; i <= high; i++)
        arr[i]++;
    }

    int acc = 0;
    cin >> num;
    if (arr[num] == 0)
      cout << num << " not found" << endl;
    else {
      for (int i = 0; i < num; i++) {
        acc += arr[i];
      }
      cout << num << " found from " << acc << " to " << acc + arr[num] - 1
           << endl;
    }
  }

  return 0;
}
