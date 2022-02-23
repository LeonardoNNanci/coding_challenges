#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const* argv[]) {
  int n;
  cin >> n;
  while (n--) {
    int m, p;
    string item;
    float price, quant, total = 0;
    map<string, float> products;

    cin >> m;
    while (m--) {
      cin >> item >> price;
      products[item] = price;
    }

    cin >> p;
    while (p--) {
      cin >> item >> quant;
      total += products[item] * quant;
    }

    cout.setf(ios::fixed);
    cout << "R$ " << setprecision(2) << total << endl;
  }
  return 0;
}
