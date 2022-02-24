#include <bits/stdc++.h>

using namespace std;

bool isVar(char c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
         (c >= '0' && c <= '9');
}

int priority(char c) {
  if (c == '+')
    return 0;
  if (c == '-')
    return 0;
  if (c == '*')
    return 1;
  if (c == '/')
    return 1;
  return 2;
}

int main(int argc, char const* argv[]) {
  int n;
  string equation;
  stack<char> stack;

  scanf("%d", &n);
  while (n--) {
    cin >> equation;
    for (char c : equation) {
      if (isVar(c))
        printf("%c", c);

      else if (c == '(')
        stack.push(c);
      else if (c == ')') {
        // pop from stack until '('
        while (stack.top() != '(') {
          printf("%c", stack.top());
          stack.pop();
        }
        stack.pop();
      } else {
        while (!stack.empty() && stack.top() != '(' &&
               priority(c) <= priority(stack.top())) {
          // pop from stack until lower priority
          printf("%c", stack.top());
          stack.pop();
        }
        stack.push(c);
      }
    }

    // pop remaining values
    while (!stack.empty()) {
      printf("%c", stack.top());
      stack.pop();
    }

    printf("\n");
  }

  return 0;
}
