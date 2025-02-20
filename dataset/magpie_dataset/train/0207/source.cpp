#include <iostream>

#include <queue>

#include <algorithm>

using namespace std;

#define INF 1e18

#define int long long

typedef pair<int,int> P;

#define MP make_pair



  int n, m, k, s, p, q;

  int zonbi[100001];

  int dis[100001];

  int costco[100001];

  priority_queue <P, vector<P>, greater<P> > pq;

  vector <int> pairs[100001];

signed main(){



  for (int i = 0; i < 100001; i++){

    dis[i] = INF;

    costco[i] = INF;

  }



  cin >> n >> m >> k >> s >> p >> q;

  for (int i = 0; i < k; i++){

    cin >> zonbi[i];

  }

  for (int i = 0; i < m; i++){

    int x, y;

    cin >> x >> y;

    pairs[x].push_back(y);

    pairs[y].push_back(x);

  }



  for (int i = 0; i < k; i++){

    pq.push(MP(0, zonbi[i]));

    dis[zonbi[i]] = 0;

  }

while(!pq.empty()){

      int cost, start;

      cost = pq.top().first;

      start = pq.top().second;

      pq.pop();

      if(s == cost) continue;

      for(int j = 0; j < pairs[start].size(); j++){

        if (dis[pairs[start][j]] > cost + 1){

          dis[pairs[start][j]] = cost + 1;

          pq.push(MP(cost + 1, pairs[start][j]));

        } 

      }

    }

  pq.push(MP(0, 1));

  costco[1] = 0;

  while(!pq.empty()){

    int cost, start;

    cost = pq.top().first;

    start = pq.top().second;

    pq.pop();

    for (int i = 0; i < pairs[start].size(); i++){

      int hoge;

      if (dis[pairs[start][i]] == 0){

        continue;

      }else if (dis[pairs[start][i]] == INF){

        hoge = p;

      }else{

        hoge = q;

      }

      if (pairs[start][i] == n){

          hoge = 0;

      }

      if (costco[pairs[start][i]] > cost + hoge){

        costco[pairs[start][i]] =  cost + hoge;

        pq.push(MP(cost + hoge, pairs[start][i]));

      }

    }

  }

  cout << costco[n] << endl;

  return 0;

}