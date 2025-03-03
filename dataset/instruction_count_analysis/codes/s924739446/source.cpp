#include <cstdio>

#include <cstring>

#include <algorithm>

#include <vector>

#include <queue>



int main() {

  int K;

  scanf("%d", &K);



  std::queue<int> q;

  std::vector<int> v(K, 1<<29);

  v[1] = 1;



  q.emplace(1);

  while (!q.empty()) {

    int i=q.front();

    q.pop();



    int next[2]={(i*10)%K, (i+1)%K};

    for (int j=0; j<=1; ++j) {

      if (v[next[j]] > v[i]+j) {

        v[next[j]] = v[i]+j;

        q.emplace(next[j]);

      }

    }

  }



  printf("%d\n", v[0]);

  return 0;

}
