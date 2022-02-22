#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n;
  while (n--) {
    cin >> m;
    vector<int> nums(m);
    for (int i = 0; i < m; i++)
      cin >> nums[i];

    vector<int> cpy(nums);
    sort(nums.begin(), nums.end(), greater<int>());

    int count = 0;
    for (int j = 0; j < m; j++)
      if (nums[j] == cpy[j])
        count++;

    cout << count << endl;
  }
}