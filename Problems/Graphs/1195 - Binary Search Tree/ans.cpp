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

void print_pre(node* p) {
  if (!p)
    return;
  cout << ' ' << p->val;
  print_pre(p->left);
  print_pre(p->right);
}

void print_in(node* p) {
  if (!p)
    return;
  print_in(p->left);
  cout << ' ' << p->val;
  print_in(p->right);
}

void print_post(node* p) {
  if (!p)
    return;
  print_post(p->left);
  print_post(p->right);
  cout << ' ' << p->val;
}

int main(int argc, char const* argv[]) {
  int c;
  cin >> c;
  for (int i = 1; i <= c; i++) {
    int n, x;
    cin >> n;
    node* root = NULL;
    while (n--) {
      cin >> x;
      root = push(x, root);
    }

    cout << "Case " << i << ':' << endl;
    cout << "Pre.:";
    print_pre(root);
    cout << endl << "In..:";
    print_in(root);
    cout << endl << "Post:";
    print_post(root);
    cout << endl << endl;
  }

  return 0;
}
