#include <cstdio>

#include <vector>

#include <utility>

#include <algorithm>



int main() {

  int N;

  scanf("%d", &N);



  std::vector<std::pair<int, int>> AB(N);

  for (int i=0; i<N; ++i)

    scanf("%d %d", &AB[i].first, &AB[i].second);



  std::sort(AB.begin(), AB.end());

  printf("%d\n", AB.back().first+AB.back().second);

  

  return 0;

}
