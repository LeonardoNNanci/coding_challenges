#include <bits/stdc++.h>
using namespace std;

int binary_search_1st(int x, int* arr, int len) {
  int low = 0, high = len - 1, mid;
  while (low <= high) {
    mid = (high + low) / 2;
    if (arr[mid] > x)
      high = mid - 1;
    else if (arr[mid] < x)
      low = mid + 1;
    else if (low != mid)
      high = mid;
    else
      return mid;
  }
  return -1;
}

template <class T>
void quicksort(T arr[], int low, int high) {
  if (low >= high)
    return;

  int left = low, right = high, pivot = arr[(high + low) / 2];
  while (left <= right) {
    while (arr[left] < pivot)
      left++;
    while (arr[right] > pivot)
      right--;

    if (left <= right) {
      int temp = arr[left];
      arr[left++] = arr[right];
      arr[right--] = temp;
    }
  }
  quicksort<T>(arr, low, right);
  quicksort<T>(arr, left, high);
}

int main(int argc, char const* argv[]) {
  int n, q, s, c = 1;

  scanf("%d %d", &n, &q);
  while (n || q) {
    int marbles[n];

    for (int i = 0; i < n; i++) {
      scanf("%d", &marbles[i]);
    }
    quicksort<int>(marbles, 0, n - 1);

    printf("CASE# %d:\n", c++);
    for (int i = 0; i < q; i++) {
      scanf("%d", &s);
      int index = binary_search_1st(s, marbles, n);
      if (index >= 0)
        printf("%d found at %d\n", s, index + 1);
      else
        printf("%d not found\n", s);
    }

    scanf("%d %d", &n, &q);
  }

  return 0;
}