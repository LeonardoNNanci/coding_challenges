#include <bits/stdc++.h>

using namespace std;

int root;
string preorder, inorder, postorder;

void make_postorder(int low, int high) {
  int i = inorder.find(preorder[root++]);
  if (i > low)
    make_postorder(low, i - 1);
  if (i < high)
    make_postorder(i + 1, high);
  postorder.push_back(inorder[i]);
}

int main(int argc, char const* argv[]) {
  int C;
  cin >> C;
  while (C--) {
    int n;
    root = 0;
    postorder = "";
    cin >> n >> preorder >> inorder;
    make_postorder(0, n - 1);
    cout << postorder << endl;
  }
  return 0;
}