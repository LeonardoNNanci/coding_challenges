#include <bits/stdc++.h>

using namespace std;

int inversions;

template <class T>
void merge(T arr[], int low, int mid, int high) {
  T aux[high - low + 1];
  int left = low, right = mid + 1;
  int i = 0;

  while (left <= mid && right <= high) {
    if (arr[left] <= arr[right])
      aux[i++] = arr[left++];
    if (arr[left] >= arr[right]) {
      aux[i++] = arr[right++];
      inversions += mid - left + 1;
    }
  }

  while (left <= mid)
    aux[i++] = arr[left++];
  while (right <= high)
    aux[i++] = arr[right++];

  for (int j = 0; j < i; j++)
    arr[low + j] = aux[j];
}

template <class T>
void merge_sort(T arr[], int low, int high) {
  if (high <= low)
    return;

  int mid = (high + low) / 2;
  merge_sort<T>(arr, low, mid);
  merge_sort<T>(arr, mid + 1, high);

  merge<T>(arr, low, mid, high);
}

int main() {
  int c, n;
  scanf("%d", &c);
  while (c--) {
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
      scanf("%d", &arr[i]);
    inversions = 0;
    merge_sort<int>(arr, 0, n - 1);
    printf("Optimal train swapping takes %d swaps.\n", inversions);
  }
  return 0;
}