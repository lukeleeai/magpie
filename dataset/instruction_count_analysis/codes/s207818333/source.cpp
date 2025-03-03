#include<iostream>

#include<vector>

#include<algorithm>

#include<cstring>

 

using namespace std;

typedef long long ll;

struct Info{int par, weight;};

const int MAX = 100005;

const int INF = (1<<28);



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

bool used[MAX];

UnionFind uf;

 

void init(){

  memset(used,false,sizeof(used));

  uf.init(N+1);

}

 

 

void update(){

   

  int a,b,c;

  cin >> a >> b >> c;

  uf.unite(a,b,c);

}

 

void print(){

  int a,b;

  cin >> a >> b;

  if(uf.same(a,b)) cout << uf.getValue(b)-uf.getValue(a) << endl;

  else cout << "UNKNOWN" << endl;

}

 

int main(){

   

  while(cin >> N >> M && N+M){

    init();

    for(int i = 0; i < M; i++){

      char c;

      cin >> c;

      if(c == '!') update();

      else print();

    }

  }

  return 0;

}