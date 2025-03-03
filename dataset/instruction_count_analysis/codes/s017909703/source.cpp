#include <cassert>

#include <cstdio>

#include <deque>

#include <utility> //pair

using namespace std;



int main() {

  int N, L;

  scanf("%d %d", &N, &L);

  struct item {

    int val, idx;

  };

  deque<item> q;



  for (int i = 0, next; i < N; ++i) {

    scanf("%d", &next);

    while (!q.empty() && q.back().val > next)

      q.pop_back();

    q.emplace_back(item{next, i});

    if (q.front().idx <= i - L)

      q.pop_front();

    assert(q.front().idx > i - L);

    if (i >= L)

      printf(" ");

    if (i >= L - 1)

      printf("%d", q.front());

  }

  printf("\n");

}


