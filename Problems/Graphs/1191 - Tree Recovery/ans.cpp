#include <bits/stdc++.h>

using namespace std;

int root;
string preorder, inorder;

void build(int low, int high) {
  root++;
  int i;
  for (i = low; inorder[i] != preorder[root]; i++)
    ;
  if (low < i)
    build(low, i - 1);
  if (i < high)
    build(i + 1, high);
  cout << inorder[i];
}

int main(int argc, char const* argv[]) {
  while (cin >> preorder >> inorder) {
    root = -1;
    build(0, preorder.size() - 1);
    cout << endl;
  }
  return 0;
}