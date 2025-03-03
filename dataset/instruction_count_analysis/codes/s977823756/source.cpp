#include "stdc++.h"

using namespace std;

//NOT TO SUBMIT IN WRONG PLACE OR BY WRONG COMPILER

//ABC 177, task a, 2020/08/29

//ms,

/*

添え字が1-indexになってるのに気づいてなくて草。

入力時に1小さいものをとるか、最初に配列を一つ大きくとるか。

*/



int main(void){

  int N, M;

  vector<vector<int>> friends(200000);

  queue<int> next;

  vector<int> dist(200000, -1);

  int ans=1;

  int group_size;



  cin >>N >>M;



  //input

  for(int i=0;i<M;i++){

    int u, v;

    cin >>u >>v;

    friends[u-1].push_back(v-1);

    friends[v-1].push_back(u-1);

  }



  //bfs

  for(int v=0;v<N;v++){

    if(dist[v] != -1) continue;



    dist[v]=0;

    next.push(v);

    group_size=1;



    while(next.size()!=0){

      int u = next.front();

      next.pop();



      for(long unsigned int i=0;i<friends[u].size();i++){

        int w = friends[u][i];

        if(dist[w] != -1) continue;



        dist[w] = dist[u]+1;

        next.push(w);

        group_size++;

      }

    }//end while

    ans = max(ans, group_size);

  }//end for



  cout <<ans<<endl;

  return 0;

}

/*

お手上げ！！！

解法はunion find木とBFSの二通り。

BFSは連結な重みなしのグラフの最短路問題を線形時間で解けるのが特徴。

また、未探索の頂点が消えるまでやり続ければ連結成分の様子がなんでもわかる。

今回は後者の特徴を使う。

友達のネットワークのグラフの、最大の連結成分の成分個のグループがあればよい。

*/
