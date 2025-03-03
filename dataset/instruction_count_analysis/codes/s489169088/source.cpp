#include <deque>

#include <iostream>

using namespace std;



int main() {

  int A[1000010];

  int n, L;

  cin >> n >> L;

  for (int i = 0; i < n; ++i)

    cin >> A[i];

  deque<int> q;

  int f = 0, b = 0;

  for (; f < L - 1; ++f) {

    while (!q.empty() and A[f] < q.back())

      q.pop_back();

    q.push_back(A[f]);

  }

  for (; f < n; ++f, ++b) {

    while (!q.empty() and A[f] < q.back())

      q.pop_back();

    q.push_back(A[f]);

    if (b)

      cout << " ";

    cout << q.front();

    if (A[b] == q.front())

      q.pop_front();

  }

  cout << endl;

}
