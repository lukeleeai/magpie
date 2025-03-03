#include<iostream>

#include<vector>

#include<algorithm>

#include<cstring>

#include<cstdio>



using namespace std;

struct Info{int par, weight;};

const int MAX = 100005;



class UnionFind{

public:

  

  Info info[MAX];



  void init(int n){

    for(int i = 0; i < n; i++) info[i] = (Info){i,0};

  }

 

  Info find(int x){

    if(info[x].par == x) return info[x];

    

    Info tmp = find(info[x].par);

    info[x].weight += tmp.weight;

    info[x].par = tmp.par;

    return info[x];

  }



   void unite(int x, int y, int w){

    Info X = find(x);

    Info Y = find(y);

    //W[x]+w = W[y]

    

    info[Y.par].par = X.par;

    info[Y.par].weight += w+info[x].weight-info[y].weight;

  }

   

  bool same(int x, int y){

    return find(x).par == find(y).par;

  }



  int getValue(int x){return info[x].weight;}

};

 

int N,M;

UnionFind uf;

 

void update(){

  int a,b,c;

  scanf("%d %d %d\n",&a,&b,&c);

  uf.unite(a,b,c);

}

 

void print(){

  int a,b;

  scanf("%d %d\n",&a,&b);

  if(uf.same(a,b)) printf("%d\n",uf.getValue(b)-uf.getValue(a));

  else printf("UNKNOWN\n");

}

 

int main(){

   

 

  while(scanf("%d %d\n",&N,&M) && N+M){

    uf.init(N+1);

    for(int i = 0; i < M; i++){

      char c;

      scanf("%c",&c);

      if(c == '!') update();

      else print();

    }

  }

  return 0;

}