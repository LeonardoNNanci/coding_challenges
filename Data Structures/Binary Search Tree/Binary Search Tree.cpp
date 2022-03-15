template <class T>
class node {
 public:
  T val;
  node *left = NULL, *right = NULL;

  node(T val) { this->val = val; }
};

template <class T>
class BST {
 private:
  int printed;
  node<T>* root = NULL;
  node<T>* push(T val, node<T>* p) {
    if (!p)
      p = new node<T>(val);
    else if (val < p->val)
      p->left = push(val, p->left);
    else if (val > p->val)
      p->right = push(val, p->right);
    return p;
  }

  node<T>* search(T val, node<T>* p) {
    if (!p)
      return NULL;
    else if (val < p->val)
      return search(val, p->left);
    else if (val > p->val)
      return search(val, p->right);
    return p;
  }

  void print_val(node<T>* p) {
    if (printed > 0)
      cout << ' ';
    cout << p->val;
    printed++;
  }

  void prefix(node<T>* p) {
    if (!p)
      return;
    print_val(p);
    prefix(p->left);
    prefix(p->right);
  }

  void infix(node<T>* p) {
    if (!p)
      return;
    infix(p->left);
    print_val(p);
    infix(p->right);
  }

  void postfix(node<T>* p) {
    if (!p)
      return;
    postfix(p->left);
    postfix(p->right);
    print_val(p);
  }

 public:
  void push(T val) { root = push(val, root); }

  node<T>* search(T val) { return search(val, root); }

  void prefix() {
    printed = 0;
    prefix(root);
  }

  void infix() {
    printed = 0;
    infix(root);
  }

  void postfix() {
    printed = 0;
    postfix(root);
  }
};