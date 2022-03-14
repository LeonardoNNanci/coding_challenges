#include <bits/stdc++.h>

using namespace std;

class node {
 public:
  int val;
  node *left = NULL, *right = NULL;

  node(int val) { this->val = val; }
};

node* push(int val, node* p) {
  if (!p)
    p = new node(val);
  else if (val < p->val)
    p->left = push(val, p->left);
  else if (val > p->val)
    p->right = push(val, p->right);
  return p;
}

int main(int argc, char const* argv[]) {
  int c;
  cin >> c;
  for (int i = 1; i <= c; i++) {
    int n, x;
    node* root = NULL;
    cin >> n;
    while (n--) {
      cin >> x;
      root = push(x, root);
    }

    cout << "Case " << i << ':' << endl;
    int count = 0;
    queue<node*> q;
    q.push(root);
    while (!q.empty()) {
      node* curr = q.front();
      if (curr->left)
        q.push(curr->left);
      if (curr->right)
        q.push(curr->right);
      if (count++)
        cout << ' ';
      cout << curr->val;
      q.pop();
    }
    cout << endl << endl;
  }

  return 0;
}