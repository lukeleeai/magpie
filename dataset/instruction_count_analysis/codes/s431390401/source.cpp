#include <iostream>

#include <vector>

#include <queue>

#include <algorithm>

#include <functional>

using namespace std;



#define MAX_V 100001

const long long INF = 1LL<<60;



static int V, E, r;

static vector<pair<int, long long> > graph[MAX_V];

static long long dist[MAX_V];



int main() {

  cin >> V >> E >> r;

  for (int i = 0; i < E; ++i) {

    int s, t; long long w;

    cin >> s >> t >> w;

    graph[s].push_back(make_pair(t, w));

  }



  priority_queue<pair<long long,int>, vector<pair<long long,int> >, greater<pair<long long, int> > > que;



  for (int i = 0; i < MAX_V; ++i) dist[i] = INF;

  dist[r] = 0;

  que.push(make_pair(0, r));



  while (!que.empty()) {

    long long curDist = que.top().first;

    int curVertex = que.top().second;

    que.pop();



    if (dist[curVertex] < curDist) continue;



    for (int i = 0; i < graph[curVertex].size(); ++i) {

      int toVertex = graph[curVertex][i].first;

      long long toDist = curDist + graph[curVertex][i].second;



      if (dist[toVertex] > toDist) {

	dist[toVertex] = toDist;

	que.push(make_pair(toDist, toVertex));

      }

    }

  }



  for (int i = 0; i < V; ++i) {

    if (dist[i] < INF) cout << dist[i] << endl;

    else cout << "INF" << endl;

  }

}
