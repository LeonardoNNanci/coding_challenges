#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    int command, x;
    bool isPQ = true, isST = true, isQ = true;
    priority_queue<int> pq;
    stack<int> st;
    queue<int> q;
    while (n--) {
      scanf("%d %d", &command, &x);

      if (command == 1) {
        st.push(x);
        q.push(x);
        pq.push(x);
      }

      else {
        if (isPQ && x != pq.top())
          isPQ = false;
        if (isST && x != st.top())
          isST = false;
        if (isQ && x != q.front())
          isQ = false;
        pq.pop();
        st.pop();
        q.pop();
      }
    }

    if (!isPQ && !isST && !isQ)
      printf("impossible\n");
    else if (isPQ && !isST && !isQ)
      printf("priority queue\n");
    else if (!isPQ && isST && !isQ)
      printf("stack\n");
    else if (!isPQ && !isST && isQ)
      printf("queue\n");
    else
      printf("not sure\n");

    while (!pq.empty())
      pq.pop();
    while (!st.empty())
      st.pop();
    while (!q.empty())
      q.pop();
  }

  return 0;
}