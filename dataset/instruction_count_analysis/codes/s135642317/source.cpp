#include"stdc++.h"

using namespace std;

const int INF = 1 << 30;

#define for_each(it,a) for(__typeof a.begin() it = a.begin();it!=a.end();it++)

template<class T> inline void chmin(T& a, T b) { if( b < a ) a = b; }



int n, m;

struct edge{

  int pos, dang;

  vector < int >  value;

  edge( int pos, int dang): pos(pos), dang(dang), value( (n + 1) / 2 + 1, INF){};

};

int main(){



  while( cin >> n >> m , n){

    vector< vector < edge > > info(n);



    for(int i = 0; i < n; i++){

      int k;

      cin >> k;

      for(int j = 0; j < k; j++){

        int t, d;

        cin >> t >> d;

        info[i].push_back( edge( t, d));

      }

    }

    for_each( it, info[0]) it -> value[m] = 0;

    for_each( it, info[1]) it -> value[m - 1] = 0;

    int ret = INF;

    for( int i = 0; i < n; i++){

      for_each( now, info[i]){

        for(int j = m; j >= 0; j--){ //ジャンプできる残り回数

          int& cost = now -> value[j], dang = now -> dang, pos = now -> pos;

          if( cost == INF) continue;

          if(j > 0){ //ジャンプしてみる

            if(i + 2 >= n) chmin( ret, cost);

            else for_each( next, info[i + 2])

                   chmin( next -> value[j - 1], cost + (dang + next -> dang) * abs( pos - next -> pos));

          }

          if(i + 1 >= n) chmin( ret, cost);

          else for_each( next, info[i + 1])

                 chmin( next -> value[j], cost + (dang + next -> dang) * abs( pos - next -> pos));

        }

      }

    }

    cout << ret << endl;

  }

}