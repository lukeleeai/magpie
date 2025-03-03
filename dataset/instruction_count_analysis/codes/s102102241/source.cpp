#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <queue>

#include <set>

#include <utility>



#define MAX_N (100)

#define MAX_M (1000)



typedef struct {

  int to;

  int cost;

} edge;



using namespace std;



void dijkstra(const vector<vector<edge>> &adj_lists, int s, int *distances) {

  // start from s

  priority_queue<pair<int, int>, vector<pair<int, int>>,

                 greater<pair<int, int>>>

      que;  // (distance, prev)

  que.push(pair<int, int>(0, s));

  while (!que.empty()) {

    const pair<int, int> p = que.top();

    const int d = p.first, v = p.second;

    que.pop();

    if (distances[v] < 0) {

      distances[v] = d;

      for (int i = 0; i < adj_lists[v].size(); i++) {

        const int u = adj_lists[v][i].to, w = adj_lists[v][i].cost;

        if (distances[u] < 0) {

          que.push(pair<int, int>(d + w, u));

        }

      }

    }

  }

}



int main(int argc, char *argv[]) {

  // read inputs

  int N, M, as[MAX_M], bs[MAX_M], cs[MAX_M];

  scanf("%d %d", &N, &M);

  for (int i = 0; i < M; i++) {

    scanf("%d %d %d", &as[i], &bs[i], &cs[i]);

  }



  // create graph

  vector<vector<edge>> adj_lists;

  // add nodes

  for (int i = 0; i < N; i++) {

    adj_lists.push_back(vector<edge>());

  }

  // add edges

  for (int i = 0; i < M; i++) {

    int a = as[i] - 1, b = bs[i] - 1, c = cs[i];

    adj_lists[a].push_back({b, c});

    adj_lists[b].push_back({a, c});

  }



  // check which edges are used

  set<pair<int, int>> used_edges;

  for (int s = 0; s < N; s++) {

    // calculate distances from s

    int distances[MAX_N];

    memset(distances, -1, N * sizeof(int));

    dijkstra(adj_lists, s, distances);

    // check which edges are along the minimum path

    for (int v = 0; v < N; v++) {

      const int d_v = distances[v];

      for (int i = 0; i < adj_lists[v].size(); i++) {

        const int u = adj_lists[v][i].to, w = adj_lists[v][i].cost;

        if (distances[u] + w == d_v) {

          used_edges.insert(pair<int, int>(u, v));

          used_edges.insert(pair<int, int>(v, u));

        }

      }

    }

  }

  printf("%d\n", M - used_edges.size() / 2);



  return 0;

}
