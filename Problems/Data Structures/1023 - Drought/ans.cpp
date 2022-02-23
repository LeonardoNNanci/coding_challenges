#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const* argv[]) {
  int n, residents, consumption, avg, c = 0;
  float total_residents = 0, total_consumption = 0;
  map<int, int> hashmap;

  cin >> n;
  while (n) {
    if (c)
      cout << endl;

    total_consumption = 0;
    total_residents = 0;

    for (int i = 0; i < n; i++) {
      cin >> residents >> consumption;
      total_residents += residents;
      total_consumption += consumption;
      avg = consumption / residents;
      hashmap[avg] += residents;
    }

    cout << "Cidade# " << ++c << ':' << endl;
    int count = 0;
    for (auto data : hashmap) {
      if (count++) {
        cout << ' ';
      }
      cout << data.second << '-' << data.first;
    }

    cout.setf(ios::fixed);
    cout << endl
         << "Consumo medio: " << setprecision(2)
         << total_consumption / total_residents - 0.004999999999999 << " m3."
         << endl;

    hashmap.clear();
    cin >> n;
  }

  return 0;
}