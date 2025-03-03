#include "stdc++.h"

using namespace std;

//NOT TO SUBMIT IN WRONG PLACE OR BY WRONG COMPILER

//ABC 177, task a, 2020/08/30

//ms,

/*

*/



struct UnionFind{

  //各頂点の親のid。親がいないなら、子の頂点数に-1をかけた値。このvectorで木を表現。

  vector<int> r;



  //コンストラクタ

  UnionFind(int N){

    r = vector<int>(N, -1);

  }



  //入力：頂点ラベル。出力：最上位の親id。入力自身でもありうる。ついでにグラフの縮約も。

  int root(int v){

    if(r[v]<0) return v;

    else{

      r[v]=root(r[v]);

      return r[v];

    }

  }



  //入力：二つの頂点ラベル。出力：併合可否。(もともと同じ集合ならfalse)。

  //入力の頂点についてはグラフの縮約をする。さらにそれぞれの頂点の集合を併合する。

  bool unite(int x, int y){

    x=root(x);

    y=root(y);

    //すでに同所属

    if(x==y) return false;



    //異所属の場合、併合。小さい方を大きい方に入れる(これは大事)

    if(abs(r[x]) < abs(r[y]) ) swap(x, y);

    r[x] += r[y];

    r[y] = x;

    return true;

  }



  int size(int x){

    return -r[root(x)];

  }

};



int main(void){

  int N, M;

  int ans=1;



  cin >>N >>M;

  UnionFind friends(N);

  for(int i=0;i<M;i++){

    int a, b;

    cin >>a >>b;

    friends.unite(a-1, b-1);

  }



  for(int i=0;i<N;i++){

    ans = max(ans, friends.size(i));

  }



  cout <<ans<<endl;

  return 0;

}

/*

幅優先探索だけじゃなくて、ユニオンファインド木もやるよー。

ユニオンファインド木はグループわけを表現できます。

所属判定も当然できます。超高速で、logNよりさらに速いです(適切な実装のもと)。

グループの大きさも返せます。

*/
